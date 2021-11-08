//
//  student.cpp
//  NameDirectoryProject
//
#include "student.h"
#include <iostream>
#include <iomanip>

Student::Student() { //Blank constructor
    this->studentID = "Z0";
    this->firstName = "AAA";
    this->lastName = "ZZZ";
    this->emailAddress = "ERROR";
    this->age = 0;
    for(int i=0; i<numCourses; i++){
    this->daysInCourse[i]=0;
    }
    this->degreeProgram = DegreeProgram::SOFTWARE;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeAdd) { //Alternate constructor
        this->studentID = studentID;
        this->firstName = firstName;
        this->lastName = lastName;
        this->emailAddress = emailAddress;
        this->age = age;
    for(int i=0; i<Student::numCourses; ++i){
    this->daysInCourse[i] = daysInCourse[i];
    }
    this->degreeProgram = degreeAdd;
}

Student::~Student(){  //Blank destructor
}

void Student::print()
{
    cout << this->getStudentID() << '\t';
    cout << "First Name: " << this->getFirstName() << '\t';
    cout << "Last Name: "  << this->getLastName() << '\t';
    //cout << "Email Address: "  << this->getEmailAddress() << '\t';
    cout << "Age: "  << this->getAge() << '\t';
    cout << "daysInCourse: " << '{';
    for (int i=0; i<numCourses; ++i){
        if (i == (numCourses - 1)){
        cout << this->getDaysInCourse()[i] << '}' << '\t';
    }
        else {
            cout << this->getDaysInCourse()[i] << ", ";
        }
    }
    cout << classStrings[this->getDegreeProgram()] << "." << endl;
    return;
}

string Student::getStudentID() { //Student ID
    return  this->studentID;
}
    void Student::setStudentID(string newStudentID) {
        studentID = newStudentID;
            return;
}

string Student::getFirstName() { //First name
    return this->firstName;
}
    void Student::setFirstName(string newFirstName) {
        firstName = newFirstName;
            return;
}

string Student::getLastName() { //Last name
    return this->lastName;
}
    void Student::setLastName(string newLastName) {
        lastName = newLastName;
            return;
}

string Student::getEmailAddress() { //Email address
    return this->emailAddress;
}
    void Student::setEmailAddress(string newEmailAddress) {
        emailAddress = newEmailAddress;
            return;
}

int Student::getAge() { //Age
    return this->age;
}
    void Student::setAge(int newAge) {
        age = newAge;
            return;
}

int* Student::getDaysInCourse() { //Days in course array
    return this->daysInCourse;
}
void Student::setDaysInCourse(int newDays[]) {
        for (int i=0; i<numCourses; ++i){
        daysInCourse[i] = newDays[i];
        }
            return;
}


DegreeProgram Student::getDegreeProgram() { //degreeProgram
    return this->degreeProgram;
}
    void Student::setDegreeProgram(DegreeProgram newDegreeProgram) {
        degreeProgram = newDegreeProgram;
            return;
}
