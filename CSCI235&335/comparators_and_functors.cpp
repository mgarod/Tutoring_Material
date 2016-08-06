/*
	Title: comparators_and_functors.cpp
	Author: Michael Garod
	Date Created: 8/6/16
	Description: A tutorial on how to define comparators which will allow you to
		fill STL containers with your user created classes. Similarly, I will
		demonstrate how to overload the std::hash function to hash user defined
		classes.
*/

#include <cstdlib>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

/*
	In this example, we will consider an internet connection. Any two computers running over the Internet Protocol (IP) will connect some IP address and port number, to another IP and port number. I recently had a work assignment that asked me, given a large list of internet connections (4-tuples), count the number of unique connections. We represent a single connection with this class, ConnectionTuple.
*/
class ConnectionTuple {
 public:
 	ConnectionTuple() : connections{0, 0, 0, 0} { };
 	ConnectionTuple(const u_int32_t& sip, const u_int16_t& sprt,
 									const u_int32_t& dip, const u_int16_t& dprt)
 		: connections{sip, sprt, dip, dprt} { };
 	inline u_int32_t getSrcIp() const { return std::get<0>(connections); };
 	inline u_int16_t getSrcPort() const { return std::get<1>(connections); };
 	inline u_int32_t getDestIp() const { return std::get<2>(connections); };
 	inline u_int16_t getDestPort() const { return std::get<3>(connections); };

 private:
 	std::tuple<u_int32_t, u_int16_t, u_int32_t, u_int16_t> connections;
};

// A refresher on how to overload a stream operator without the friend keyword
std::ostream& operator<<(std::ostream& os, ConnectionTuple ct) {
	os << "(" << ct.getSrcIp() << ", " << ct.getSrcPort();
	os << ", " << ct.getDestIp() << ", " << ct.getDestPort() << ")" << std::endl;
	return os;
}

/*
	To place these ConnectionTuples into std::set, we must define a comparator. A comparator is simply a class that will be passed to the container that has only one function, the overloaded operator(), that is, the parenthesis operator. When the container needs to observe two objects, it will call this class' operator() to get a bool about what to do with it.

	In the standard library, a set is ordered, therefore we must define a way to determine ordering of these ConnectionTuples. I use the less than operator on the integers within the objects. The std::set will also enforce uniqueness by computing !LessCmpCT(a,b) && !LessCmpCT(b,a).
*/ 
class LessCmpCT { // Less than operator to compare ConnectionTuple
 public:
 	bool operator()(const ConnectionTuple& a, const ConnectionTuple& b) const noexcept {
 		return ((a.getSrcIp() < b.getSrcIp()) &&
 				    (a.getSrcPort() < b.getSrcPort()) &&
 				    (a.getDestIp() < b.getDestIp()) &&
 				    (a.getDestPort() < b.getDestPort()));
 	}
};

/*
	For unordered STL containers like std::unordered_set and std::unordered_map, we will define a comparator which can simply determine uniqueness. Two connections are unique if and only if each of the 4 numbers in the 4-tuple are equal.
*/
class EqCmpCT {
 public:
 	bool operator()(const ConnectionTuple& a, const ConnectionTuple& b) const noexcept {
 		return ((a.getSrcIp() == b.getSrcIp()) &&
 				    (a.getSrcPort() == b.getSrcPort()) &&
 				    (a.getDestIp() == b.getDestIp()) &&
 				    (a.getDestPort() == b.getDestPort()));
 	}
};

/*
	If we wish to use ConnectionTuple as a key in std::unordered_map, then we must define a hash. Rather than making a hash functor, I will overload the std::hash, so that in the future, we can always hash Connection Tuple.
*/
namespace std {
template<>
struct hash<ConnectionTuple> {
	size_t operator()(const ConnectionTuple& ct) const noexcept {
		size_t key = 1;
		std::hash<u_int32_t> h32;
		std::hash<u_int16_t> h16;
		key = (97*key) + h32(ct.getSrcIp());
		key = (97*key) + h16(ct.getSrcPort());
		key = (97*key) + h32(ct.getDestIp());
		key = (97*key) + h16(ct.getDestPort());
		return key;
	}
};
}

