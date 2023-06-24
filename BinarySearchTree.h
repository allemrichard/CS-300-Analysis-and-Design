#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Course Data structure
struct Course {
	string courseNumber;
	string courseName;
	string coursePrereq;
};


// Node Data Structure
struct Node {
	Course course;
	Node* left;
	Node* right;

	Node() {
		left = nullptr;
		right = nullptr;
	}

	Node(Course aCourse) : Node() {
		course = aCourse;
	}

};
class BinarySearchTree {
private:
	Node* root;
	void addNode(Node* node, Course course);
	void inOrder(Node* node);


public:
	BinarySearchTree();
	virtual ~BinarySearchTree();
	void DeleteRecursive(Node* node);
	void InOrder();
	void Insert(Course course);
	Course Search(string courseNumber);
};


