#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

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

int main(int argc, char const *argv[])
{
    //parse input
    ifstream input_file;
    const char * filename = argv[1];
    input_file.open(filename);
    string dna = "";
    string sub_dna = "";
    getline(input_file, dna);
    getline(input_file, sub_dna);

    //find
    
    int dna_len = get_len(dna);
    dna.erase(dna_len - 2);
    dna_len = get_len(dna) - 1;
    int sub_dna_len = get_len(sub_dna) - 1;

    //go through dna set
    //search each character find one that matches the first character of the expected motif
    //take note of position of character if matches then move to the next character

    //max amount of positions is given by dna_len ex. motif = 'A' dna = 'AAAAAAAA'
    int * positions = (int *)malloc(sizeof(int) * dna_len);
    int positions_idx = 0;
    int motif_idx = 0;
    int i;
    for(i = 0; i < dna_len; i++){
        //characters match start checking process
        if(dna[i] == sub_dna[motif_idx]){
            int j = i + 1;
            motif_idx = 1;
            for(motif_idx; motif_idx < sub_dna_len - 1; j++, motif_idx++){
                if(dna[j] != sub_dna[motif_idx]){
                    motif_idx = 0;
                    break;
                } 
            }
            //the motif and segmented dna match
            if(motif_idx != 0){
                //take note of position
                positions[positions_idx] = i + 1;
                positions_idx++;
                motif_idx = 0;
            }
        }    
    }

    int pos_iter = 0;
    for(pos_iter; pos_iter < positions_idx; pos_iter++){
        cout << positions[pos_iter] << " ";
    }
    cout << endl;


    free(positions);
    

    return 0;
}
