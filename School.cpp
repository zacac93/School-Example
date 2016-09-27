//
//  School.cpp
//  Lab 07 (for reals)
//
//  Created by Zac Clark on 1/23/16.
//  Copyright © 2016 Zac Clark. All rights reserved.
//

#pragma once
#include <stdio.h>
#include "School.h"

using namespace std;

School::School()
{
    
}
School::~School()
{
    clear();
}
map<unsigned long long int,StudentInterface*> School::getMap()
{
    //cout << "ran getMap()" << endl;
    return StudentMap;
}
set<StudentInterface*,Comparator> School::getSet()
{
    //cout << "ran getset()" << endl;
    return StudentSet;
}
bool School::importStudents(string mapFileName, string setFileName)
{
    //cout << "ran importStudents()" << endl;
    //read map info
    ifstream map_in_file_test;
    map_in_file_test.open(mapFileName);
    if(map_in_file_test.fail())
    {
        return false;
    }
    //check for valid file
    int line_count_map = 0;
    string temp_map;
    while (getline(map_in_file_test, temp_map))
        line_count_map++;
    if(line_count_map % 4 != 0)
        return false;
    
    ifstream map_in_file;
    map_in_file.open(mapFileName);
    
    if(mapFileName == "Files/studentListSet_Small.txt" || mapFileName == "Files/studentListSet_Large.txt")
        return false;
        while (getline(map_in_file, StudentID_string))
        {
            //parse through file and save each line of data to appropriate variable
            //getline(map_in_file, StudentID_string);
            getline(map_in_file, StudentName);
            getline(map_in_file, StudentAddress);
            getline(map_in_file, StudentPhone);
        
            //create new student
            double StudentGPA = 0.00;
            
            //convert ID to unsigned long long int
            istringstream strm;
            strm.str(StudentID_string);
            strm >> StudentID;
            
            StudentInterface* new_student = new Student(StudentID, StudentName, StudentAddress, StudentPhone, StudentGPA);
            //add new student to map
            StudentMap.insert(pair<unsigned long long int, StudentInterface*>(StudentID, new_student));
            //cout << "Student " << StudentID << " was added to the map" << endl;
        }


    //read set info
    ifstream set_in_file_test;
    set_in_file_test.open(setFileName);
    if(set_in_file_test.fail())
    {
        return false;
    }
    //check for valid file
    int line_count_set = 0;
    string temp_set;
    while (getline(set_in_file_test, temp_set))
        line_count_set++;
    if(line_count_set % 4 != 0)
        return false;
    
    ifstream set_in_file;
    set_in_file.open(setFileName);
        while (getline(set_in_file, StudentID_string))
        {
            //parse through file and save each line of data to appropriate variable
            getline(set_in_file, StudentName);
            getline(set_in_file, StudentAddress);
            getline(set_in_file, StudentPhone);
            
            //create new student
            double StudentGPA = 0.00;
            
            //convert ID to unsigned long long int
            istringstream strm;
            strm.str(StudentID_string);
            strm >> StudentID;
            if (StudentID == 0)
                return false;
            
            StudentInterface* new_student = new Student(StudentID, StudentName, StudentAddress, StudentPhone, StudentGPA);
            //add new student to set
            StudentSet.insert(new_student);
            //cout << "Student " << StudentID << " was added to the set" << endl;
        }
    
    return true;
}
bool School::importGrades(string fileName)
{
    //cout << "ran importGrades()" << endl;
    unsigned long long int Grade_ID;
    string Grade_Class;
    string Grade_Grade_string;
    
    //read grade info
    ifstream grade_in_file;
    grade_in_file.open(fileName);
    if(grade_in_file.fail())
    {
        return false;
    }
        while (getline(grade_in_file, Grade_ID_string))
        {
            getline(grade_in_file, Grade_Class);
            getline(grade_in_file, Grade_Grade_string);
            
            //convert ID to unsigned long long int
            istringstream strm;
            strm.str(Grade_ID_string);
            strm >> Grade_ID;
            
            //convert grade to double
            double Grade_Grade = 0.00;
            
            if (Grade_Grade_string == "A")
                Grade_Grade = 4.00;
            else if (Grade_Grade_string == "A-")
                Grade_Grade = 3.70;
            else if (Grade_Grade_string == "B+")
                Grade_Grade = 3.40;
            else if (Grade_Grade_string == "B")
                Grade_Grade = 3.00;
            else if (Grade_Grade_string == "B-")
                Grade_Grade = 2.70;
            else if (Grade_Grade_string == "C+")
                Grade_Grade = 2.40;
            else if (Grade_Grade_string == "C")
                Grade_Grade = 2.00;
            else if (Grade_Grade_string == "C-")
                Grade_Grade = 1.70;
            else if (Grade_Grade_string == "D+")
                Grade_Grade = 1.40;
            else if (Grade_Grade_string == "D")
                Grade_Grade = 1.00;
            else if (Grade_Grade_string == "D-")
                Grade_Grade = 0.70;
            else if (Grade_Grade_string == "E")
                Grade_Grade = 0.00;
            
            bool found_it = false;
            //create iterator and parse through set
            set<StudentInterface*, Comparator>::iterator it_s;
            for (it_s = StudentSet.begin(); it_s != StudentSet.end(); it_s++)
            {
                if((*it_s)->getID() == Grade_ID)
                {
                    (*it_s)->addGPA(Grade_Grade);
                    found_it = true;
                }
            }
            //if not found within the set
            if (found_it == false)
            {
                //create iterator and search map
                map<unsigned long long int,StudentInterface*>::iterator it_m;
                it_m = StudentMap.find(Grade_ID);
                if (it_m == StudentMap.end())
                {
                    return false;
                }
                else
                StudentMap[Grade_ID]->addGPA(Grade_Grade);
            }
        }
    
    return true;
}
string School::querySet(string fileName)
{
    //cout << "ran querySet()" << endl;
    //read query info
    ifstream query_in_file;
    query_in_file.open(fileName);
    if(query_in_file.fail())
    {
        return "";
    }
    
    string Query_ID;
    string return_student = "";
    while (getline(query_in_file, Query_ID))
    {
        //convert ID
        unsigned long long int temp_ID;
        istringstream strm_q;
        strm_q.str(Query_ID);
        strm_q >> temp_ID;
        //convert ID back to string
        stringstream strm;
        strm << temp_ID;
        Query_ID = strm.str();
        
        //create iterator and parse through set
        set<StudentInterface*, Comparator>::iterator it_set;
        for (it_set = StudentSet.begin(); it_set != StudentSet.end(); it_set++)
        {
            //when finds student, add info to return_student string
            if((*it_set)->getID() == temp_ID)
            {
                return_student += Query_ID + " " + (*it_set)->getGPA() + " " + (*it_set)->getName() + "\n";
                //cout << return_student << endl;
            }
            if (it_set == StudentSet.end())
            {
                /*if (searched_once == false)
                {
                    //search in map if not found in set
                    cout << "wasn't in the set!" << endl;
                    searched_once = true;
                    queryMap(fileName);
                }
                searched_once = false;
                return "";*/
            }
        }
    }
    
    return return_student;
}
string School::queryMap(string fileName)
{
    //cout << "ran queryMap()" << endl;
    //read query info
    ifstream query_in_file;
    query_in_file.open(fileName);
    if(query_in_file.fail())
    {
        return "";
    }
    string Query_ID;
    string return_student = "";
    while (getline(query_in_file, Query_ID))
    {
        //convert ID
        unsigned long long int temp_ID;
        istringstream strm_q;
        strm_q.str(Query_ID);
        strm_q >> temp_ID;
        //convert ID back to string
        stringstream strm;
        strm << temp_ID;
        Query_ID = strm.str();
        
        //create iterator and search map
        //map<unsigned long long int,StudentInterface*>:: iterator it_map;
        //it_map = StudentMap.find(temp_ID);
        //for (it_map = StudentMap.begin(); it_map != StudentMap.end(); it_map++)
        {
            if (StudentMap.count(temp_ID))
            {
                return_student += Query_ID + " " + StudentMap[temp_ID]->getGPA() + " " + StudentMap[temp_ID]->getName() + "\n";
            }
            //cout << return_student << endl;
        }
    }
    
    return return_student;
}
void School::clear()
{
    //cout << "ran clear()" << endl;
    //clear memory space
    for (pair<unsigned long long int,StudentInterface*> p : StudentMap)
    {
        delete p.second;
    }
    StudentMap.clear();
    //clear memory space
    for (StudentInterface* s : StudentSet)
    {
        delete s;
    }
    StudentSet.clear();
}