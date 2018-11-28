//Chance McCormick, Carlton, James
//COSC 2030 
//Project 2-Binary search tree and hash table
//11/27/2018
#ifndef _BST_H_
#define _BST_H_

#include<iostream>
#include <string>
#include<vector>
#include<cmath>
 
using std::cin;
using std::cout;
using std::endl;

/*
	void preorder(struct Node<T> *root)
	{
		preorder(root->left);
		preorder(root->right);

	}

}*/

class BinSearchTree
{
private:
	struct node
	{
		int key;
		node *left;
		node *right;

	};
	node *root;
	node *createLeaf(int key);
	void insertHelp(int key, node* Ptr);

public:
	int count=0;
	int base = 2;
	BinSearchTree();	//constructor prototype
	void addLeaf(int key);


};

#endif
