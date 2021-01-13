#include "holberton.h"

/**
 * _isdigit - checks if it is fully a number
 * @c: string to validate
 * Return: 1 if is digit otherwise 0
 */

int _isdigit(char *c)
{
	int i;

	for (i = 0; c[i] != '\0'; i++)
	{
		if (c[i] < '0' || c[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * _strlen - size of string
 * @s: string to measure
 * Return: size of string
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (*(s + i) != '\0')
		++i;
	return (i);
}

/**
 * main - program that multiplies two positive numbers
 *
 * @argc: argument counter
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int l1, l2, len, i, j, mul, carry;
	int *total;

	if (argc != 3 || !(_isdigit(argv[1])) || !(_isdigit(argv[2])))
	{
		puts("Error");
		exit(98);
	}
	if (atoi(argv[1]) == 0 || atoi(argv[2]) == 0)
		puts("0"), exit(0);
	l1 = _strlen(argv[1]), l2 = _strlen(argv[2]);
	len = l1 + l2;
	total = calloc(len, sizeof(int));
	if (total == NULL)
		puts("Error"), exit(98);
	for (i = l2 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = l1 - 1; j >= 0; j--)
		{
			mul = (argv[2][i] - '0') * (argv[1][j] - '0');
			carry = (mul / 10);
			total[(i + j) + 1] += (mul % 10);
			if (total[(i + j) + 1] > 9)
			{
				total[i + j] += total[(i + j) + 1] / 10;
				total[(i + j) + 1] = total[(i + j) + 1] % 10;
			}
			total[(i + j)] += carry;
		}
	}
	if (total[0] == 0)
		i = 1;
	else
		i = 0;
	for (; i < len; i++)
		printf("%d", total[i]);
	printf("\n");
	free(total);
	return (0);
}
