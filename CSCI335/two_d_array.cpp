/*
	Title: two_d_array.cpp
	Author: Michael Garod
	Date Created: 9/3/15
	Description: A tutorial on how to make and fill a two-d array
*/
#include <iostream>
using namespace std;

int main()
{
	size_t rows, columns;
	cout << "Input rows: ";
	cin >> rows;
	cout << "/nInput columns: ";
	cin >> columns;
	cout << "/n";

	// Initializing the matrix
	int** two_d_array = new int*[rows];
	for (int i = 0; i < rows; i++ )
	{
		two_d_array[i] = new int[columns];
	}

	// Filling the matrix
	for (int i=0; i < rows; i++)
	{
		for (int j=0; j<columns; j++)
		{
			two_d_array[i][j]=i+j;
		}
	}

	// Printing the matrix
	for (int i=0; i < rows; i++)
	{
		for (int j=0; j<columns; j++)
		{
			cout << two_d_array[i][j] << " ";
		}
		cout << endl;
	}
}