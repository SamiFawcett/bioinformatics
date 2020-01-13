#include <iostream> 
#include <stdlib.h>
#include <string>
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




int main(int argc, const char * argv[]){

    /*

    >Rosalind_87
    CAGCATGGTATCACAGCAGAG

    f(C) = 0
    f(CA) = 0
    f(CAG) = 0
    f(CAGC) = 1
    f(CAGCA) = 2
    f(CAGCAT) = 0
    f(CAGCATG) = 0
    ...
    ...
    f(CAGCATGGTA) = 0
    f(CAGCATGGTATCACAGCAGAG) = 0

    
    */
    ifstream inFile;
    const char * filename = argv[1];
    inFile.open(filename);

    string DNA;
    getline(inFile, DNA);

    int dna_len = get_len(DNA) - 1;
    int * failure_arr = (int *)malloc(sizeof(int) * dna_len);
    int i;


    for(i = 0; i < dna_len; i++){
        cout << i << " ";
        if(i == 0){
            //first index of failure array is always 0 because there is only 1 character.
            failure_arr[i] = 0;
        } else {
            int last_fail_pos = failure_arr[i-1];
            if(DNA[i] == DNA[last_fail_pos]){
                failure_arr[i] = last_fail_pos + 1;
            } else {
                int j;
                for(j = i; j >= 0; j--){
                    if(j == 0){
                        break;
                    } else if(DNA[i] == DNA[j-1]){
                        failure_arr[i] = failure_arr[j-1];
                        break;
                    }
                }
                cout << j << " " << failure_arr[i] << endl;
            } 
        }
        
        
    }

    cout << endl;
    


    return 0;
}