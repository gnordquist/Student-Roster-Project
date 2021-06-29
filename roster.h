#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <string>
#include "student.h"

using namespace std;

#define NUM_STUDENTS 5

class Roster {

public:

// Constructor

	Roster();

// Estalished constructor

	Roster(int maxStudents);

//Destructor

	~Roster(); 

// Methods

	void parseAndAdd(string studentInfo);
	DegreeProgram enumValue(string value);
	void add(string studentID, 
		     string firstName, 
		     string lastName,
		     string emailAddress,
		     int age,
		     int daysInCourse1,
		     int daysInCourse2,
		     int daysInCourse3,
		     DegreeProgram degreeProgram);

	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID); 
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

private:

	Student** classRosterArray; // Array of pointers to the student objects
	int lastIndex; // The index of the last student on the roster
	int maxStudents; // The maximum size of the roster
};

#endif

