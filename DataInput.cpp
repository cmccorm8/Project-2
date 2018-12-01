//Chance McCormick, Carlton Wilcox, James Schuchardt
//COSC 2030
//Project 2 
//11/28/2018

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "BST.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

BinSearchTree Tester;

int main()
{
	//Inputs the root node
	Tester.createNode();
	//Inputs the second node in the tree (this shoud end up being the left or right of the one above with null being produced on the other one.)
	Tester.createNode();
	system("pause");
	return 2;
}