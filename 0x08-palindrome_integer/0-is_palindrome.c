#include "palindrome.h"

/**
  * backward - function to backwards the given number
  * @num: Allocated backward number
  * @n: Given number
  * Return: None
  */
void backward(unsigned long *num, unsigned long n)
{
	if (n > 0)
	{
		*num = *num * 10 + (n % 10);
		n /= 10;
		backward(num, n);
	}
}

/**
 * is_palindrome - function that checks whether or not a given unsigned integer
 * is a palindrome.
 * @n: Given number
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long num = 0;

	backward(&num, n);
	if (n != num)
		return (0);
	else
		return (1);
}

