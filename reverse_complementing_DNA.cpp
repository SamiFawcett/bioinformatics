/*
reverse complementing DNA

A -> T
C -> G

given string s, e.g. "ACTTAG"
produce string s_rc, e.g. "CTAAGT"
*/

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;



int main(int argc, char const *argv[])
{
    
    const char * filename = *(argv + 1);
    ifstream inFile;
    inFile.open(filename);
    
    string dna_string;
    
    getline(inFile, dna_string);
    inFile.close();
    

    //get length of dna_string
    char dna_char = dna_string[0];
    int i = 1;
    while(dna_char){
        if(dna_string[i] == '\n'){
            break;
        } else {
            dna_char = dna_string[i];
            i++;
        }
        
    }

    int dna_length = i;

    //reverse complement set
    char * reverse_complement = (char *)calloc(sizeof(char), dna_length);
    int rc_iterator = 0;
    //start reading from the end of the DNA string
    int dna_iterator = dna_length - 3;
    for(dna_iterator; dna_iterator >= 0; dna_iterator--, rc_iterator++){
        char cur_reverse_dna_char = dna_string[dna_iterator];
        if(cur_reverse_dna_char == 'A'){
            *(reverse_complement + rc_iterator) = 'T';
        } else if(cur_reverse_dna_char == 'G'){
            *(reverse_complement + rc_iterator) = 'C';
        } else if(cur_reverse_dna_char == 'C') {
            *(reverse_complement + rc_iterator) = 'G';
        } else if(cur_reverse_dna_char == 'T') {
            *(reverse_complement + rc_iterator) = 'A';
        }
    }
    
    cout << reverse_complement << endl;

    free(reverse_complement);
    
    return 0;
}
 