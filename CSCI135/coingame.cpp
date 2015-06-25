/*
Review Midterm 1: Question 12

The player starts with a score of 0. In each round, she flips both coins, and receives points according to the following criteria:

Two Heads: 5 // One Head, One Tail: 3 // Two Tails: 1

The game stops when the total score of all rounds is at least X, where X is a value decided independently. The player then records the number of rounds it took to reach this score. You have to write a function coinGame(int X) that simulates this game. It has one parameter X, which corresponds to the score X that decides when the game stops. This function should return the number of rounds that the game went on for.

You may assume srand(time(0)) has already been called in your program.

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int coinGame(int x);

int main()
{
	srand(time(NULL));
	cout << coinGame(10) << " rounds to beat the game" << endl;

	return 0;
}

int coinGame(int x)
{
	int score = 0;
	int rounds = 0;
	cout << "GAME ENDS AT: " << x << endl;
	
	// The game stops when the total score of all rounds is at least x
	while (score < x)
	{
		// 0 = tails, 1 = heads
		int coin1, coin2;
		coin1 = rand() % 2;
		coin2 = rand() % 2;

		cout << "Current score: " << score << endl;
		cout << "round: " << rounds << " ";
		cout << "coin1: " << coin1 << " coin2: ";
		cout << coin2 << endl;

		if(coin1+coin2 == 0)
		{	// 2 tails
			score = score + 1;
		}
		else if(coin1+coin2 == 1)
		{	// 1 head, 1 tail
			score = score + 3;
		}
		else // if (coin1+coin2 == 2)
		{	// 2 heads
			score = score + 5;
		}
		rounds++;
	}
	return rounds;
}