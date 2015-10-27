/*
	Title: string_breaking.cpp
	Author: Michael Garod
	Date Created: 10/27/15
	Description: One of many ways to break a sentence into multiple words.
	This is a very naive way to do this. A better implementation would use
	stringstreams from the standard library.
*/

#include <iostream>
using namespace std;

int main(){

string sentence = "the man and the woman";
string word1, word2, word3;

cout << sentence << endl;

bool done = false;
unsigned i = 0;

// Get the first word in the sentence. This is done by extracting character, by
//	character and putting into word1. The boolean condition ensures that we
//	stop after pulling out the first word.
for (i; i < sentence.length() && !done; ++i)
{
	if(sentence[i] != ' ')
	{
		word1 = word1 + sentence[i];
		sentence[i] = ' ';
	}
	else if (sentence[i] == ' ')
	{
		done = true;
	}
}

// Get the second word. We must reset the boolean to capture the second word.
done = false;
for (i; i < sentence.length() && !done; ++i)
{
	if(sentence[i] != ' ')
	{
		word2 = word2 + sentence[i];
		sentence[i] = ' ';
	}
	else if (sentence[i] == ' ')
	{
		done = true;
	}
}

// Get the third word.
done = false;
for (i; i < sentence.length() && !done; ++i)
{
	if(sentence[i] != ' ')
	{
		word3 = word3 + sentence[i];
		sentence[i] = ' ';
	}
	else if (sentence[i] == ' ')
	{
		done = true;
	}
}

cout << word1 << " " << word2 << " " << word3 << endl;

}