/*
	Title: returning_void.cpp
	Author: Michael Garod
	Date Created: 8/26/15
	Description: A tutorial on a common error with void functions
*/

#include <iostream>
using namespace std;

void foo() { cout << "Hello World!\n" };

int main(){

// Can you spot the error?

cout << "Before food()\n" << foo() << " After foo()\n";

/*
  When this is run you will get pages on pages of error messages.
  You probably won't be able to decipher the error messages, but
  you should be able to pick out the line of the error (at the very
  start of the error message) and that the error derives from 
  ostream class, or operator<<, and cannot convert argument
  of type 'void' to some other type. Don't worry about the rest of
  the error messages, because they are pointing to elements in the
  iostream libraries that are causing the error, which you can't
  change anyway.
  
  The real problem is that 'cout' does not know how to represent
  foo() as text in the console because foo() is returning void.
  Rhetorical: How do you represent 'nothing' as text?
  
  The solution here is to either remove foo() from the cout
  statement, or change foo() to return a value that cout
  knows how to handle (i.e. a primative data type, or the more
  advanced, overloading operator<< to handle a structure you've
  built).
*/

  return 0;
}
