#include "student.h"
#include "degree.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//Empty Constructor

Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->studentAge = -1;
    for (int i = 0; i < COURSE_SIZE; i++) {
        this->daysPerCourse[i] = 0;
    }
    this->degreeProgram = DegreeProgram::DEGREE_UNDECIDED;
};

// Established Constructor

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysPerCourse[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->studentAge = studentAge;
	for (int i = 0; i < COURSE_SIZE; ++i) {
		this->daysPerCourse[i] = daysPerCourse[i];
    }   
    this->degreeProgram = degreeProgram;
}

// Destructor

Student::~Student() {}

// Setters, AKA Mutators

void Student::SetID(string studentID) {
    this->studentID = studentID;
    return;
}

void Student::SetFirstName(string firstName) {
    this->firstName = firstName;
    return;
}

void Student::SetLastName(string lastName) {
    this->lastName = lastName;
    return;
}

void Student::SetEmail(string emailAddress) {
    this->emailAddress = emailAddress;
    return;
}

void Student::SetAge(int studentAge) {
    this->studentAge = studentAge;
    return;
}

void Student::SetDaysPerCourse(int daysPerCourse[]) {
    for (int i = 0; i < COURSE_SIZE; ++i) {
        this->daysPerCourse[i] = daysPerCourse[i];
    }
}

void Student::SetDegreeProgram(DegreeProgram program) {
    this->degreeProgram = program;
    return;
}

//Getters, AKA Accessors

string Student::GetID() const {
    return studentID;
}

string Student::GetFirstName() const {
    return firstName;
}

string Student::GetLastName() const {
    return lastName;
}

string Student::GetEmail() const {
    return emailAddress;
}

int Student::GetAge() const {
    return studentAge;
}

int* Student::GetDaysPerCourse() {
    return daysPerCourse;
}

DegreeProgram Student::GetDegreeProgram() const {
    return degreeProgram;
}

//Print() Method

void Student::Print() const {
    
    string degree;

    if (GetDegreeProgram() == 0) {
        degree = "Degree Undecided";
    }
    else if (GetDegreeProgram() == 1) {
        degree = "Security";
    }
    else if (GetDegreeProgram() == 2) {
        degree = "Network";
    }
    else if(GetDegreeProgram() == 3) {
        degree = "Software";
    }

    cout << studentID << '\t';
    cout << "First name: " << firstName << ",\t";
    cout << "Last name: " << lastName << ",\t";
    cout << "Email: " << emailAddress << ",\t";
    cout << "Age: " << studentAge << ",\t";
    cout << "Days In Courses: {";
    for (int i = 0; i < COURSE_SIZE; ++i) {
        cout << daysPerCourse[i];
        if (i != COURSE_SIZE - 1) {
            cout << ", ";
        }
    }
    cout << "}" << ",\t" << "Degree Program: ";
    cout << degree << endl << endl;
}

