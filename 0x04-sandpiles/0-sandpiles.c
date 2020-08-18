#include "sandpiles.h"

/**
 * print_grid - prints a 3x3 sandpile grid
 * @grid: Grid to print
 */
void print_grid(int grid[3][3])
{
	int row, col;

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
			if (col < 2)
				printf("%d ", grid[row][col]);
			else
				printf("%d", grid[row][col]);
		printf("\n");
	}
}

/**
 * topple - topple each pile of the Sandpile
 * @grid: grid to change
 * @row: row to topple
 * @col: col to topple
 */
void topple(int grid[3][3], int row, int col)
{
	grid[row][col] -= 4;
	if (row > 0)
		grid[row - 1][col] += 1;
	if (row < 2)
		grid[row + 1][col] += 1;
	if (col > 0)
		grid[row][col - 1] += 1;
	if (col < 2)
		grid[row][col + 1] += 1;
}

/**
 * sandpiles_sum - function that computes the sum of two sandpiles
 * @grid1: Sandpile 1
 * @grid2: Sandpile 2
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int chekc = 1, row, col;

	for (row = 0; row < 3; row++)
		for (col = 0; col < 3; col++)
			grid1[row][col] += grid2[row][col];
	while (chekc)
	{
		for (row = 0; row < 3; row++)
			for (col = 0; col < 3; col++)
				grid2[row][col] = grid1[row][col];
		chekc = 0;
		for (row = 0; row < 3; row++)
			for (col = 0; col < 3; col++)
				if (grid2[row][col] > 3)
				{
					topple(grid1, row, col);
					chekc = 1;
				}
		if (chekc)
		{
			printf("=\n");
			print_grid(grid2);
		}
	}
}
