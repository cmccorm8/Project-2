//Chance McCormick, Carlton, James
//COSC 2030
//Project 2 
//11/28/2018

#include "BST.h"


BinSearchTree::BinSearchTree()
{
	root = NULL;
}

BinSearchTree::node* BinSearchTree::createLeaf(int key)
{
	node *n = new node;
	n->key = key;		// sets key inside of node(n->key)equal to
	n->left = NULL;					//key passed in by function
	n->right = NULL;

	return n;
}

void BinSearchTree::insertHelp(int key, node * Ptr)
{
	for (count; count <= pow(base, count); count++) // should create 2 new leaves based on the current count ex: 2^0 would result in 1 new node/root
	{												//2^4 should result in 16 new nodes/ a complete tree that grows 1 complete level at a time
		if (root == NULL)	//checks to see if tree is empty
		{
			root = createLeaf(key);		// if so creates a new node at the root
		}
		else if (key < Ptr->key)   // checks to see if the key we want to add is less than 
		{							//the key currently in the node
			if (Ptr->left != NULL)  //checks the currents nodes left ptr to see if not empty
			{
				insertHelp(key, Ptr->left); // traverses down the left ptr until the left ptr is not pointing to something
			}
			else
			{
				Ptr->left = createLeaf(key);  // creates a new leaf an points Ptr->left to the new node
			}
		}
		else if (key >= Ptr->key)   // checks to see if the key we want to add is greater than or equal
		{							//the key currently in the node
			if (Ptr->right != NULL)  //checks the currents nodes right ptr to see if not empty
			{
				insertHelp(key, Ptr->right); // traverses down the right ptr until the right ptr is not pointing to something
			}
			else
			{
				Ptr->right = createLeaf(key);  // creates a new leaf an points Ptr->right to the new node
			}
		}
	}
}

void BinSearchTree::addLeaf(int key)
{
	insertHelp(key, root);
}



