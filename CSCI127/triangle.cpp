/*
Author: Michael Garod
Date Created: 6/25/15
Description: Draw 4 right triangles (90 degree rotations) of an input size.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int max;
	cout << "Input the side length of the triangle: ";
	cin >> max;
	cout << endl;

	// Lower left triangle
	for (int i=0; i<max; i++)
	{
		for(int j=0; j<=i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	// Upper left triangle
	for (int i=max; i>0; i--)
	{	
		for (int j=i; j>0; j--)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	// Upper right triangle
	for (int i=max; i>0; i--)
	{
		for (int j=max-i; j>0; j--)
		{
			cout << " ";
		}

		for (int k=i; k>0; k--)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	// Lower right triangle
	for (int i=max; i>0; i--)
	{
		for (int j=i-1; j>0; j--)
		{
			cout << " ";
		}

		for (int k=max-i+1; k>0; k--)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	return 0;
}