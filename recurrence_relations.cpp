#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>

using namespace std;

//recursive version
long find_rabbits(int months, int reproduction_rate){
    if(months == 1 || months == 2){
        return 1;
    } else {
        return find_rabbits(months - 1, reproduction_rate) + (reproduction_rate*(find_rabbits(months - 2, reproduction_rate)));
    }
}


int main(int argc, char const *argv[])
{
    int months = atoi(argv[1]);
    int reproduction_rate = atoi(argv[2]);
    // iterative version
    /*
    long result = 0;
    //at 2 months this is always the case of nr_rabbits and r_rabbits
    int nr_rabbits = reproduction_rate;
    int r_rabbits = 1;
    
    int i = 0;
    for(i; i < months - 3; i++){
        //update nr_rabbits
        nr_rabbits = r_rabbits * reproduction_rate;
        //update r_rabbits
        r_rabbits = r_rabbits + reproduction_rate;
    }   
    //return the sum of the non-reproductive rabbits and the reproductive rabits
    // nr_rabbits + r_rabbits = #of rabbits given months and reproductive_rate
    result = nr_rabbits + r_rabbits;
    cout << result << endl;
    */
    long result = find_rabbits(months, reproduction_rate);
    cout << result << endl;
    return 0;
}
