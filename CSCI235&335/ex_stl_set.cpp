#include <iostream>
#include <set>
using namespace std;

int main() {
  // "
  // http://cplusplus.com/reference/set/set

  // Sets are containers that store unique elements.
  // In a set, the key is the data being stored.
  // Data in a set cannot be modified (stored as const).
  
  // Sets are implemented as BSTs, therefore are stored in
  //  accordance to an ordering (by default operator<).
  // The ordering can be altered by implementing a comparator
  //  class and adding it to the set template.
  // More on Comparators (aka Functors):
  //  http://neutrofoton.github.io/blog/2016/12/30/c-plus-plus-set-with-custom-comparator/
  //  http://www.cprogramming.com/tutorial/functors-function-objects-in-c++.html

  // Sets are implemented with a self-balancing BST
  //  (can be an AVL Tree or Red-Black Tree).
  // This guarantees that the tree does not become unbalanced,
  //  affecting the complexity of its operations.

  // Sets are associative, meaning that elements are accessed by
  //  their key, and not by positions in the container (unlike vectors).
  // ";

  // Sets are instantiated with the data type it will hold
  set<int> s;
  
  cout << "s.empty(): " << s.empty() << endl; // true
  cout << "s.size(): " << s.size() << endl; // 0
  
  s.insert(10);
  s.insert(5);
  s.insert(3);
  s.insert(7);
  s.insert(15);
  s.insert(12);
  s.insert(17);

  //      10
  //     /  \
  //    5    15
  //   / \   / \
  //  2   7 12  17

  // Like all other STL containers, set implements iterators
  set<int>::iterator it;

  // Loop from "beginning" to "end" is the inorder traversal of the tree
  for (it = s.begin(); it != s.end(); ++it) {
    cout << "Printing: " << *it << endl;
  }
  
  // Finding something will return an iterator to the element itself
  if (s.find(17) == s.end())
    cout << "17 not found in the tree" << endl;
  else
    cout << "17 is in the tree" << endl; // this prints

  // Removing a node can trigger imbalances in the tree
  // The set will self-correct, and is abstracted away from the user
  
  // Erasing a value returns the number of elements removed (always 1)
  cout << "Erasing 17: " << s.erase(17) << endl; // 1
  cout << "Erasing 20: " << s.erase(20) << endl; // 0

  // Can also erase by an iterator, but has return type void
  // This will erase the minimum value (3)
  s.erase(s.begin()); 

  // Finding something not in the tree will return iterator to the end
  if (s.find(17) == s.end())
    cout << "17 not found in the tree" << endl; // this prints
  else
    cout << "17 is in the tree" << endl;
    
  // Many times we don't need an iterator to an element
  // Sometimes we just need to know if the element is in the set

  // We can use count as a simpler way to search the set
  // Count returns the number of items whose key is equal to K
  // Since a set never holds duplicates, a count of K will always
  //  return 0 or 1, which can be used as a boolean value
  cout << "Found 10: " << s.count(10) << endl;
  cout << "Found 88: " << s.count(88) << endl;

  // Clear will erase all the contents of the set
  s.clear();
}


// How is the iterator being implemented? This iterator must be able to
//  walk through the tree, and pause for the user to work on the data.

// This is an iterative inorder traversal using a stack data structure
// This allows the iterator to pause at each node, for the user to work
// with the node, and then continue on with the inorder traversal.
