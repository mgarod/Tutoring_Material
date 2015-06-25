#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int max;
	cin >> max;
	// Lower left triangle
	for (int i=0; i<5; i++)
	{
		for(int j=i; j<5; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	// Upper left triangle
	for (int i=5; i>0; i--)
	{	
		for (int j=i; j>0; j--)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	// Upper right triangle
	for (int i=5; i>0; i--)
	{
		for (int j=5-i; j>0; j--)
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
	for (int i=5; i>0; i--)
	{
		for (int j=i-1; j>0; j--)
		{
			cout << " ";
		}

		for (int k=5-i+1; k>0; k--)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;



	return 0;
}