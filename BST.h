//Chance McCormick, Carlton Wilcox, James Schuchardt
//COSC 2030
//Project 2 
//11/28/2018

#ifndef _BST_H_
#define _BST_H_

#include<iostream>
#include <string>
#include<vector>
#include<cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class BinSearchTree
{
private:
	struct node
	{
		//The node inside the binary tree
		string ID;
		string Parent_ID;
		string Raw_Event;
		string RHASH;
		string LHASH;
		vector<string> RHISTH;
		vector<string> LHISTH;
		//pointers to help us out
		node* left;
		node* right;
		node* parent;

	};
	//these pointers are what we use in the cpp to save our lives.
	node *root;
	node *self;
	node *parental;

public:
	//sets root and self to null
	BinSearchTree();

	node* RootNode();
	//creates node
	void createNode();
	//creates and organizes the details when making a new node
	void details();
	//Function displayLeft taken from Lab 8
	

	void printPreorder(struct node* root);

	void Update();

	void Record();

	void HashTableout(string in);

	void Display(struct node *root, int spacing);







};



#endif
