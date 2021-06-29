#include "roster.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


// Constructor

Roster::Roster()
{
    this->maxStudents = 0;
    this->lastIndex = -1;
    this->classRosterArray = nullptr;
}

Roster::Roster(int maxStudents)
{
    this->maxStudents = maxStudents;
    this->lastIndex = -1;
    this->classRosterArray = new Student * [maxStudents]; // 'New' student pointer to an array of student instances
}

// Destructor

Roster::~Roster() {
    for (int i = 0; i < maxStudents; i++) {
        delete this->classRosterArray[i]; // Remove each individual student from the memory one at a time
    }
    delete this; // Then, remove the empty roster from memory
}

// Methods

void Roster::parseAndAdd(string studentInfo)
{ // Returns a vector of strings (parsed data)
    std::vector<string> dataInput; 
    std::stringstream inputSStream(studentInfo); // String to be parsed

    while (inputSStream.good())
    { // Parse the string on the commas then add each data input to the vector
        string data;
        getline(inputSStream, data, ',');
        dataInput.push_back(data);
    }
    add(dataInput.at(0), // Student ID
        dataInput.at(1), // First Name
        dataInput.at(2), // Last Name
        dataInput.at(3), // Email Address
        stoi(dataInput.at(4)), // Age
        stoi(dataInput.at(5)), // Days in course 1
        stoi(dataInput.at(6)), // Days in course 2
        stoi(dataInput.at(7)), // Days in course 3
        enumValue(dataInput.at(8)) // Degree Program
    );
}

DegreeProgram Roster::enumValue(string value) { // Convert the string passed from the add function into an enum
    if (value == "SECURITY") {
        return SECURITY;
    }
    else if (value == "NETWORK") {
        return NETWORK;
    }
    else if (value == "SOFTWARE") {
        return SOFTWARE;
    }
    else {
        return DEGREE_UNDECIDED;
    }
}

void Roster::add(string studentID,
                 string firstName,
                 string lastName, 
                 string emailAddress,
                 int age, 
                 int daysInCourse1,
                 int daysInCourse2, 
                 int daysInCourse3,
                 DegreeProgram degreeProgram) { // Add a new student to the roster
    if (lastIndex < maxStudents) { 
        lastIndex++; // We increment so we dont go beyond our proper roster size
        this->classRosterArray[lastIndex] = new Student();
        this->classRosterArray[lastIndex]->SetID(studentID);
        this->classRosterArray[lastIndex]->SetFirstName(firstName);
        this->classRosterArray[lastIndex]->SetLastName(lastName);
        this->classRosterArray[lastIndex]->SetEmail(emailAddress);
        this->classRosterArray[lastIndex]->SetAge(age);
        int daysPerCourse[COURSE_SIZE] = { daysInCourse1, daysInCourse2, daysInCourse3 };
        this->classRosterArray[lastIndex]->SetDaysPerCourse(daysPerCourse);
        this->classRosterArray[lastIndex]->SetDegreeProgram(degreeProgram);
    }
    else {
        cout << "Error: Roster has exceeded max capacity." << endl << endl;
    }
}

// Removes student(s) from the roster by student ID.

void Roster::remove(string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; ++i) {
        if (this->classRosterArray[i] != nullptr && this->classRosterArray[i]->GetID() == studentID) { // student was found
            this->classRosterArray[i] = nullptr;
            found = true;
            break;
        }
    }
    if (found == false) {
        cout << "Error. Student ID " << studentID << " was not found in the system." << endl; // student not found: error message
    }
    else {
        cout << "Student ID '" << studentID << "' was removed." << endl; // student found message
    }
    cout << endl;
}

// Print a list of the student roster and their data

void Roster::printAll() {
    cout << "Student Roster Information:" << endl << endl;
    for (int i = 0; i < maxStudents; ++i) {
        if (classRosterArray[i] != nullptr) {
            this->classRosterArray[i]->Print();
        }
    }
    cout << endl;
}


void Roster::printAverageDaysInCourse(string studentID) {
    bool found = false;
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        if (this->classRosterArray[i]->GetID() == studentID) {
            found = true;
            cout << "Average number of days for Student ID: " << this->classRosterArray[i]->GetID();
            int* days = this->classRosterArray[i]->GetDaysPerCourse();
            cout << " was " << ((days[0] + days[1] + days[2]) / 3.0) << " days." << endl;
           }
    } if (!found) {
        cout << "ERROR: Student " << studentID << " was not found in the system." << endl;
    }
}

void Roster::printInvalidEmails() {
    cout << "Invalid email addresses were inputted into the system: " << endl << endl;
    bool found = false; // Just to be safe, there could be no invalid emails (even if we know there are)

    // Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ')
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        string emailAddress = classRosterArray[i]->GetEmail();
        if (emailAddress.find('.') == string::npos) { // If it does not find a '.'
            found = true;
            cout << "Error: Requires a '.' after the server name: " << emailAddress << endl;
        }
        else if (emailAddress.find('@') == string::npos) { // If it does not find a '@'
            found = true;
            cout << "Error: Requires an '@' symbol before the server name: " << emailAddress << endl;
        }
        else if (emailAddress.find(' ') != string::npos) {  // If it finds an invalid space
            found = true;
            cout << "Error: Emails do not contain spaces: " << emailAddress << endl;
        }
    }
}
// Prints out student information for a degree program specified by a chosen enumerated type.

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    cout << "Displaying Students in the selected degree program: " << endl << endl;
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        if (this->classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
            this->classRosterArray[i]->Print();
            cout << endl;
        }
    }
    cout << endl;
}

