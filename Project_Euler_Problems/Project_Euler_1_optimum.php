<?php
	/*
	Title: Project_Euler_1_optimum.php
	Author: Michael Garod
	Date Created: 7/19/15
	Problem: If we list all the natural numbers below 10 that are multiples of
		3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
		Find the sum of all the multiples of 3 or 5 below 1000.
	Note: This is the mathematical solution using the summation identity
		that the sum of the first N numbers = N*(N+1)/2 (in addition to the
		inclusion-exclusion principle). This is the optimal soltion because
		not a single loop was required.
	*/
	$start = microtime();
	
	$sum = 0;
	$max = 1000;

	function sumOfFirstN($n)
	{
		return ($n*($n+1))/2;
	}

	$threes = 3*sumOfFirstN( floor(($max-1) / 3));
	$fives = 5*sumOfFirstN( floor(($max-1) / 5));
	$fifteens = 15*sumOfFirstN( floor(($max-1)/ 15));

	$sum = $threes + $fives - $fifteens;

	echo "Time elapsed in milliseconds: ".(microtime()-$start)."\n";
	echo "$sum is the sum of multiples of 3 or 5 below 1000\n";
?>