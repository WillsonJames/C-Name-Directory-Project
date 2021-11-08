//
//  student.h
//  NameDirectoryProject
//
#pragma once
#include <iostream>
#include <iomanip>
#include "student.h"
#include "degree.h"
using namespace std;

class Student {
public:
    const static int numCourses = 3; //Number of courses in array
    
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[numCourses];
    DegreeProgram degreeProgram;
    
public:
    Student(); //Constructor
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeAdd) ; //Specified constructor
    ~Student(); //Destructor
    
    void print(); //Prints all info for student
    
    //Get and Set commands for each variable
    string getStudentID(); //Student ID
    void setStudentID(string newStudentID);
    
    string getFirstName(); //First name
    void setFirstName(string newFirstName);
    
    string getLastName(); //Last name
    void setLastName(string newLastName);
    
    string getEmailAddress(); //Email address
    void setEmailAddress(string newEmailAddress);
    
    int getAge(); //Age
    void setAge(int newAge);
    
    int* getDaysInCourse(); //Days in courses array
    void setDaysInCourse(int newDays[]);
    
    DegreeProgram getDegreeProgram(); //Degree program
    void setDegreeProgram(DegreeProgram newDegreeProgram);
};
