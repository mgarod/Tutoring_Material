#include <iostream>
using namespace std;

int iterative_fact(int input);
int recursive_fact(int input);

int main()
{

	cout << iterative_fact(5);
	cout << endl;
	cout << recursive_fact(5);

	return 0;
}

int iterative_fact(int input)
{
	int value = 1;
	while (input > 0)
	{
		value = value * input;
		input--;
	}
	return value;
}

int recursive_fact(int input)
{
	if (input == 0)
		return 1;
	else
		return input * recursive_fact(input-1);
}