/*******************************************************************
* Name: 
* Date: 1/9/10
* Course: CSCI 132
* Assignment: Assignment 9
* Instructor: Royden or King
* Program: test_tree.cc
* Purpose:  Program to test binary tree functions
***************************************************************************/
#include <iostream>
#include "binary_tree.h"
#include "binary_tree.cc"

using namespace std;

void print(int &my_data) {
	cout << my_data << " ";
} //print

int main(void) {
	Binary_tree<int> my_tree;
	
	cout << "Creating first test tree." << endl;
	for (int i = 1; i <= 20; i++) 
		my_tree.insert(i);
	
	cout << "The tree in preorder is: " << endl;
	my_tree.preorder(print);
	cout << endl;
	cout << "The tree in inorder is: " << endl;
	my_tree.inorder(print);
	cout << endl;
	cout << "The tree in postorder is: " << endl;
	my_tree.postorder(print);
	cout << endl;
	cout << "The size of the tree is " << my_tree.size() << endl;
	my_tree.clear();
	cout << "After clearing, the size of the tree is " << my_tree.size() << endl;
	cout << endl << "Creating second test tree." << endl;
	my_tree.insert(5);
	my_tree.insert(2);
	my_tree.insert(7);
	my_tree.insert(6);
	my_tree.insert(8);
	my_tree.insert(1);
	my_tree.insert(3);
	my_tree.insert(4);
	my_tree.insert(9);
	my_tree.insert(10);
	
	cout << "The tree in preorder is: " << endl;
	my_tree.preorder(print);
	cout << endl;
	cout << "The tree in inorder is: " << endl;
	my_tree.inorder(print);
	cout << endl;
	cout << "The tree in postorder is: " << endl;
	my_tree.postorder(print);
	cout << endl;
	cout << "The size of the tree is " << my_tree.size() << endl;
	my_tree.clear();
	cout << "After clearing, the size of the tree is " << my_tree.size() << endl;
} //end main
