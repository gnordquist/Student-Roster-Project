#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

//#include "roster.h"

const string studentData[NUM_STUDENTS] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
								           "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
					           			   "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
								           "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
								           "A5,Gabrielle,Nordquist,gnordqu@wgu.edu,23,20,30,40,SOFTWARE"
};

int main() {
	
    // Required student information header
    cout << "Scripting and Programming - Applications C867;\t" << "Written in C++ on Visual Studio;" << endl;
    cout << "Student ID: 001629826;\t" << "Name: Gabrielle Nordquist" << endl << endl;


    Roster* classRoster = new Roster(NUM_STUDENTS);

    for (int i = 0; i < NUM_STUDENTS; i++) {
        classRoster->parseAndAdd(studentData[i]);
 }

// Provided psuedocode:

    // Print Roster
    classRoster->printAll();
    cout << endl;

    // Print Invalid Emails
    classRoster->printInvalidEmails();
    cout << endl;

    // Print average days per course for each student based off of their student ID
    
    cout << "The average amount of days each student spent taking 3 courses: " << endl << endl;
    classRoster->printAverageDaysInCourse("A1");
    classRoster->printAverageDaysInCourse("A2");
    classRoster->printAverageDaysInCourse("A3");
    classRoster->printAverageDaysInCourse("A4");
    classRoster->printAverageDaysInCourse("A5");
    cout << endl;

    // Print by degree program "SOFTWARE"
    classRoster->printByDegreeProgram(SOFTWARE);

    // Remove student A3 from roster
    classRoster->remove("A3");
    cout << endl;

    // Print newly updated roster
    classRoster->printAll();

    // Try to remove student A3 again...
    classRoster->remove("A3");
    // Expected: the above line should print a message saying such a student with this ID was not found.
    // Should throw an error message
    cout << endl;

    // Implementing the destructor to release allocated dynamic memory
    classRoster->~Roster();

    return 0;
}