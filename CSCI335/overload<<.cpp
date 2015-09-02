/*
	Title: overload<<.cpp
	Author: Michael Garod
	Date Created: 9/2/15
	Description: A tutorial on how to overload the ostream insertion
		operator (<<) for your class
*/
#include <iostream>
#include <fstream>
using namespace std;

class Date
{
public:
	Date();
	Date(int d, int m, int y):day{d}, month{m}, year{y}{};
	friend ostream& operator<<(ostream& os, const Date& date);
	friend ofstream& operator<<(ofstream& ofs, const Date& date);
	// declaring friend allows the ostream access to private members
private:
	int day, month, year;
};

ostream& operator<<(ostream& os, const Date& date)
{
	os << "The date is: " << date.month << "/" << date.day << "/" << date.year;
	return os;
}

ofstream& operator<<(ofstream& ofs, const Date& date)
{
	ofs << "The date is: " << date.month << "/" <<
		date.day << "/" << date.year;
	return ofs;
}

int main()
{
	Date someDate(9,2,2015);
	cout << someDate << endl;

	ofstream output("output.txt");

	output << someDate << endl;

	output.close();

	return 0;
}