#include <iostream>
using namespace std;

class Animal {
 public:
 	Animal(string s) { name = s; };
	virtual void speak() = 0;
	virtual void walk() = 0;
	virtual void rollover() = 0;
	string getName() { return name; };
 protected:
 	string name;
};

class Dog : public Animal {
 public:
	Dog(string s) : Animal(s) { };
	void speak() { cout << "woof!" << endl; };
	void walk() {	cout << "dogwalk" << endl; };
	void rollover() {	cout << "dogrollover" << endl; };
};

class Cat : public Animal {
 public:
	Cat(string s) : Animal(s) { };
	void speak() { cout << "meow!" << endl; };
	void walk() {	cout << "catwalk" << endl; };
	void rollover() {	cout << "cats dont roll over" << endl; };
};

int main() {
	Dog odie("odie");
	Cat garfield("garfield");

	odie.rollover();
	garfield.rollover();
}