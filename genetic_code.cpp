#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <map>

using namespace std;

int get_len(string str){
    int i = 0;
    //get length of set name
    char ch = str[i];
    while(ch || (ch != '\n')){
        ch = str[i];
        i++;
    }
    return i;
}


int main(int argc, char const *argv[])
{
    ifstream input_file;
    const char * filename = argv[1];
    input_file.open(filename);
    //CODON TABLE (less complex way ... i wish i was smart enough to develop a binary representation)
      
    map<string, char> codon_table;
    codon_table.insert(pair<string, char>("UUU", 'F'));
    codon_table.insert(pair<string, char>("UUC", 'F'));
    codon_table.insert(pair<string, char>("UUA", 'L'));
    codon_table.insert(pair<string, char>("UUG", 'L'));
    codon_table.insert(pair<string, char>("UCU", 'S'));
    codon_table.insert(pair<string, char>("UCC", 'S'));
    codon_table.insert(pair<string, char>("UCA", 'S'));
    codon_table.insert(pair<string, char>("UCG", 'S'));
    codon_table.insert(pair<string, char>("UAU", 'Y'));
    codon_table.insert(pair<string, char>("UAC", 'Y'));
    codon_table.insert(pair<string, char>("UAA", ' '));
    codon_table.insert(pair<string, char>("UAG", ' '));
    codon_table.insert(pair<string, char>("UGU", 'C'));
    codon_table.insert(pair<string, char>("UGC", 'C'));
    codon_table.insert(pair<string, char>("UGA", ' '));
    codon_table.insert(pair<string, char>("UGG", 'W'));

    
    codon_table.insert(pair<string, char>("CUU", 'L'));
    codon_table.insert(pair<string, char>("CUC", 'L'));
    codon_table.insert(pair<string, char>("CUA", 'L'));
    codon_table.insert(pair<string, char>("CUG", 'L'));
    codon_table.insert(pair<string, char>("CCU", 'P'));
    codon_table.insert(pair<string, char>("CCC", 'P'));
    codon_table.insert(pair<string, char>("CCA", 'P'));
    codon_table.insert(pair<string, char>("CCG", 'P'));
    codon_table.insert(pair<string, char>("CAU", 'H'));
    codon_table.insert(pair<string, char>("CAC", 'H'));
    codon_table.insert(pair<string, char>("CAA", 'Q'));
    codon_table.insert(pair<string, char>("CAG", 'Q'));
    codon_table.insert(pair<string, char>("CGU", 'R'));
    codon_table.insert(pair<string, char>("CGC", 'R'));
    codon_table.insert(pair<string, char>("CGA", 'R'));
    codon_table.insert(pair<string, char>("CGG", 'R'));

    codon_table.insert(pair<string, char>("AUU", 'I'));
    codon_table.insert(pair<string, char>("AUC", 'I'));
    codon_table.insert(pair<string, char>("AUA", 'I'));
    codon_table.insert(pair<string, char>("AUG", 'M'));
    codon_table.insert(pair<string, char>("ACU", 'T'));
    codon_table.insert(pair<string, char>("ACC", 'T'));
    codon_table.insert(pair<string, char>("ACA", 'T'));
    codon_table.insert(pair<string, char>("ACG", 'T'));
    codon_table.insert(pair<string, char>("AAU", 'N'));
    codon_table.insert(pair<string, char>("AAC", 'N'));
    codon_table.insert(pair<string, char>("AAA", 'K'));
    codon_table.insert(pair<string, char>("AAG", 'K'));
    codon_table.insert(pair<string, char>("AGU", 'S'));
    codon_table.insert(pair<string, char>("AGC", 'S'));
    codon_table.insert(pair<string, char>("AGA", 'R'));
    codon_table.insert(pair<string, char>("AGG", 'R'));

    codon_table.insert(pair<string, char>("GUU", 'V'));
    codon_table.insert(pair<string, char>("GUC", 'V'));
    codon_table.insert(pair<string, char>("GUA", 'V'));
    codon_table.insert(pair<string, char>("GUG", 'V'));
    codon_table.insert(pair<string, char>("GCU", 'A'));
    codon_table.insert(pair<string, char>("GCC", 'A'));
    codon_table.insert(pair<string, char>("GCA", 'A'));
    codon_table.insert(pair<string, char>("GCG", 'A'));
    codon_table.insert(pair<string, char>("GAU", 'D'));
    codon_table.insert(pair<string, char>("GAC", 'D'));
    codon_table.insert(pair<string, char>("GAA", 'E'));
    codon_table.insert(pair<string, char>("GAG", 'E'));
    codon_table.insert(pair<string, char>("GGU", 'G'));
    codon_table.insert(pair<string, char>("GGC", 'G'));
    codon_table.insert(pair<string, char>("GGA", 'G'));
    codon_table.insert(pair<string, char>("GGG", 'G'));
    
    

    //read
    string rna_string;
    getline(input_file, rna_string);
    input_file.close(); // no longer need input file
    
    /*
    parse
    /*go through the rna_string 3 neuclic acids at a time and translate them through the codon table */
    char * result = (char *)malloc((sizeof(char) * 100) + 1);
    int result_max_size = 100;
    int result_idx = 0;
    int rna_string_len = get_len(rna_string) - 1;

    int i = 0;
    for(i; i < rna_string_len; i+=3){
        char * c_codon = (char *)calloc(1, 4);
        char c0 = rna_string[i];
        char c1 = rna_string[i+1];
        char c2 = rna_string[i+2];
        
        c_codon[0] = c0;
        c_codon[1] = c1;
        c_codon[2] = c2;
        c_codon[3] = '\0';
        
        string codon = c_codon;
        free(c_codon);

        
        map<string, char>::iterator begin_itr = codon_table.begin();
        for(begin_itr; begin_itr != codon_table.end(); begin_itr++){
            string codon_table_string = begin_itr->first;
            char codon_table_char = begin_itr->second;
            if(codon_table_string.compare(codon) == 0){
                if(result_idx + 1 >= result_max_size){
                    int prev_max = result_max_size; 
                    result_max_size = result_max_size * 2;
                    char * temp = (char *)malloc((sizeof(char) * result_max_size)+1);
                    int z;
                    for(z = 0; z < prev_max; z++){
                        temp[z] = result[z];
                    } 
                    result = temp;
                }
                if(codon_table_char == ' '){
                    break;
                }
                result[result_idx] = codon_table_char;
                result_idx++;
                
            }
        }

    }
        result[result_idx] = '\0';
        cout << result << endl;
        free(result);
   
    return 0;
}