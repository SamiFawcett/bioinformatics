/* 
 given string s, find out how many A,C,G,T
*/
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
    int ACGT_results[4];
    int i = 0;
    for(i; i < 4; i++){
        ACGT_results[i] = 0;
    }


    string dna_string = "GGTTGGTCAACGCACCCTCCTCCATGATGATAGAGGCGGAATGTAGAGTTAAGCGTTGATTCCTGGAAAGAACATAGGAGCTCCGTTCCCGGCTTACGCTCGGTTGCGACTCGATTTCGACCTCCTTGTTTCACCTTGCATTTGCGATATCCCGATTGTGGTCGTACACATCTGCATAATATCTAGATTAAAGCTTTGCTGGTCCAAGATTTTAAGTGGCCATCGCTATGTCCCGCTTCACTGGTTGATTGCACGTGACGCCGAACCTCCTTAAATTCGAGCTACGTCCTGTAGCACAGTCAGGATCCACTTTCGCAGGCCCGCGAATATGCCCCACTGACTTCTAAAAACTGTGGACAGACAAATCCATGATACGATGGGTGCCCGCGAGCGCGACAGATTGGCCTCCGCCGCAAAACAGAGCGATCGAAGCGGAAACGCTAAATGGATGGTTTCGGAAATGCAGACACTACATGACGATAAGCACCACGCCGCGCTCCTGATCCCTGTGACTCATCCTGGTCTATGTCGCTCTCAAGTACTTTCCATATGGCAGAGTCGGCAAACGGCCAGCCGCTGGGCTTTGTACCGGCCTGCAAGACGAATGATTTCAACGTTGCAATCGAATTATGCACCCGAGAAGGCAATGGAAACACACTATTGTCCACCGGACGCCATGTGAACACAAACAGTCGTCAGTATAAACTATCTTAATACCGGTTTAAGTGAAAAATCAATAGTCAAAACGTTGCCGAGAATACGACCATATGCCAGAACCCTAAACCCTTAGTTTCTTACCGGTTAAG";

    char dna_char = dna_string[0];
    i = 0;
    while(dna_char){
        dna_char = dna_string[i];
        i++;
    }

    int dna_length = i;

    i = 0;
    for(i = 0; i < dna_length; i++){
        if(dna_string[i] == 'A'){
            (ACGT_results[0])++;
        } else if(dna_string[i] == 'C') {
            (ACGT_results[1])++;
        } else if(dna_string[i] == 'G'){
            (ACGT_results[2])++;
        } else if(dna_string[i] == 'T'){
            (ACGT_results[3])++;
        }
    }


    //print out results
        cout << ACGT_results[0] << " " <<
                ACGT_results[1] << " " <<
                ACGT_results[2] << " " << 
                ACGT_results[3] << endl;      
    


    


    



    




    return 0;
}
