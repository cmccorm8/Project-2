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


char input;
BinSearchTree Tester;

int main()
{
	bool check = true;

	while (check)
	{
		cout << "\nPlease make a selection." << endl;

		cout << "\n1. Add a new Node." << endl;
		cout << "\n2. See record pertaining to ID." << endl;
		cout << "\n3. Update the contents of a node." << endl;
		cout << "\n4. Visualize the tree (ID Vals)." << endl;
		cout << "\n'E' or 'Exit': To Quit" << endl;
		cin >> input;

		

		switch (input)
		{
		case '1':
			//Inputs the root node
			Tester.createNode();

			break;

		case '2':
			cout << "Please enter the ID of the record you wish to see: ";
			break;
		case '3':
			Tester.Update();
			break;
		case '4':
			Tester.printPreorder(Tester.RootNode());
		
			break;


		case 'E':
			check = false;

		}
	}



	system("pause");
	return 0;
}

//Things remaining to implement:

//
//Get printing function to display in a tree like way
//display record function finished - pretty much done
//