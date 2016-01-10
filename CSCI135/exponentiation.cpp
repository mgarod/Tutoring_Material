/*
	Title: exponentiation.cpp
	Author: Michael Garod
	Date Created: 1/10/16
	Description: This tutorial describes an algorithm to optimize
		exponentiation better than iterative multiplication.
*/

#include <iostream>
#include <cmath>
using namespace std;

int exponentiation(int base, int exponent);

int main(int argc, char** argv){
	cout << "pow(2,6) = " << pow(2,6) << endl;
	cout << "exponentiation(2,6) = " << exponentiation(2,6) << endl;;
	cout << endl;

	cout << "pow(5,2) = " << pow(5,2) << endl;
	cout << "exponentiation(5,2) = " << exponentiation(5,2) << endl;;
	cout << endl;

	cout << "pow(6,3) = " << pow(6,3) << endl;
	cout << "exponentiation(6,3) = " << exponentiation(6,3) << endl;;
	cout << endl;

	cout << "pow(3,5) = " << pow(3,5) << endl;
	cout << "exponentiation(3,5) = " << exponentiation(3,5) << endl;;
	cout << endl;

	cout << "pow(9,6) = " << pow(9,6) << endl;
	cout << "exponentiation(9,6) = " << exponentiation(9,6) << endl;;
	cout << endl;

	return 0;
}

int exponentiation(int base, int exponent){
	if (base == 0){
		return 0;
	}
	if (exponent == 0){
		return 1;
	}

	int e = 1;
	int answer = base;

	// First Loop:
	// Starting at 1, we double until it would exceed the exponent
	// Doubling the exponent is the same as squaring the base.
	while (e*2 < exponent){
		answer *= answer;
		e *= 2;
	}

	// Second Loop:
	// If we can't double any more, then multiply by the base until
	//	we reach exponent.
	while (e < exponent){
		answer *= base;
		e++;
	}

	return answer;
}

/*
	The advantage of this algorithm is that it is O(log n), rather
	than iterative multiplication which would be O(n).

	For example, if we had 2^10 the loops are as follows;
	Before Loop:
		e == 1
		answer == 2
	------------------
	First Loop 1:
		e == 2
		answer == 4
	First Loop 2:
		e == 4
		answer == 16
	First Loop 3:
		e == 8
		answer == 256
	------------------
	Second Loop 1:
		e == 9
		answer == 512
	Second Loop
		e == 10
		answer == 1024
		
	return answer!
*/