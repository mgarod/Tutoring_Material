/*
Author: Michael Garod
Date Created: 7/2/15
Description: A tutorial on how to build a function around the distance formula.
*/

#include <iostream>
#include <cmath>
using namespace std;

// Here is a more complex example of functions, where one will use the other.
// If you are unfamiliar with the distance formula: 
// http://cs.selu.edu/~rbyrd/math/distance/

double diffSquared(double left, double right);
double distanceFormula(double x1, double y1, double x2, double y2);

int main()
{
	// Once the function is complete, it is just a double, and cout knows
	// how to cout a double, so we can place the function call within cout.
	cout << "(8,4) and (7,2) is: " << distanceFormula(8, 4, 7, 2) << endl;
	cout << "(12.5,9) and (7.5,-3) is: "
			<< distanceFormula(12.5, 9, 7.5, -3) << endl;

	return 0;
}

double diffSquared(double left, double right)
{
	// This function does a small piece of the work for distanceFormula()
	return pow( (left-right), 2);

	/*
		pow(base, exponent) is a function from the <cmath> library.
		In human notation, it would be like writing base^(exponent).
	*/

	/*
		This function could have been written like this:
		int base = left - right;
		int answer = pow(base, 2);
		return answer;
	*/
}

double distanceFormula(double x1, double y1, double x2, double y2)
{
	// When diffSquared() is called, the logic will then jump to diffSquared()
	// to retrieve an answer. You may think of these nested function calls as
	// a placeholder for what the number will be when diffSquared() returns.
	return sqrt(diffSquared(x2,x1) + diffSquared(y2,y1));

	/*
		There is no need for any other logic or variables in this function.
		You could have done something like:
		
		int diff_of_x_sq = diffSquared(x2,x1);
		int diff_of_y_sq = diffSquared(y2,y1);
		int sum = diff_of_x_sq + diff_of_y_sq;
		int root_of_sum = sqrt(sum);
		return root_of_sum;

		There can be times where it is nice to be verbose about your work, but
		the same was achieved in a single line and is still readable.
	*/

	/*
		Alternately, the distanceFormula() could have been written as:

		return sqrt(pow(x2-x1,2) + pow(y2-y1,2));

		and foregoing diffSquared() altogether, but this was designed to show
		that you may chain together functions like Russian Matryoshka dolls.
	*/
}

