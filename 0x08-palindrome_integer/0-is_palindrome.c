#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"
/**
 * is_palindrome - checks whether or not a given unsigned integer is palindrome
 * @n: is the number to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long t = n, r = 0;
	int palindrome;

	palindrome = recursion(n, t, r);
	return (palindrome);
}
/**
 * recursion - verify with recursion if the unsigned integer is palindrome
 * @n: is the number to be checked
 * @t: number of digits to be checked
 * @r: invert the number to be validated
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int recursion(unsigned long n, unsigned long t, unsigned long r)
{
	if (t != 0)
	{
		r = r * 10;
		r = r + t % 10;
		t = t / 10;

		if (recursion(n, t, r))
		{
			return (1);
		}
		return (0);
	}

	if (n == r)
	{
		return (1);
	}
	return (0);
}
