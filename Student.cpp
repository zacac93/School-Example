//
//  Student.cpp
//  Lab 07 (for reals)
//
//  Created by Zac Clark on 1/23/16.
//  Copyright © 2016 Zac Clark. All rights reserved.
//

#include <stdio.h>
#include "Student.h"

using namespace std;

Student::Student()
{
    
}
Student::~Student()
{
    
}
Student::Student(unsigned long long int ID, string name, string address, string phone, double GPA) : ID(ID), name(name), address(address), phone(phone), GPA(GPA)
{
    grade = 0;
    class_count = 0;
}
unsigned long long int Student::getID()
{
    //cout << "ran getID()" << endl;
    return ID;
}
string Student::getName()
{
    //cout << "ran getName()" << endl;
    return name;
}
string Student::getGPA()
{
    //cout << "ran getGPA()" << endl;
    if(class_count == 0)
        return "0.00";
    //cout << "class_count > 0" << endl;
    stringstream strm;
    strm << fixed << setprecision(2) << grade/class_count;
    GPA_string = strm.str();
    return GPA_string;
}
void Student::addGPA(double classGrade)
{
    //cout << "ran addGPA()" << endl;
    grade += classGrade;
    class_count++;
   
}
string Student::toString()
{
    //cout << "ran toString()" << endl;
    
    //convert ID to string
    stringstream strmID;
    strmID << ID;
    string ID_string = strmID.str();
    //construct student object as string
    string student_string = ID_string + "\n" + name + "\n" + address + "\n" + phone + "\n" + getGPA();
    
    //cout << student_string << endl;
    return student_string;
}