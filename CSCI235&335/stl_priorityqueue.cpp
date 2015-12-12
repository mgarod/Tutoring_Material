/*
	Title: stl_priorityqueue.cpp
	Author: Michael Garod
	Date Created: 12/12/15
	Description: A tutorial on how to use std::priority_queue with user defined
		class. Queueing a struct instead of a class would be easier. There would be no need for getters and setters (see line 33 and 41 to see
		the difference).
*/
#include <iostream>
#include <queue>
using namespace std;

// If we had struct class, this would be easier because members are public
class Vertex{
	public:
		//friend struct VertexMinHeap;
		friend struct VertexMaxHeap;
		void SetValue(int x) { value = x; };
		const int GetValue() const { return value; };
	private:
		int value;
};

// For simplicity of printing this user defined structure
ostream& operator<<(ostream& os, const Vertex& v){
	os << v.GetValue();
	return os;
}

// Note that we want a min heap, but use the greater than operator
struct VertexMinHeap{
	bool operator()(const Vertex& a, const Vertex& b){
		return a.GetValue() > b.GetValue();
	}
};

// Note that we want a max heap, but use the less than operator
// Since we have declared friendship with class Vertex, no need for getters
struct VertexMaxHeap{
	bool operator()(const Vertex& a, const Vertex& b){
		return a.value < b.value;
	}
};

int main(int argc, char** argv){
	// Make some toy values to insert
	Vertex x, y, z;
	x.SetValue(5);
	y.SetValue(3);
	z.SetValue(1);

	// Create a PQ object with the following settings:
	// <(object to store), (internal data structure), (comparator)>
	priority_queue<Vertex, vector<Vertex>, VertexMinHeap> apq;

	cout << "The following 3 lines are the top of the MIN heap:\n";
	apq.push(x); // Push 5
	cout << "Push: " << x.GetValue() << " Top: " << apq.top() << endl; // 5 on top

	apq.push(z); // 
	cout << "Push: " << z.GetValue() << " Top: " << apq.top() << endl; // 1 on top

	apq.push(y);
	cout << "Push: " << y.GetValue() << " Top: " << apq.top() << endl; // 1 on still top


	priority_queue<Vertex, vector<Vertex>, VertexMaxHeap> bpq;

	cout << "The following 3 lines are the top of the MAX heap:\n";
	bpq.push(z); // Push 1
	cout << "Push: " << z.GetValue() << " Top: " << bpq.top() << endl; // 1 is on top

	bpq.push(x); // Push 5
	cout << "Push: " << x.GetValue() << " Top: " << bpq.top() << endl; // 5 on top

	bpq.push(y); // Push 3
	cout << "Push: " << y.GetValue() << " Top: " << bpq.top() << endl; // 5 still on top
	
	return 0;
}