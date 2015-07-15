/*
	Author: Michael Garod
	Date Created: 6/30/15
	Desciption: CSCI 127 Homework #2

		Write a program that calculates the Hamming distance between two
	segments of DNA.
		You can model a segment of a strand of DNA as a string (or an array of
	characters) consisiting of the letters C,A,G, and T. Your program should
	prompt the user for two strings to compare, make sure the input strings
	are valid, and then output the Hamming distance. If an input string is not
	valid, your program should allow the user to re-enter it until it is valid.
	
	Note: If one string is longer than the other by X, then the hamming distance
	between the strings is at least X. When length of S1 is 5 and length of S2 is
	3, then the hamming distance is at least 2, and you will compare the remaining
	3 leftmost characters.
	
	Tricky Concepts: Input Validation, Returning a Boolean Value
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

bool verify(string input);
int hamming(string one, string two);

int main()
{
	string str1, str2;

	do
	{
	cout << "Input string #1 of only A,C,T,G: " << endl;
	cin >> str1;
	} while(!verify(str1));

	do
	{
	cout << "Input string #2 of only A,C,T,G: " << endl;
	cin >> str2;
	} while(!verify(str2));

	cout << "The hamming distance of these is: " << hamming(str1, str2);
	cout << endl;

	return 0;
}

bool verify(string input)
{
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] != 'A' &&
			input[i] != 'C' &&
			input[i] != 'T' &&
			input[i] != 'G' )
		{
			cout << "The input string is invalid!" << endl;
			return false;
		}
	}

	return true;
}

int hamming(string one, string two)
{
	// When one string is longer, the surplus length is always added to dist
	int dist = max(one.length(), two.length()) -
				min(one.length(), two.length());
	
	// Only compare characters up to the length of the smallest one
	int smallest = min(one.length(), two.length());

	for (int i = 0; i < smallest; i++)
	{
		if (one[i] != two[i])
		{
			dist++;
		}
	}
	
	return dist;
}
