<?php
	/*
	Title: Project_Euler_1_naive.php
	Author: Michael Garod
	Date Created: 7/17/15
	Problem: If we list all the natural numbers below 10 that are multiples of
		3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
		Find the sum of all the multiples of 3 or 5 below 1000.
	Note: This is the naive solution.
	*/
	$start = microtime();
	$sum = 0;

	for($i = 0; $i < 1000; $i++)
	{
		if(($i % 3 == 0) || ($i % 5 == 0))
		{
			$sum += $i;
		}
	}

	echo "Time elapsed in milliseconds: ".(microtime()-$start)."\n";
	echo "$sum is the sum of multiples of 3 or 5 below 1000\n";

?>