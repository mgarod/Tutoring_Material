/*
Author: Michael Garod
Date Created: 6/23/15

Midterm Review: Question 6

Write a function makeStr(string str1, string str2, int i, int j) that returns a string that contains i occurrences of (the value of) str1 separated by a some sepa- rator, followed by a separator, followed by j occurrences of str2 (again, separated by some separator). The separator changes value, such that all occurrences of the separa- tor at odd positions produce ‘-’ (without quotes), and all even occurrences produce ‘+’ (without quotes).
For example,
(a) the function call makeStr("abc", "def", 2, 4) would return
"abc-abc+def-def+def-def". Note that there is no separator after the last “def”.
(b) the function call makeStr("abc", "def", 1, 6) would return "abc-def+def-def+def-def+def". Note that there is no separator after the last “def”.

For simplicity, assume i > 0, j > 0.
*/

#include <string>
#include <iostream>
using namespace std;

string makestr(string one, string two, int first, int second);

int main()
{
	cout << makestr("abc", "def", 2,4) << endl;
	cout << makestr("abc", "def", 1,6) << endl;
	return 0;
}

string makestr(string one, string two, int first, int second)
{
	string result;

	for (int i=1; i <= first+second; i++)
	{
		if (i <= first)
		{
			result += one;
		}
		else if (i <= first+second)
		{
			result += two;
		}

		if ((i % 2 == 1) && (i != first+second))
		{
			result += "-";
		}
		else if (i != first+second)
		{
			result += "+";
		}
	}

	return result;
}
