#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <iostream>
#include <string>

using namespace std;

//#define allows me to replace any occurence of COURSE_SIZE with the given size of 3

#define COURSE_SIZE 3     

class Student {

public:

// Empty Constructor

    Student();

// Established Constructor

	Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysPerCourse[], DegreeProgram degreeProgram);

// Destructor

	~Student();

//Setters (Mutators)

	void SetID(string studentID);                                        // Mutator
	void SetFirstName(string firstName);                                 // Mutator
	void SetLastName(string lastName);                                   // Mutator
	void SetEmail(string emailAddress);                                  // Mutator
	void SetAge(int studentAge);                                         // Mutator
	void SetDaysPerCourse(int daysPerCourse[]);                          // Mutator
	void SetDegreeProgram(DegreeProgram degreeProgram);                  // Mutator
	
//Getters (Accessors)

    string GetID() const;                                                // Accessor
	string GetFirstName() const;                                         // Accessor
	string GetLastName() const;                                          // Accessor
	string GetEmail() const;                                             // Accessor
	int GetAge() const;                                                  // Accessor
	int* GetDaysPerCourse();                                             // Accessor
	DegreeProgram GetDegreeProgram() const;                              // Accessor
                                   
//Print() Method

	void Print() const;

private:

//Member Variables

	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int studentAge;
	int daysPerCourse[COURSE_SIZE];
	DegreeProgram degreeProgram;
 };

#endif