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
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

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
	ParentID = gen_random();
	cout << ParentID << endl;
	system("pause");
	return 2;
}