/*
	Title: infinity.cpp
	Author: Michael Garod
	Date Created: 12/12/15
	Description: A very small tutorial on how to make and use the idea of
		infinity as a variable.
*/
#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char** argv){
	// When you write INFINITY in all caps, you are calling a global value
	// cmath provides this value as well as some functions using INFINITY
	cout << "is INFINITY infinite?: " << isinf(INFINITY) << endl;
	
	cout << "now x is INFINITY" << endl;
	float x = INFINITY;

	cout << "is x infinite?: " << isinf(x) << endl;
	cout << "value of x?: " << x << endl;
	
	cout << "is 5 less than x?: " << (5 < x) << endl;
	cout << "is 5 greater than x?: " << (5 > x) << endl;

	return 0;
}