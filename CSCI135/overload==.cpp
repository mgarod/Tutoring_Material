/*
  Title: operator==.cpp
  Author: Michael Garod
  Date Created: 12/8/16
  Description: An example of how to overload operator== as a method in a
    nontrivial class structure.
*/

#include <iostream>
using namespace std;

struct Data {
  Data() { };
  int getVal() const { return *val; };
  void increment() { *val += 1; };
  void decrement() { *val -= 1; };
  int* val = new int(5);
};

class Sub {
 public:
  Sub() { };
  bool operator==(const Sub& rhs) { return getData() == rhs.getData(); };
  void increment() { data.increment(); };
  void decrement() { data.decrement(); };
  int getData() const { return data.getVal(); };
  void printData() { cout << data.getVal() << endl; };
 private:
  Data data;
};

class Super {
 public:
  Super() { };
  void incrementSecond() { B.increment(); };
  void decrementSecond() { B.decrement(); };
  bool checkEquality() { return A == B; };
 private:
  Sub A;
  Sub B;
};

int main() {
  Super super;
  cout << super.checkEquality() << endl;
  super.incrementSecond();
  cout << super.checkEquality() << endl;
  super.decrementSecond();
  cout << super.checkEquality() << endl;

  return 0;
}
