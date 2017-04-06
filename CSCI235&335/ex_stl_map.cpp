#include <iostream>
#include <map>
using namespace std;

int main() {  
  // "
  // http://cplusplus.com/reference/map/map

  // Maps are containers that store unique key/value pairs.
  // As opposed to sets, in a map the key and the value (data)
  //  are not (necessarily) equal.

  // Maps are also BSTs (usually AVL Tree or Red-Black Tree) that
  //  keep stored elements sorted by the key, not the value.

  // By default the sorting is maintained with operator< on the keys.
  // The comparison of keys can be modified by altering adding a
  //  comparator class to the map template.
  // More on Comparators (aka Functors):
  //  http://neutrofoton.github.io/blog/2016/12/30/c-plus-plus-set-with-custom-comparator/
  //  http://www.cprogramming.com/tutorial/functors-function-objects-in-c++.html

  // Maps are associative, that is their elements can be accessed by the key,
  //  and not their position in the data structure. This is simplified in
  //  maps by the use of the bracket operator (operator[]).
  // ";

  // Maps must be instantiated with the key type, and value type
  // We will map user_ids, to names
  map<int, string> m;
  
  cout << "m.empty(): " << m.empty() << endl; // true
  cout << "m.size(): " << m.size() << endl; // 0
  
  // To insert into a map, both the key and value are inserted as a pair
  // See: http://www.cplusplus.com/reference/utility/pair/
  m.insert(std::pair<int, string>(1, "Adam"));

  // The operator[] simplifies insertion
  // If no entry of this particular key exists in the map,
  //  one will be created with the given value;
  m[2] = "Britney";
  m[3] = "Charlie";
  m[4] = "Dana";
  m[5] = "Eric";
  m[6] = "Faye";
  m[7] = "Greg";

  // If the key already existed, then the value would be overwritten.
  m[2] = "Belinda";

  // The resulting tree is balanced
  //      4
  //     /  \
  //    2    6
  //   / \   / \
  //  1   3 5   7

  // Like all other STL containers, map implements iterators
  map<int, string>::iterator it;

  // This loop is the inorder traversal of the tree based on the keys
  for (it = m.begin(); it != m.end(); ++it) {
    // Entries in a map are pairs (simple data structures with 2 members)
    cout << "Printing: " << it->first << ", " << it->second << endl;
  }
  
  // Finding something will return an iterator to the element itself
  if (m.find(5) == m.end())
    cout << "id 5 not found in the tree" << endl;
  else
    cout << "id 5 is in the tree" << endl; // this prints

  // Erasing a value returns the number of elements removed (always 1)
  // Imbalances caused by removal are corrected internally
  cout << "Erasing id 17: " << m.erase(5) << endl; // 1
  cout << "Erasing id 20: " << m.erase(20) << endl; // 0

  // Can also erase by an iterator, but has return type void
  // This will erase the minimum value (3)
  m.erase(m.begin()); 

  // Finding something not in the tree will return iterator to the end
  if (m.find(5) == m.end())
    cout << "id 5 not found in the tree" << endl; // this prints
  else
    cout << "id 5 is in the tree" << endl;
    
  // Many times we don't need an iterator to an element
  // Sometimes we just need to know if the element is in the map

  // We can use count as a simpler way to search the map
  // Count returns the number of items whose key is equal to K
  // Since a map never holds duplicates, a count of K will always
  //  return 0 or 1, which can be used as a boolean value
  cout << "Found 7: " << m.count(7) << endl;
  cout << "Found 88: " << m.count(88) << endl;

  // Clear will erase all the contents of the map
  m.clear();
}

// How is the iterator being implemented? This iterator must be able to
//  walk through the tree, and pause for the user to work on the data.

// This is an iterative inorder traversal using a stack data structure
// This allows the iterator to pause at each node, for the user to work
// with the node, and then continue on with the inorder traversal.
