/*
	Title: dereferencing.cpp
	Author: Michael Garod
	Date Created: 8/11/15
	Description: A tutorial on how to access object methods from a
		pointer and a double pointer in two different ways.
*/
#include <iostream>
using namespace std;

class Something{
public:
	void echo(){cout << "Hello World!\n";}
};

int main()
{
	// Object
	Something one;
	one.echo();

	// Single pointers
	Something* two = new Something;
	cout << "single pointer by * and .: "; (*two).echo();
	cout << "single pointer by ->: "; two->echo();


	// Double pointers
	Something** three = new Something*;
	(*three) = new Something;
	cout << "double pointer by * and .: "; (*(*three)).echo();
	cout << "double pointer by ->: "; (*three)->echo();

	return 0;
}