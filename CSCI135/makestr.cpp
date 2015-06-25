/*
Midterm Review: Question 6
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
