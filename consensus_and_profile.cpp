/*
INPUT:
>Rosalind_1
ATCCAGCT
>Rosalind_2
GGGCAACT
>Rosalind_3
ATGGATCT
>Rosalind_4
AAGCAACC
>Rosalind_5
TTGGAACT
>Rosalind_6
ATGCCATT
>Rosalind_7
ATGGCACT

OUTPUT:
ATGCAACT
A: 5 1 0 0 5 5 0 0
C: 0 0 1 4 2 0 6 1
G: 1 1 6 3 0 1 0 0
T: 1 5 0 0 0 1 1 6

*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>



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

void print_profile(int ** &profile, int dna_len){
    int i;
    int j;
    for(i = 0; i < 4; i++){
        if(i == 0){
            cout << "A: ";
        } else if(i == 1){
            cout << "C: ";
        } else if(i == 2){
            cout << "G: ";
        } else if(i == 3){
            cout << "T: ";
        } else {}
        for(j = 0; j < dna_len; j++){
            cout << profile[i][j] << " ";
        }
        cout << endl;
    }
}



void update_profile(string &dna, int dna_len, int ** &profile){
    int i;
    for(i = 0; i < dna_len; i++){
        if(dna[i] == 'A'){
            if(profile[0][i]){
                profile[0][i] = profile[0][i] + 1;
            } else {
                profile[0][i] = 1;
            }
        } else if(dna[i] == 'C'){
            if(profile[1][i]){
                profile[1][i] = profile[1][i] + 1;
            } else {
                profile[1][i] = 1;
            }
        } else if(dna[i] == 'G'){
            if(profile[2][i]){
                profile[2][i] = profile[2][i] + 1;
            } else {
                profile[2][i] = 1;
            }
        } else if(dna[i] == 'T'){
            if(profile[3][i]){
                profile[3][i] = profile[3][i] + 1;
            } else {
                profile[3][i] = 1;
            }
        }
    }
}


int get_max(int * &profile_nums){
    int i;
    int max = profile_nums[0];
    int max_idx = 0;
    for(i = 0; i < 4; i++){
        if(profile_nums[i] > max){ 
            max = profile_nums[i];
            max_idx = i;
        }
    }
    return max_idx;
}



int main(int argc, char const *argv[])
{
    
    ifstream inFile;
    const char * filename = argv[1];
    inFile.open(filename);


   string partial_dna = "";
   string full_dna = "";
   string line;
   int ** profile;
   int dna_len;
   int i;
   

   //skip first line
   getline(inFile, line);
   int update_ready = 0;
    
    while(getline(inFile, line)){
        //only used once because we only need to update profile dimensions once
        if(line[0] == '>' && update_ready == 0){
            dna_len = get_len(full_dna) - 1;
            profile = (int **)calloc(4, sizeof(int *));
            int i;
            for(i=0; i < 4; i++){ 
                *(profile+i) = (int *)calloc(dna_len, sizeof(int));
            }
            update_profile(full_dna, dna_len, profile);
            full_dna = "";
            //no longer needs to update profile size because all dna are same length;
            update_ready++;
        } else if(line[0] == '>' && update_ready == 1){
            update_profile(full_dna, dna_len, profile);
            full_dna = "";  
        } else { 
            //start concating partial dna's
            partial_dna = line;
            partial_dna.erase(get_len(partial_dna) - 2);
            full_dna.append(partial_dna);
            partial_dna = "";
        }
        
        
    }
    //final update
    update_profile(full_dna, dna_len, profile);

    //print_profile(profile, dna_len);

    char * consensus = (char *)calloc(dna_len, sizeof(char));
    
    for(i = 0; i < dna_len; i++){
        int a = profile[0][i];
        int c = profile[1][i];
        int g = profile[2][i];
        int t = profile[3][i];
        int * max = (int *)malloc(sizeof(int) * 4);
        max[0] = a;
        max[1] = c;
        max[2] = g;
        max[3] = t;
        int corresponding_idx = get_max(max);
        if(corresponding_idx == 0){
            consensus[i] = 'A';
        } else if(corresponding_idx == 1){
            consensus[i] = 'C';
        } else if(corresponding_idx == 2){
            consensus[i] = 'G';
        } else if(corresponding_idx == 3){
            consensus[i] = 'T';
        }
        free(max);
    }

    cout << consensus << endl;
    print_profile(profile, dna_len);

    inFile.close();
    
    free(consensus);
    i = 0;
    for(i; i < 4; i++){
        free(*(profile+i));
    }
    free(profile);
    

    return 0;
}