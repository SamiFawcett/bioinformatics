/*
transcribe DNA to RNA

replace T in t, with U in u
where t is a DNA string
and u is a RNA string
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
    int i = 0;
    while(dna_char){
        dna_char = dna_string[i];
        i++;
    }

    int dna_length = i;
    
    
    char * rna_string = (char *)malloc(sizeof(char) * dna_length);
    //swap T's and U's
    i = 0;
    for(i; i < dna_length; i++){
        //get DNA char
        char cur_dna_char = dna_string[i];        
        if(cur_dna_char != 'T'){
            *(rna_string + i) = cur_dna_char;
        } else {
            *(rna_string + i) = 'U';
        }
        
    }
    cout << dna_string << endl;
    cout << rna_string << endl;
    free(rna_string);
    
    
    return 0;
}
