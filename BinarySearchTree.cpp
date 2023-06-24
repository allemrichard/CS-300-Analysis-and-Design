#include "BinarySearchTree.h"

// Default constructor
BinarySearchTree::BinarySearchTree() {
	root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {

	DeleteRecursive(root);

}

void BinarySearchTree::DeleteRecursive(Node* node) {
	if (node) {
		DeleteRecursive(node->left);
		DeleteRecursive(node->right);
		delete node;
	}
}

// Adding Nodes
void BinarySearchTree::addNode(Node* node, Course course) {

	// if node is larger, then add new one to the left
	if (node->course.courseNumber.compare(course.courseNumber) > 0) {

		// if no left node
		if (node->left == nullptr) {
			node->left = new Node(course);
		}
		else {
			this->addNode(node->left, course);
		}

	}
	// else node is smaller, then add new one to the right
	else {

		// if no right node
		if (node->right == nullptr) {
			node->right = new Node(course);
		}
		else {
			this->addNode(node->right, course);
		}
	}

}


// Printing out all the courses
void BinarySearchTree::inOrder(Node* node) {

	if (node != nullptr) {

		// Traverse to the left 
		inOrder(node->left);

		// Output course information
		cout << "Course Number: " << node->course.courseNumber << endl;
		cout << "Course Name: " << node->course.courseName << endl;
		cout << "Course Prerequisites: " << node->course.coursePrereq << endl;
		cout << endl;

		// Traverse to the right
		inOrder(node->right);
	}
}


void BinarySearchTree::InOrder() {

	this->inOrder(root);
}


// Inserting a course
void BinarySearchTree::Insert(Course course) {

	// if root is null, new node is the root
	if (root == nullptr) {
		root = new Node(course);
	}
	// else, add node to BST
	else {
		this->addNode(root, course);
	}
}


// Searching for a course
Course BinarySearchTree::Search(string courseNumber) {

	Course course;
	Node* currNode = root;

	while (currNode != nullptr) {
		if (currNode->course.courseNumber.compare(courseNumber) == 0) {		// Match found
			return currNode->course;
		}
		else if (currNode->course.courseNumber.compare(courseNumber) > 0) {		// Traverse to the left if it is smaller
			currNode = currNode->left;
		}
		else {
			currNode = currNode->right;			// Traverse to the right
		}
	}
	return course;
}

