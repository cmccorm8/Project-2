//Chance McCormick, Carlton Wilcox, James Schuchardt
//COSC 2030
//Project 2 
//11/28/2018

#include "BST.h"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <functional>

using std::cin;
using std::cout;
using std::endl;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::hash;

vector<string> Lefty;
vector<string> Righty;

//The Search tree starts with not knowing what the root is and not knowing what its self is
BinSearchTree::BinSearchTree()
{
	root = NULL;
	self = NULL;
}

//Creates the next Node in the BST, however, if they tree is empty it will create the first node.
void BinSearchTree::createNode()
{
	//Looks to see if when we make a new node if the self pointer has been previously modified. Chooses route based on that.
	//we set the self pointer as well to the new node created either way
	node *n = new node;
	if (self != NULL)
	{
	//in this one the parent gets set to the current node and then changes the self over to the new node. allowing for access the parent node and 
	//the newest nose. The Left and right I am using for LHASH and RHASH, i just don't know how yet.
	
	n->parent = self;
	self = n;
	parental = n->parent;
	details();
	n->right = NULL; 
	n->left = NULL;
	
	
	}
	else
	{
		//we set the root as this will be the first node, left and right will be null, the parent is null and that determines
		//the route that the details() function will go.
		root = n;
		self = n;
		n->left = NULL;
		n->right = NULL;
		n->parent = NULL;
		details();
	}

}
//Details is a function that determines several things by first asking for an Event, and then:
//If this is the first node: It finds a random string to put as the parent to the root being made. It then creates the self ID based on the event 
//that the user inputs and the randomized string.
//
//If this is the any other node: It finds what the parent string is and It then creates the self ID based on the event 
//that the user inputs.
void BinSearchTree::details()
{
	if (self->parent != NULL)
	{
		//This is when the root node has already been created~~~~~
		string holder;
		string MakeID;
		hash<string> hasher;

		//Asks for a raw event and stores it in the node
		cout << "Please Enter a Raw Event for us to worry about: ";
		cin >> holder;
		cout << endl;
		cout << "Event: " << holder << endl;
		self->Raw_Event = holder;

		//////////////////////////////////Seperator///////////////////////////////////////
		
		//Accesses the parent node and gathers its ID to then store in the new node. 
		self->Parent_ID = (self->parent)->ID;
		//Combines the Raw_Event and the Parent_ID and then hashes out the self->ID;
		string storage;
		storage.append(holder);
		storage.append((self->Parent_ID));
		cout << "ParentID: " << self->Parent_ID << endl;
		cout << "Before New Hash: " << storage << endl;
		//Hash Code: Hashes it, and then rehashes based on some rules i made up until we have a total of 8 characters 
		//as currently the hash function being used on prints out only one character before the if&else statements were introduced
		MakeID = hasher(storage);
		while (MakeID.length() < 8)
		{
			string falseword = MakeID;
			if (holder.length() > 1)
			{

				falseword.pop_back();
				string supertemp;
				supertemp = hasher(falseword);
				MakeID.append(supertemp);
			}
			else
			{
				MakeID.append(falseword);
				string supertemp2;
				supertemp2 = hasher(falseword);
				MakeID.append(supertemp2);
			}
		}
		
		MakeID = MakeID.substr(0, 8);
		cout << "Hashed ID: " << MakeID << endl; 
		self->ID = MakeID;         

		/////Left and Right Hash Storage//////
		self->LHASH = "NULL";
		self->RHASH = "NULL";
		////Parents////
		

		if (parental->ID <= self->ID) //if parent ID is less than the new nodes ID then new node goes to the right
		{
			parental->LHASH = "NULL";
			parental->RHASH = self->ID;
			Righty.push_back(parental->RHASH);
		}
		else
		{
			
				parental->RHASH = "NULL";
				parental->LHASH = self->ID;
				Lefty.push_back(parental->LHASH);
		}

		cout << "Parent LHASH: " << parental->LHASH << endl;
		cout << "Parent RHASH: " << parental->RHASH << endl;

		Lefty.push_back(self->LHASH);
		Righty.push_back(self->RHASH);

		
		cout << "LHISTH: ";
		for (int i = 0; i < Lefty.size(); i++)
		{
			cout << Lefty[i] << " + ";
			(self->LHISTH).push_back(Lefty[i]);
		}
		cout << endl << "RHISTH: ";
		for (int i = 0; i < Righty.size(); i++)
		{
			cout << Righty[i] << " + ";
			(self->RHISTH).push_back(Righty[i]);
		}
		cout << endl;

		//////////////////////////////////Seperator///////////////////////////////////////
	}
	else
	{
		string holder;
		string MakeID;
		hash<string> hasher;
		string hashtype;


		cout << "Please Enter a Raw Event for us to worry about: ";
		cin >> holder;
		cout << endl;
		cout << "Event: " << holder << endl;
		self->Raw_Event = holder;

		//////////////////////////////////Seperator///////////////////////////////////////

		string final;
		string temp;
		string container =
			"0123456789AaBbCcDdEeFfGgHhIjJiKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";

		for (int i = 0; i < 8; i++)
		{
			temp = container[rand() % (sizeof(container))];
			final.append(temp);
		}
		self->Parent_ID = final;
		cout << "ParentID: " << final << endl;

		//////////////////////////////////Seperator///////////////////////////////////////

		hashtype.append(holder);
		hashtype.append(final);
		cout << "Before Hash: " << hashtype << endl;
		//Hash Code: Hashes it, and then rehashes based on some rules i made up until we have a total of 8 characters 
		//as currently the hash function being used on prints out only one character before the if&else statements were introduced
		MakeID = hasher(hashtype);
		while (MakeID.length() < 8)
		{
			string falseword = MakeID;
			if (holder.length() > 1)
			{

				falseword.pop_back();
				string supertemp;
				supertemp = hasher(falseword);
				MakeID.append(supertemp);
			}
			else
			{
				MakeID.append(falseword);
				string supertemp2;
				supertemp2 = hasher(falseword);
				MakeID.append(supertemp2);
			}
		}

		
		MakeID = MakeID.substr(0, 8);
		cout << "Hashed ID: " << MakeID << endl; 
		/////////////Left and Right Hashes////////////////
		self->ID = MakeID;
		self->LHASH = "NULL"; 
		cout << "LHASH: " << self->LHASH << endl;
		self->RHASH = "NULL";
		cout << "RHASH: " << self->RHASH << endl;

		Lefty.push_back(self->LHASH);
		Righty.push_back(self->RHASH);

	//	parental->LHISTH = Lefty;
	//	parental->RHISTH = Righty;
	//	self->LHISTH = Lefty;
	//	self->RHISTH = Righty;

		cout << "LHISTH: ";
		for (int i = 0; i < Lefty.size(); i++)
		{
			cout << Lefty[i] << "  ";
		}
		cout << "RHISTH: ";
		for (int i = 0; i < Righty.size(); i++)
		{
			cout << Righty[i] << "  ";
		}
		cout << endl;
	

//////////////////////////////Seperator///////////////////////////////////////
	}
	//Things remaining to implement:

	//self->RHASH;
	//self->LHASH;
	//self->RHISTH;
	//self->LHISTH; //vector that stores rawevents
}
