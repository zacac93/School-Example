//
//  School.h
//  Lab 07 (for reals)
//
//  Created by Zac Clark on 1/23/16.
//  Copyright © 2016 Zac Clark. All rights reserved.
//

#pragma once
#include "GPAInterface.h"
#include "Student.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <iomanip>

class School : public GPAInterface
{
public:
    School();
    ~School(void);
    map<unsigned long long int,StudentInterface*> getMap();
    set<StudentInterface*,Comparator> getSet();
    bool importStudents(string mapFileName, string setFileName);
    bool importGrades(string fileName);
    string querySet(string fileName);
    string queryMap(string fileName);
    void clear();
private:
    map<unsigned long long int,StudentInterface*>StudentMap;
    set<StudentInterface*,Comparator>StudentSet;
    unsigned long long int StudentID;
    string StudentName;
    string StudentAddress;
    string StudentPhone;
    string StudentID_string;
    string Grade_ID_string;
    bool searched_once = false;
};