int main (int argc, char* argv[])
{
	std::cout << "Let's make some ConnectionTuple objects, where 2 are duplicates" << std::endl;
	ConnectionTuple a(1,2,3,4);
	ConnectionTuple b(3,4,5,6);
	ConnectionTuple c(2,3,4,5);
	ConnectionTuple d(1,2,3,4); // duplicate
	ConnectionTuple e(2,3,4,5); // duplicate

	std::cout << a << b << c << d << e;
	std::cout << std::endl;
	std::cout << "Let's try out our Equality Comparator" << std::endl;
	std::cout << "a==b? " << EqCmpCT()(a,b) << std::endl; // 0
	std::cout << "a==d? " << EqCmpCT()(a,d) << std::endl; // 1
	std::cout << "c==d? " << EqCmpCT()(c,d) << std::endl; // 0
	std::cout << "c==e? " << EqCmpCT()(c,e) << std::endl; // 1
	std::cout << "We see that inserting D and E into a set will fail";
	std::cout << std::endl << std::endl;

	std::cout << "Inserting a, b, c, d, and e into std::set with LessCmpCT" << std::endl;
	std::set<ConnectionTuple, LessCmpCT> set;
	set.insert(a);
	std::cout << "set size after insert a: " << set.size() << std::endl; // 1
	set.insert(b);
	std::cout << "set size after insert b: " << set.size() << std::endl; // 2
	set.insert(c);
	std::cout << "set size after insert c: " << set.size() << std::endl; // 3
	set.insert(d);
	std::cout << "set size after insert d: " << set.size() << std::endl; // 3
	set.insert(e);
	std::cout << "set size after insert e: " << set.size() << std::endl; // 3
	std::cout << std::endl;

	std::cout << "Inserting a, b, c, d, and e into std::unordered_set with EqCmpCT" << std::endl;
	std::unordered_set<ConnectionTuple, std::hash<ConnectionTuple>, EqCmpCT> u_set;
	u_set.insert(a);
	std::cout << "u_set size after insert a: " << u_set.size() << std::endl; // 1
	u_set.insert(b);
	std::cout << "u_set size after insert b: " << u_set.size() << std::endl; // 2
	u_set.insert(c);
	std::cout << "u_set size after insert c: " << u_set.size() << std::endl; // 3
	u_set.insert(d);
	std::cout << "u_set size after insert d: " << u_set.size() << std::endl; // 3
	u_set.insert(e);
	std::cout << "u_set size after insert e: " << u_set.size() << std::endl; // 3
	std::cout << std::endl;

	std::cout << "Let's try out our hash function" << std::endl;
	std::hash<ConnectionTuple> hf;
	std::cout << hf(a) << std::endl; // 89461067
	std::cout << hf(b) << std::endl; // 91305427
	std::cout << hf(c) << std::endl; // 90383247
	std::cout << hf(d) << std::endl; // 89461067 duplicate
	std::cout << hf(e) << std::endl; // 91305427 duplicate
	std::cout << std::endl;

	std::cout << "Inserting a, b, c, d, and e into std::unordered_map with hash overload and EqCmpCT" << std::endl;
	std::unordered_map<ConnectionTuple, char,
										 std::hash<ConnectionTuple>, EqCmpCT> u_map;

	u_map[a] = 'a';
	auto it = u_map.find(a);
	std::cout << "u_map[a] -> ";
	it == u_map.end() ? std::cout << "n/a" : std::cout << it->second; // a
	std::cout << std::endl;
	
	u_map[b] = 'b';
	it = u_map.find(b);
	std::cout << "u_map[b] -> ";
	it == u_map.end() ? std::cout << "n/a" : std::cout << it->second; // b
	std::cout << std::endl;
	
	u_map[c] = 'c';
	it = u_map.find(c);
	std::cout << "u_map[c] -> ";
	it == u_map.end() ? std::cout << "n/a" : std::cout << it->second; // c
	std::cout << std::endl;
	
	u_map[d] = 'd';
	it = u_map.find(d);
	std::cout << "u_map[d] -> ";
	it == u_map.end() ? std::cout << "n/a" : std::cout << it->second; // d
	std::cout << std::endl;
	
	u_map[e] = 'e';
	it = u_map.find(e);
	std::cout << "u_map[e] -> ";
	it == u_map.end() ? std::cout << "n/a" : std::cout << it->second; // e
	std::cout << std::endl << std::endl;


	std::cout << "What happened to the originals, a and c?" << std::endl;
	std::cout << "u_map[a] -> ";
	it = u_map.find(a);
	it == u_map.end() ? std::cout << "n/a" : std::cout << it->second; // d
	std::cout << std::endl;

	it = u_map.find(c);
	std::cout << "u_map[c] -> ";
	it == u_map.end() ? std::cout << "n/a" : std::cout << it->second; // e
	std::cout << std::endl;

	std::cout << "Since d and e were the equivalent of a and c, they overwrote a and c. Be careful!" << std::endl;

  return 0;
}