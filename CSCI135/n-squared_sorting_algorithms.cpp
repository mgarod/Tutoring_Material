/*
	Title: n-squared_sorting_algorithms.cpp
	Author: Michael Garod
	Date Created: 8/11/15
	Description: A file containing 3 implementations of O(n-squared) sorting
		algorithms.
	Note: I used std::swap(x, y) en lieu of using a third variable.
*/
#include <iostream>
using namespace std;

void printArray(int a[], int size)
{
	for (int i=0; i < size; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;
}

// Over-simplified Decription: Swap every adjacent items until we reach a
//	sorted array.
void bubbleSort(int array[], int size)
{
	for(int i=0; i < size; i++)
	{
		for (int j=i+1; j < size; j++)
		{
			if (array[j] < array[i])
			{
				swap(array[i], array[j]);
			}
		}
	}
}

// Over-simplified Decription: Find the smallest element. Put the smallest
//	element into the smallest position until we reach a sorted array.
void selectionSort(int array[], int size)
{
	for(int i=0; i < size; i++)
	{
		int minimum = array[i];
		int min_index = i;

		for (int j=i+1; j < size; j++)
		{
			if (array[j] < minimum)
			{
				minimum = array[j];
				min_index = j;
			}
		}

		swap(array[i], array[min_index]);
	}
}

// Over-simplified Decription: Hold the first item to be a sorted sub-array.
//	Iterate through the remaining items, and put the item into the proper
//	sorted position within the sub-array
void insertionSort(int array[], int size)
{
	int j;

	for(int i=1; i < size; i++)
	{
		int element = array[i];

		for (j=i; j > 0 && element < array[j-1]; j--)
		{
			array[j] = array[j-1];
		}

		array[j] = element;
	}
}

int main()
{
	int x[] = {4,-3,2,5,4,10,24,4,21,2,5,8,5};
	int size = 13;

	bubbleSort(x, size);
	printArray(x, size);
	
	int y[] = {4,-3,2,5,4,10,24,4,21,2,5,8,5};

	selectionSort(y, size);
	printArray(y, size);

	int z[] = {4,-3,2,5,4,10,24,4,21,2,5,8,5};

	insertionSort(z,size);
	printArray(z,size);
}