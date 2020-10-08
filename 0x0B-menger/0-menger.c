#include "menger.h"

/**
 * menger - Function that draws a 2D Menger Sponge
 * @level: Level of the Menger Sponge to draw
 * Return: None
 */
void menger(int level)
{
	int i, j, limit;

	if (level < 0)
		return;

	for (i = 0, limit = pow(3, level); i < limit; i++)
	{
		for (j = 0; j < limit; j++)
		{
			if (firstLevel(i, j) == 1)
			{
				printf("%c", '#');
			}
			else
				printf("%c", ' ');
		}
		printf("\n");
	}
}

/**
 * firstLevel - Validate first level, level 1
 * @i: Position in the row
 * @j: Position in the column
 * Return: 1 when sponge is a 1, 0 otherwise
 */
int firstLevel(int i, int j)
{
	while (i != 0 && j != 0)
	{
		if (i % 3 == 1 && j % 3 == 1)
			return (0);
		i /= 3, j /= 3;
	}
	return (1);
}
