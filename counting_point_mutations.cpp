#include <iostream> 
#include <iomanip>
#include <string.h>
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


int main(int argc, char const *argv[])
{


    ifstream inFile;
    const char * filename = *(argv + 1);
    inFile.open(filename);
    
    string s;
    string t;

    getline(inFile, s);
    getline(inFile, t);

    int i = 0;
    int count = 0;
    //s and t are the same length!
    for(i; i < get_len(s) - 2; i++){
        if(s[i] != t[i]){
            count++;
        }
    }

    inFile.close();

    cout << count << endl;
    

    return 0;
}
