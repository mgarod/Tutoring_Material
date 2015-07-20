<?php
	/*
	Title: Project_Euler_6.php
	Author: Michael Garod
	Date Created: 7/17/15
	Problem: The sum of the squares of the first ten natural numbers is
			1^2 + 2^2 + ... + 10^2 = 385
		The square of the sum of the first ten natural numbers is
			(1 + 2 + ... + 10)^2 = 55^2 = 3025
		Hence the difference between the sum of the squares of the first ten
		natural numbers and the square of the sum is 3025 − 385 = 2640.

		Find the difference between the sum of the squares of the first one
		hundred natural numbers and the square of the sum.
	Note: By using summation identities, you do not need to count or loop to
		find any numbers. The identities are a closed form solution.
	*/
	$start = microtime();
	$sum = 0;
	$numbers = 100;

	function sumOfSquares($n)
	{
		return (($n)*($n+1)*(2*$n+1) / 6);
	}

	function squareOfSum($n)
	{
		return pow(($n*($n+1)/2) , 2);
	}

	$diff = squareOfSum($numbers) - sumOfSquares($numbers);

	echo "Time elapsed in milliseconds: ".(microtime()-$start)."\n";
	echo "$diff is the difference between the sum of the squares and the \nsquare of the sum for the first $numbers natural numbers\n";

?>