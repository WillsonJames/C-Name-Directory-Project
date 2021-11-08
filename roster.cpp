//
//  roster.cpp
//  NameDirectoryProject
//
#include "roster.h"



Roster::~Roster(){ //destructor
    for (int i=0; i<numStudentsInit; i++){
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
        }
    
void Roster::readTo(string studentLine){
        size_t right = studentLine.find(",");
        string studentID = studentLine.substr(0, right);
    
        size_t left = right + 1;
        right = studentLine.find(",", left);
        string firstName = studentLine.substr(left, right - left);

        left = right + 1;
        right = studentLine.find(",", left);
        string lastName = studentLine.substr(left, right - left);
    
        left = right + 1;
        right = studentLine.find(",", left);
        string emailAddress = studentLine.substr(left, right - left);
    
        left = right + 1;
        right = studentLine.find(",", left);
        string age = studentLine.substr(left, right - left);

        left = right + 1;
        right = studentLine.find(",", left);
        string daysInCourse1 = studentLine.substr(left, right - left);

        left = right + 1;
        right = studentLine.find(",", left);
        string daysInCourse2 = studentLine.substr(left, right - left);

        left = right + 1;
        right = studentLine.find(",", left);
        string daysInCourse3 = studentLine.substr(left, right - left);

        left = right + 1;
        DegreeProgram degreeAdd = SOFTWARE;

            int ERROR = 90909;
        string degreeType = studentLine.substr(left, studentLine.length() - left);
                try
                {

                    if (degreeType == "SOFTWARE") { degreeAdd = DegreeProgram::SOFTWARE; }
                    else if (degreeType == "SECURITY") { degreeAdd = DegreeProgram::SECURITY; }
                    else if (degreeType == "NETWORK") { degreeAdd = DegreeProgram::NETWORK; }
                    else throw ERROR;
                }
                catch (int e)
                {
                    cout << "Invalid Degree Type\n";
                    cout << "Error code: " << e << endl;
                    return;
                }
       add(studentID, firstName, lastName, emailAddress, stoi(age), stoi(daysInCourse1), stoi(daysInCourse2),  stoi(daysInCourse3), degreeAdd);
    }

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)   {
    int daysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3}; //moves course days into array
    
    classRosterArray[numStudentsNow++] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram); //dynamically calls constructor for new student object and adds it into class roster
}

void Roster::remove(string studentID)   {
    bool deleteSuccessful = false;
    for (int i=0; i<Roster::numStudentsNow; i++){
        if (classRosterArray[i]->getStudentID() == studentID){ //finds student ID
            if (i < numStudentsInit - 1) {
                Student* placeHolder = classRosterArray[i];
                for (int k=0; k<numStudentsInit-i; ++k){ //Moves other items down list in original order
                    classRosterArray[i+k] = classRosterArray[i+k+1];
                }
                classRosterArray[numStudentsInit-1] = placeHolder; //moves student to delete to end
                }
                
            Roster::numStudentsNow--; //Removes value for last student from list so that it is not printed
            deleteSuccessful = true;
            cout << "Student " << studentID << " removed." << endl;
        }
            
    }
    if (deleteSuccessful == false){
        cout << "Student with ID " << studentID << " not found." << endl;
    }
    cout << endl;
    return;
}

void Roster::printAll() { //Goes through student list and prints each
    cout << "Student List: " << endl;
    for (int i=0; i<Roster::numStudentsNow; i++){
        classRosterArray[i]->print();
    }
    cout << endl;
    return;
}

void Roster::printAverageDaysInCourse(string studentID) {
    for (int i=0; i<Roster::numStudentsNow; i++) {
        if (studentID == classRosterArray[i]->getStudentID()){
            double studentAverage = 0.0;
            int studentTotal = 0;
            for (int k=0; k<Student::numCourses; k++){ //Adds up all day values for student
                studentTotal += classRosterArray[i]->getDaysInCourse()[k];
            }
            studentAverage = static_cast<double>(studentTotal)/static_cast<double>(Student::numCourses); //sets studentAverage to studentTotal divided by numCourses after converting both to double
            cout << studentID << ": " << studentAverage << endl;
        }
    }
    return;
}

void Roster::printInvalidEmails() {
    bool invalid = false; //tracks if any email is invalid
    for (int i=0; i<Roster::numStudentsNow; i++) {
        
        string emailTemp = (classRosterArray[i]->getEmailAddress()); //Moves current email to string emailTemp
        
        if (emailTemp.find('@') == string::npos || emailTemp.find('.') == string::npos || emailTemp.find(' ') != string::npos){ //Checks if any category invalid for this email
            invalid = true;
            
            cout << "Invalid email for student: " << classRosterArray[i]->getStudentID() <<": " << emailTemp << " "; //Prints student info if invalid

            if (emailTemp.find('@') == string::npos){ //if email missing '@'
            cout << "Missing '@' symbol. " ;
            }
        
            if (emailTemp.find('.') == string::npos){ //if email missing '.'
           cout << "Missing '.' character. ";
            }
            
            if (emailTemp.find(' ') != string::npos){ //if email includes space
            cout << "Email has space. ";
            }
        cout << endl; //prints endline after printing each invalid category for current email
        }//Goes to next student
    }
        
    if (invalid == false){
        cout << "All emails validated." << endl;
    }
    cout << endl;
    return;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)  {
    cout << "Students in the " << classStrings[degreeProgram] << " program:" << endl;
    for (int i=0; i<Roster::numStudentsNow; ++i){
        if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram){
            classRosterArray[i]->print();
        }
    }
    cout << endl;
    return;
}
