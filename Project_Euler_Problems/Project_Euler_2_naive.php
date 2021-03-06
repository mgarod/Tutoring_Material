<?php
	/*
	Title: Project_Euler_2_naive.php
	Author: Michael Garod
	Date Created: 7/17/15
	Problem: Each new term in the Fibonacci sequence is generated by adding
		the previous two terms. By starting with 1 and 2, the first 10 terms
		will be: 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

	By considering the terms in the Fibonacci sequence whose values do not
		exceed four million, find the sum of the even-valued terms.
	Note: This is a naive, brute force solution.
	*/
	$start = microtime();
	$num1 = 1;
	$num2 = 2;
	$sum = 0;
	while ($num2 < 4000000)
	{
		if($num2 % 2 == 0)
		{
			$sum += $num2;
		}

		$num2 += $num1;
		$num1 = $num2 - $num1;
	}

	echo "Time elapsed in milliseconds: ".(microtime()-$start)."\n";
	echo "$sum is the sum of the even termed fibonacci numbers below 4mil\n";

?>