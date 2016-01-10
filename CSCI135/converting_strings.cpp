/*
	Title: converting_strings.cpp
	Author: Michael Garod
	Date Created: 1/10/16
	Description: This tutorial contains two functions--
		1) stringtodouble() converts a given string of a number, into a double.
		2) decToHex() converts an integer into a hexadecimal as a string.
*/

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

// Precondition: str only contain '.' and numeric characters
double stringtodouble(string str){
	double intpart = 0;
	int dotpos=0;

	for (int i=0; i < str.length(); i++){
		
		if(str[i] != '.'){
			double x = (str[i] - 48);
			intpart = 10 * intpart + x;
		}
		else{
			dotpos = str.find('.') + 1;
		}
	}

	double result = intpart / pow(10,dotpos);

	return result;
}

string decToHex(int x){
	string str = "";

	while (x > 0){
		int n = (x % 16);
		char c;
		if (n > 9){
			c = n - 10 + 'A';
		}
		else{
			c = n + '0';
		}

		x /= 16;

		str = c + str;
	}

	return str;
}

int main(int argc, char** argv){

	string s = "7345329.18009324";

	cout << "string s = " << s << endl;
	double d = stringtodouble(s);
	cout << "string s converted to a double = ";
	cout << setprecision(15) << d << endl;

	cout << "2394 converted into Hex = " << decToHex(2394) << endl;
	cout << "(9 * 16^2) + (5 * 16^1) + (10 * 16^0) = " << (9 * 16*16) + (5 * 16) + (10) << endl;

	return 0;
}