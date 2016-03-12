"""
Title: Project_Euler_14.php
Author: Michael Garod
Date Created: 3/11/16
Problem: The following iterative sequence is defined for the set of positive
    integers:
        n → n/2 (n is even)
        n → 3n + 1 (n is odd)

    Using the rule above and starting with 13, we generate the following
    sequence:
    13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
    
    It can be seen that this sequence (starting at 13 and finishing at 1)
    contains 10 terms.

    Although it has not been proved yet (Collatz Problem), it is thought that
    all starting numbers finish at 1.

    Which starting number, under one million, produces the longest chain?
    (Once the chain starts the terms are allowed to go above one million.)

Note: This problem was given to me in an interview with 1010data
"""

def euler14():
    """
    Maintain a hashmap of { num : steps induced by num }

    Iterate through one million numbers; attempt the brute force.

    If a starting number ever brings you to a number you have already
    calculated, then the answer to that starting number is the sum of the
    steps you've taken on this sequence plus the steps of what you've
    calculated previously and saved in the map
    """
    hashmap = {1: 0}

    longest_chain = 0
    longest_original = 1

    for i in range(1,1000000):
        collatz(i, hashmap, i, 0)

        if hashmap[i] > longest_chain:
            longest_original = i
            longest_chain = hashmap[i]

    print "the longest chain is {}".format(longest_original)
    print "which produces {} steps".format(longest_chain)


def collatz(original, hmap, current, steps):
    if current in hmap:
        hmap[original] = hmap[current] + steps
    else:
        if current % 2 == 0:
            collatz(original, hmap, current/2, steps+1)
        else:
            collatz(original, hmap, (3*current)+1, steps+1)

euler14()
