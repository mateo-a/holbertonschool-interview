#include "regex.h"

/**
 * _com - compares string
 * @s1: string 1
 * @s2: string 2
 * @wild: wildcard flag
 *
 * Return: 1 if true otherwise 0
 */

int _com(char const *s1, char const *s2, int wild)
{
	if (wild == 1)
	{
		if (s2[0] == '*')
			return (_com(s1, s2 + 1, 1));
		else if (s1[0] == s2[0])
			return (_com(s1, s2, 0));
		else if (s1[0] != '\0')
			return (_com(s1 + 1, s2, 1));
		else
			return (0);
	}
	else
	{
		if (s1[0] == '\0' && s2[0] == '\0')
			return (1);
		else if (s1[0] == s2[0])
		{
			if (_com(s1 + 1, s2 + 1, 0))
			{
				return (_com(s1 + 1, s2 + 1, 0));
			}
		}
		else if (s2[0] == '.' && s1[0] != '\0')
			return (_com(s1 + 1, s2 + 1, 0));
		else if (s2[0] == '*')
			return (_com(s1, s2, 1));
		else
			return (0);
	}
	return (0);
}

/**
 * regex_match - checks whether a given pattern matches a given string.
 * @str: string
 * @pattern: pattern
 *
 * Return: 1 if the pattern matches the string, or 0 if it doesn’t
 */

int regex_match(char const *str, char const *pattern)
{
	return (_com(str, pattern, 0));
}
