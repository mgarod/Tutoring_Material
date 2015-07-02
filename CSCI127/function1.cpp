/*
Author: Michael Garod
Date Created: 7/2/15
Description: A tutorial on how to build a function around Perfect Numbers.
Purpose: CSCI 127/135 Tutoring Material
*/

#include <iostream>
using namespace std;

/*
	You must declare all functions you wish to use after includes/namespace
	and before your main. A function declarations consists of:
 
 	returnType functionName(any number of parameters and their names);

 	This declaration is a contract with the compiler. When this function is
 	called upon, you have an agreement that it will only take these
 	parameters, and will always give back some returnType.

	Just like on a physical calulator, you would press the sin button, then
	type in some number. The sin function expects a Real number, and will
	return to you a real number between -1 and 1. If you input sin(i), you
	have broken the contract with your calculator on what the sin function
	should be and you will receive an error. The same will happen here.
*/

bool isPerfect(int input);

int main()
{
	// Before learning functions, you would have done this;
	int x;
	int sum = 0;
	cout << "Input an integer and I will tell you if it's Perfect: \n";
	cin >> x;

	for (int i = 1; i < x; i++)
	{
		if (x % i == 0)
		{
			sum = sum + i;
		}
	}

	if (sum == x)
	{
		cout << "The number " << x << " is Perfect\n";
	}
	else
	{
		cout << "The number " << x << " is not Perfect\n";
	}

	cout << "Now we will do this with functions\n";
	// Every time you would want to determine a perfect number, you would
	// need to copy/paste this entire block or place it in a do-while loop.

	// With functions, you can place this previous code into one line
	// which allows for very simple use and re-use. To call the function,
	// just write the name and insert an argument. This is exactly the same
	// as if you were to use sin(60) on your calculator.

	isPerfect(6);
	isPerfect(326);
	isPerfect(788);
	isPerfect(8128);

	return 0;
}

/*
	Function definitions are placed after the end of main. All declared functions must have a definition.

	The function definition must look exactly like your previous declaration.
	Instead of placing a semicolon, you place curly brackets, and the logic
	to take place within them.

	On line 70, the function was called with the argument 788. The integer
	788	is passed into the function and is now renamed 'input' and the logic
	will proceed where input equals 788.
*/

bool isPerfect(int input)
{
	int sum = 0;

	// The cout/cin statements are no longer needed because we are already
	// given an integer called 'input' from the argument. Anywhere we had x,
	// we have changed the name to 'input'

//	cout << "Input an integer and I will tell you if it's Perfect: \n";
//	cin >> x;

	for (int i = 1; i < input; i++)
	{
		if (input % i == 0)
		{
			sum = sum + i;
		}
	}

	if (sum == input)
	{
		cout << "The number " << input << " is Perfect\n";
		// Once a function is complete, you must end the function by returning
		// what was contracted in the declaration, in this case a boolean value
		return true;
	}
	else
	{
		cout << "The number " << input << " is not Perfect\n";
		// Every single possible pathway that the function takes must end
		// by returning the contracted value
		return false;
	}
}