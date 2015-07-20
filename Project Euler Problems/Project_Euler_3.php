<?php
	/*
	Title: Project_Euler_3.php
	Author: Michael Garod
	Date Created: 7/15/15
	Problem: The prime factors of 13195 are 5, 7, 13 and 29.
		What is the largest prime factor of the number 600851475143?
	Description: This solution relies on the Fundamental Theorem of
		Arithmetic. Because any number is merely the product of some number
		of primes, I can simply repeatedly divided the large prime by all
		smaller numbers (which will only ever be primes by happenstance).
		When all that remains of the large prime is equal to the next
		factor I attempt to divide, I have found the largest prime factor.
	Note: This was written in php so that I did not have to deal with
		integer sizes to store the large prime.
	*/
	$start = microtime();

	$prime = 600851475143;
	$originalprime = $prime; // for the purpose of printing the final message

	$factors = 2;	// $factors must begin with 2 to avoid an infinite loop

	while ($prime != $factors)	// Will stop before making $prime == 1
	{
		if ($prime % $factors == 0)
		{
			//echo "This factor is $factors\n";
			$prime /= $factors;
		}
		else
		{
			$factors++;
		}
	}

	echo "Time elapsed in milliseconds: ".(microtime()-$start)."\n";
	echo "$factors is the largest prime factor of $originalprime\n";

?>