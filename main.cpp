//
//  main.cpp
//  Lab 07 (for reals)
//
//  Created by Zac Clark on 1/23/16.
//  Copyright © 2016 Zac Clark. All rights reserved.
//

#include <iostream>
#include "Student.h"
#include "School.h"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string name = "Jim";
    double GPA = 4.12345;
    
    /*using float
    float GPAf = GPA;
    GPAf *= 10;
    ceil(GPAf);
    GPAf /= 10;
    GPA = GPAf;
    cout << GPAf << endl;*/
    
    //using ceiling function
    //ceil(GPA*pow(10,GPA))/pow(10,GPA);
    //cout << GPA << endl;
    
    /*GPA *= 100;
    int GPAi = GPA;
    float GPAx = GPAi/100;
    cout << GPAx << endl;*/

    stringstream strm;
    strm << GPA;
    string GPA_string = strm.str();
    GPA_string = GPA_string.substr(0, 4);
    
    cout << GPA_string << endl;
    
    return 0;
}
