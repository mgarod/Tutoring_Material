<?php
	/*
	Title: Project_Euler_5.php
	Author: Michael Garod
	Date Created: 7/17/15
	Problem: 2520 is the smallest number that can be divided by each of the
		numbers from 1 to 10 without any remainder.
		What is the smallest positive number that is evenly divisible by all
		of the numbers from 1 to 20?
	Description: If $factor divides $product, then you don't have to deal
		withit, so move to the next factor. If $factor doesn't divide
		$product, then naively you might incorporate it to the product, but in
		the case of $factor=4, you will be checking against $product=6. If you
		multiply $product*=4, then 4 will indeed divide 24, but $product*=2
		would be 12, which is divisible by 4. In this fashion we check all
		smaller numbers to the smallest number we can incorporate to satisfy
		the divisibility.
	Note: This was written in php so that I did not have to deal with
		integer sizes to store the large prime.
	*/
	$start = microtime();
	$product = 1;
	$factor = 1;
	$first_N_numbers = 20;

	while ($factor <= $first_N_numbers)
	{
		if ($product % $factor != 0)
		{
			// $factor doesn't divide product so check if there is a smaller
			// factor to satisfy the condition, if not then $factor is prime
			// and $i will equal $factor when the loop terminates.
			for ($i = 2; $i <= $factor; $i++)
			{
				if(($product * $i) % $factor == 0)
				{	
					// As soon as you find a smaller factor, stop and move on
					$product *= $i;
					break;
				}
			}
		}
		else //if ($product % $factor == 0)
		{
			// then $factor already divides $product, do nothing
			$factor++;
		}
	}

	echo "Time elapsed in milliseconds: ".(microtime()-$start)."\n";
	echo "$product is the product of the first $first_N_numbers\n";
?>