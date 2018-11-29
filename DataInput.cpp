#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

string gen_random()
{
	string final;
	string temp;
	string holder =
		"0123456789AaBbCcDdEeFfGgHhIjJiKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";

	for (int i = 0; i < 8; i++) 
	{
		temp = holder[rand() % (sizeof(holder))];
		final.append(temp);
	}
	return final;

}

int main()
{
	string ParentID;
	string Second;
	string Second1;
	string Second2;
	string Second3;
	ParentID = gen_random();
	cout << ParentID << endl;
	Second = gen_random();
	cout << Second << endl;

	Second1 = gen_random();
	cout << Second1 << endl;
	Second2 = gen_random();
	cout << Second2 << endl;
	Second3 = gen_random();
	cout << Second3 << endl;
	system("pause");
	return 2;
}