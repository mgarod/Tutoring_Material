<?php
	/*
	Title: Project_Euler_1_less_naive.php
	Author: Michael Garod
	Date Created: 7/19/15
	Problem: If we list all the natural numbers below 10 that are multiples of
		3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
		Find the sum of all the multiples of 3 or 5 below 1000.
	Note: This is the mathematical solution using the inclusion-exclusion
		principle.
	*/
	$start = microtime();
	
	$sum = 0;

	// Add all numbers that are multiples of 3
	for ($i = 0; $i < 1000; $i+=3)
	{
		$sum += $i;
	}

	// Add all numbers that are multiples of 5
	for ($i = 0; $i < 1000; $i+=5)
	{
		$sum += $i;
	}

	// Subtract all numbers that are multiples of 3 and 5 (15)
	// due to the inclusion-exclusion principle.
	for ($i = 0; $i < 1000; $i+=15)
	{
		$sum -= $i;
	}

	echo "Time elapsed in milliseconds: ".(microtime()-$start)."\n";
	echo "$sum is the sum of multiples of 3 or 5 below 1000\n";
?>