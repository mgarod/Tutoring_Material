/*
Author: Michael Garod
Date Created: 6/23/15

Midterm Review: Question 1(a)

Write a function doMult(int x, int y) that computes (and returns) the product of integers x and y without using the * (multiplication) operator or any other built- in functions (but you can use abs()). You may use + (addition) and the standard C++ control flow statements. Note that x and y can be positive or negative. Make sure your function can handle the size of the product of two integers.
*/

#include <iostream>
#include <cmath>
using namespace std;

int doMult(int x, int y);

int main()
{

	cout << doMult(2,10) << endl;
	cout << doMult(2,-10) << endl;
	cout << doMult(-2,10) << endl;
	cout << doMult(-2,-10) << endl;

	return 0;
}

int doMult(int x, int y)
{
	if (x == 0 || y == 0)
	{
		return 0;
	}

	int answer = 0;
	for (int i = abs(y); i > 0; i--)
	{ 
		answer += abs(x);
	}

	if ((x < 0 && y > 0) || (y < 0 && x > 0))
	{
		return -1*(answer);
	}

	return answer;
}