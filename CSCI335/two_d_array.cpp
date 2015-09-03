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
	cin >> rows;
	cin >> columns;

	int** two_d_array = new int*[rows];
	for (int i = 0; i < rows; i++ )
	{
		two_d_array[i] = new int[columns];
	}

	for (int i=0; i < rows; i++)
	{
		for (int j=0; j<columns; j++)
		{
			two_d_array[i][j]=i+j;
		}
	}

	for (int i=0; i < rows; i++)
	{
		for (int j=0; j<columns; j++)
		{
			cout << two_d_array[i][j] << " ";
		}
		cout << endl;
	}
}