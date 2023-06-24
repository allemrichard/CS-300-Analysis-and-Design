/* MacRichard Risma
* 
* 06/13/2023
* 
* CS 300 ABCU Project 2
* 
*/

#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"
using namespace std;

// Loading Data structure
int loadData(BinarySearchTree* bst) {
	ifstream in;
	Course course;
	string line;
	string courseID;
	string name;
	string preReq;
	

	// Open txt file of courses
	in.open("ABCU Course List for Project 2.txt");

	if (!in.is_open()) {
		cout << "Could not open file" << endl;
		return 1;
	}

	// Read file line by line
	while (!in.eof()) {

		while (getline(in, line)) {

			stringstream ss(line);

			getline(ss, courseID, ','); // Input for courseNumber
			course.courseNumber = courseID;

			getline(ss, name, ','); // Input for courseName
			course.courseName = name;

			if (ss.good()) {
				while (ss.good()) {		// Input for coursePrereq
					getline(ss, preReq);
					course.coursePrereq = preReq;
				}
			}
			else {				// If there are no prerequisites to the course
				preReq = "None";
				course.coursePrereq = preReq;
			}

			// Insert into BST with insert logic
			bst->Insert(course);
			ss.clear();
		}

	}
	in.close();	// Close file
	return 0;
}

// Menu option
void menuOption() {

	cout << endl;
	cout << "********************************************" << endl;;
	cout << "** Welcome! Please choose an option below **" << endl;
	cout << "**                                        **" << endl;
	cout << "**       1 - Load Data Structure          **" << endl;
	cout << "**       2 - Print Course List            **" << endl;
	cout << "**       3 - Search Course                **" << endl;
	cout << "**       4 - Exit Program                 **" << endl;
	cout << "********************************************" << endl;
	cout << "Enter Option: ";
}

// Function that turns first four letters to uppercase if needed to match file input
string upperCase(string word) {
	for (int i = 0; i < 4; ++i) {
		word.at(i) = toupper(word.at(i));
	}
	return word;
}

int main() {
	char menuInput = '0';
	string userInput;
	string userCourse;
	BinarySearchTree* bst;
	bst = new BinarySearchTree();
	Course course;

	while (menuInput != '4') {
		menuOption();
		cin >> menuInput;

		switch (menuInput) {
		case '1':
			// Load data
			cout << endl;
			cout << "Data Loaded" << endl;
			loadData(bst);
			break;

		case '2':
			// Print all courses
			bst->InOrder();
			break;

		case '3':
			// Search for a course
			cout << "Enter Course ID Number: ";
			cin >> userInput;
			userCourse = upperCase(userInput);
			course = bst->Search(userCourse);

			// if course found
			if (!course.courseNumber.empty()) {
				cout << endl;
				cout << "Course Number: " << course.courseNumber << endl;
				cout << "Course Name: " << course.courseName << endl;
				cout << "Course Prerequisites: " << course.coursePrereq << endl;
				cout << endl;
			}
			else {
				cout << "Course not found" << endl;
			}
			break;

		case '4':
			//Exit program
			cout << "Thank You! Goodbye!";
			break;

		default:
			cout << "Invalid input" << endl;
			break;
		}
	}
	return 0;
}