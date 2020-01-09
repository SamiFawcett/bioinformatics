#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;

double aboslute_error = 0.001;

int get_len(string str){
    int i = 0;
    //get length of set name
    char ch = str[i];
    while(ch){
        ch = str[i];
        i++;
    }
    return i;
}

long double get_GC(string dna_string){
    int i = 0;
    long double count = 0.0;
    for(i; i < get_len(dna_string) - 1; i++){
        if(dna_string[i] == 'G' || dna_string[i] == 'C'){
            count++;
        }
    }
    return (count)/((long double)get_len(dna_string) - 1);
}

int main(int argc, char const *argv[])
{
    const char * filename = *(argv + 1);
    ifstream inFile;
    inFile.open(filename);
    
    string dna_string;
    /*
    * CREATION OF TABLE
    */
   //_____________________________
    //create dna_data table
    //above "---" are dna set names
    //below "---" are the dna sets
    //_0_|_1_|_2_|_3_
    //---|---|---|---
    //_A_|_G_|_T_|_A_
    //_T_|_C_|_T_|_G_
    //_A_|_A_|_C_|_T_
    // . | . | . | . 
    // . | . | . | . 
    // . | . | . | . 

    //constraint at most 10 dna sets
    //dna set table
    //row 0: set names row
    //row 1: dna strings row
    string table[10][2];
    string line;
    string partial_dna;
    string full_dna;
    int i = 1;
    int dna_setname_idx = -1;
    int cur_setname_len = 0;
    int tabulation_end = 0;
    while(getline(inFile, line) || tabulation_end){
        if(line[0] == '>' || tabulation_end == 1){
            if(dna_setname_idx > -1){
                table[dna_setname_idx][1] = full_dna;
                if(tabulation_end == 1) {
                    break;
                }
            }
            //reset full dna for the next set
            full_dna = "";
            //move to the next setname column
            dna_setname_idx++;

            cur_setname_len = get_len(line);

            string dna_set_name;
            i = 0;
            for(i; i < cur_setname_len - 2; i++){
                dna_set_name += line[i];
            }
            table[dna_setname_idx][0] = dna_set_name;
            
        } else if(line[0] != '>' && line[0] != '.'){
            //concatenate partial and full
            partial_dna = line;
            partial_dna.erase(get_len(partial_dna) - 2);
            full_dna.append(partial_dna);
            //reset partial
            partial_dna = "";
        } else if(line[0] == '.'){
            tabulation_end = 1;
        }
    }


    //go through table and find the max GC-content
    int rows = dna_setname_idx + 1;
    i = 0;
    int j = 0;
    long double max = 0.0;
    string id;
    for(i; i < rows; i++){
        long double gc_content = 0.0;
        //always produces a square table so we can use rows as columns
        for(j; j < rows; j++){ 
            gc_content = get_GC(table[j][1]);
            if(gc_content > max){
                max = gc_content;
                id = table[j][0];
            }
        }
    }

    cout << id << endl;
    cout << setprecision(9) << max * 100 << endl;
    
    
    inFile.close();
    return 0;
}