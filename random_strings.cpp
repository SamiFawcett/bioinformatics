#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <math.h>


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

int getGC(string DNA){
    int dna_len = get_len(DNA) - 1;
    int i;
    int count = 0;
    for(i = 0; i < dna_len; i++){
        if(DNA[i] == 'G' || DNA[i] == 'C'){
            count++;
        } else {
            continue;
        }
    }
    return count;
}

int getAT(string DNA){
    int dna_len = get_len(DNA) - 1;
    int i;
    int count = 0;
    for(i = 0; i < dna_len; i++){
        if(DNA[i] == 'A' || DNA[i] == 'T'){
            count++;
        } else {
            continue;
        }
    }
    return count;
}


int main(int argc, char const *argv[])
{
    ifstream inFile;
    
    const char * filename = argv[1];
    inFile.open(filename);


    string dna;
    getline(inFile, dna);
    string gc_contents;
    getline(inFile, gc_contents);
    int gc_content_len = 1;
    int i;
    char ch = gc_contents[0];
    while(ch){
        if(ch == ' '){
            gc_content_len++;
        }
        i++;
        ch = gc_contents[i];
    }


    //put the floats into an array
    double * gc_content_sep = (double *)malloc(sizeof(double) * gc_content_len);
    int gc_content_sep_idx = 0;
    i = 0;
    ch = gc_contents[0];
    string gc_indiv_str = "";
    bool out = true;
    while(out){
        //c++ is so complicated for no reason.
        string s(1, ch);
        gc_indiv_str.append(s);
        if(ch == ' ' || ch == '\0'){
            //insert into array
            gc_content_sep[gc_content_sep_idx] = atof(gc_indiv_str.c_str());
            //reset
            gc_indiv_str = "";
            gc_content_sep_idx++;
            if(ch == '\0'){
                out = false;
            }
        }
        i++;
        ch = gc_contents[i];
    }


    //go throuh gc_content_sep and apply math and save output in a double *
    double * output = (double *)malloc(sizeof(double) * gc_content_len);
    
    //find number of gc and number of at
    int gc = getGC(dna); 
    int at = getAT(dna);
    
    for(i = 0; i < gc_content_len; i++){
        //log10(X^(gc) * Y^(at))
        double X = (gc_content_sep[i])/2.0;
        double Y = (1 - gc_content_sep[i])/2.0;
        output[i] = log10(pow(X, gc) * pow(Y, at));
        cout.precision(3);
        cout << fixed << output[i] << " ";
    }

    cout << endl;
    inFile.close();

    return 0;
}
