#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

// Precondition: n is non-negative
int fib(int n) {
  if (n < 0) {
    throw invalid_argument("Cannot compute fibonnaci of a negative number");
  } else if (n <= 1) {
    return 1;
  } else {
    return fib(n-2) + fib(n-1);  
  }  
}

int main() {
  // If we call fib(-5) directly, the program will crash
  
  /* Try-Catch Blocks

    The Try block will execute all code that may contain an exception
    Normally, when an exception is thrown the program terminates immediately
    The Catch block will catch an exception of some type, without terminating. Then, some code can be executed using the execption that was caught.
  */  
  try {
    cout << "fib(-5): " << fib(-5) << endl;
  } catch (const invalid_argument& ia) {
    cout << ia.what() << endl;
  }

  // stoi(string s) will convert some string into the integer it represents
  // stoi will throw invalid_argument exception
  try {
    int n = stoi("500");
    cout << n << endl;
    n = stoi("hello");
    cout << n;
  } catch (const invalid_argument& ia) {
    cout << ia.what() << endl;
  }

  // vector<T>::at will check bounds, unlike operator[] which can cause undefined behavior if the parameter is out of bounds
  // If the argument is out of bounds, vector<T>::at will throw an out_of_range exception
  vector<int> myvector(10); // vector of size 10, of 10 garbage ints
  try {
    myvector.at(20) = 100;
  } catch (const out_of_range& oor) {
    cout << "Out of range error: " << oor.what() << '\n';
  } catch (const exception& e) {
    // A try-catch block can catch multiple exceptions
    // If you don't know what kind of exception will be thrown, then you can simply catch exception, which is the parent of all exceptions
    cout << "Exception caught: " << e.what() << '\n';
  }

  // Due to the inheritance relationships of exceptions, specialized exceptions need to be caught first.
  // If the previous two catches were reversed, then out_of_range block would never execute under any circumstance
  
  return 0;
}