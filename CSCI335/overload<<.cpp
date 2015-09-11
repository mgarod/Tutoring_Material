/*
	Title: overload<<.cpp
	Author: Michael Garod
	Date Created: 9/2/15
	Description: A tutorial on how to overload the ostream and ofstream insertion operator (<<) for your class
	Credit to: https://msdn.microsoft.com/en-us/library/1z2f6c2k.aspx
*/
#include <iostream>
#include <fstream>
using namespace std;

template<class ItemType>
class Date
{
public:
	Date();
	Date(int d, int m, int y):day{d}, month{m}, year{y}{};
	void setItem(ItemType x){it = x;};

	friend ostream& operator<<(ostream& os, const Date& date);
	friend ofstream& operator<<(ofstream& ofs, const Date& date);
	// declaring friend allows the streams access to private members of Date
private:
	int day, month, year;
	ItemType it;
};

// Overloading for console output (cout)
template <class ItemType>
ostream& operator<<(ostream& os, const Date<ItemType>& date)
{
	os << "The date is: " << date.month << "/" << date.day << "/" << date.year;
	os << endl << date.it;
	return os;
}

// Overloading for file output (ofstream)
template <class ItemType>
ofstream& operator<<(ofstream& ofs, const Date<ItemType>& date)
{
	ofs << "The date is: " << date.month << "/" <<
		date.day << "/" << date.year;
	return ofs;
}

int main()
{
	Date<string> someDate(9,2,2015);
	someDate.setItem("hello world!");

	// Testing overload cout
	cout << someDate << endl;

	// Testing overload ofstream
	ofstream output("output.txt");
	output << someDate << endl;
	output.close();

	return 0;
}