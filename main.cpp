//
//  main.cpp
//  NameDirectoryProject
//
#include <iostream>
#include <iomanip>
#include "roster.h"
#include "degree.h"
using namespace std;

int main() {
cout << "Course: C867, Language: C++, ID: 001523156, Name: James Fuller" << endl;
cout << endl;
    
const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,James,Fuller,willsonjames@protonmail.com,26,12,12,12,SOFTWARE"};
const int numStudentsInit = 5;
Roster classRoster;
    for (int i=0; i<numStudentsInit; ++i){
        classRoster.readTo(studentData[i]);
    }
       
    
classRoster.printAll();


classRoster.printInvalidEmails();
    
cout << "Average days in class for students: " << endl;

for (int i=0; i<classRoster.numStudentsNow; ++i){
classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
}
cout << endl;


classRoster.printByDegreeProgram(SOFTWARE);
    
classRoster.remove("A3");

classRoster.printAll();

classRoster.remove("A3");


//5.  Implement the destructor to release the memory that was allocated dynamically in Roster.
    return 0;
}
