/*
Midterm review: Question 1(a)
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