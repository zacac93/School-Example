//
//  Student.h
//  Lab 07 (for reals)
//
//  Created by Zac Clark on 1/23/16.
//  Copyright © 2016 Zac Clark. All rights reserved.
//

#pragma once
#include "StudentInterface.h"
#include "School.h"
#include <cmath>

using namespace std;

class Student : public StudentInterface
{
public:
    Student();
    ~Student(void);
    Student(unsigned long long int ID, string name, string address, string phone, double GPA);
    unsigned long long int getID();
    string getName();
    string getGPA();
    void addGPA(double classGrade);
    string toString();
    
protected:
    unsigned long long int ID;
    string name;
    string address;
    string phone;
    string GPA_string;
    double GPA;
    double grade;
    int class_count;
    
};
