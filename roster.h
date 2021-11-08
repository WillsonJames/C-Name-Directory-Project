//
//  roster.h
//  NameDirectoryProject
//
#pragma once
#include "roster.h"
#include "student.h"
#include "degree.h"
using namespace std;

class Roster {
private:
    const static int numStudentsInit = 5; //Number of initial students
public:
    Student* classRosterArray[numStudentsInit]; //Array of students
    int numStudentsNow = 0; //Keeps track of number of students in array
    ~Roster(); //Desructor
    void readTo(string studentLine); //Sorts items from initial string into student class
    
    //Add and remove functions
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string studentID);
    
    //Print functions
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
};
