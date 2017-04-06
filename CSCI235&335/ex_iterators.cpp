#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {

  vector<int> v;
  for (int i = 0; i < 5; ++i) {
    v.push_back(i*i); //
  }
  // v == [0, 1, 4, 9, 16]

  // Iterator is inner/nested class--A pointer to the internal structure
  vector<int>::iterator it;

  // begin() is a method that returns the iterator/pointer
  //  to the first element;
  it = v.begin();

  // end() is a method that returns the iterator/pointer
  //   to one position AFTER the last element
  vector<int>::iterator end = v.end();

  // Can loop using iterators rather than indexing, because not every data structure allows for direct indexing
  cout << "Looping: ";
  while (it != end) {
    cout << *it << " ";
    ++it; // Iterators can "advance" with the prefix ++operator
  }
  cout << endl;

  // Iterators are useful for finding, inserting and erasing in STL containers
  //  without having direct access to the internals of the data structure
  
  // Find the element equal to 16
  vector<int>::iterator p;
  for (p = v.begin(); p != v.end(); ++p) {
    if (*p == 16)
      break;
  }

  // Insert 12 before the item being pointed to by the iterator
  cout << "Insert 12 before 16: ";
  v.insert(p, 12);
  for (p = v.begin(); p != v.end(); ++p) {
    cout << *p << " ";
  }
  cout << endl;

  // Find the element equal to 4
  for (p = v.begin(); p != v.end(); ++p) {
    if (*p == 4)
      break;
  }

  // Erase the item pointed to by the iterator
  cout << "Erase 4: ";
  v.erase(p);
  for (p = v.begin(); p != v.end(); ++p) {
    cout << *p << " ";
  }
  cout << endl;

  // The <algorithm> library provides functions that work on STL
  //  collections regardless of what they are, or how they are
  //  implemented. These algorithms depend only on iterators that
  //  know how to traverse the structure.
  //  http://www.cplusplus.com/reference/algorithm/
  std::reverse(v.begin(), v.end());

  cout << "Reversed: ";
  for (p = v.begin(); p != v.end(); ++p) {
    cout << *p << " ";
  }
  cout << endl;

  std::sort(v.begin(), v.end());

  cout << "Sort: ";
  for (p = v.begin(); p != v.end(); ++p) {
    cout << *p << " ";
  }  
  cout << endl;

  return 0;
}