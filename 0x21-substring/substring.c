#include "substring.h"

/**
 * find_substring - finds all the possible substrings containing a list of
 *                  words, within a given string.
 * @s: string to scan
 * @words: array of words all substrings must be a concatenation arrangement of
 *         nb_words
 * @nb_words: number of elements in the array words
 * @n: holds the address at which to store the number of elements in the
 *      returned array.
 * Return: an allocated array, storing each index in s, at which a
 * substring was found. If no solution is found, NULL can be returned
 */

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	char *temp = NULL, *p = NULL;
	int _strLen, _regWrdLen, i, j, k, _dicLen = 0, count = 0;
	int *_pPos = NULL;

	_strLen = strlen(s);
	_regWrdLen = strlen(words[0]);
	_dicLen = _regWrdLen * nb_words;
	temp = calloc((_dicLen + 1), sizeof(char));
	_pPos = calloc((_strLen + 1), sizeof(char));
	for (i = 0; i <= _strLen - _dicLen;)
	{
		strncpy(temp, &s[i], _dicLen);
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < _dicLen;)
			{
				p = strstr(temp + k, words[j]);
				if (p != NULL && ((p - temp) % _regWrdLen) == 0)
					break;
				else if (p != NULL)
				{
					k = p - temp + 1;
					p = NULL;
				}
				else if (p == NULL)
					goto nextseg;
			}
			if (p != NULL)
				memset(p, '.', _regWrdLen);
			else
				goto nextseg;
		}
		if (_strLen != 0 && _dicLen != 0)
			_pPos[count++] = i;
nextseg:
		i++;
	}
	free(temp);
	*n = count;
	return (_pPos);
}
