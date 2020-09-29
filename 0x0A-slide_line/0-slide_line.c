#include "slide_line.h"
/**
 * merge - Function that merges an array of integers reproducing
 *	   the 2048 game mechanics on a single horizontal line.
 * @line: Points to an array of integers containing size elements, that
 *		  must be slided & merged to the direction represented by direction
 * @direction: Helps identify left or right move
 * @check: Current value of line beign checked
 * @initial_val: First value of line left or right
 * @actual_val: Current mergeable value
 * @actual_id: idx of current
 * @qty_zeros: how many spaces can a value move
 */
void merge(int *line, int direction, int check, int initial_val,
	int *actual_val, int *actual_id, int *qty_zeros)
{

	if (line[check] == 0)
	{
		*qty_zeros += 1;
	}

	if (check == initial_val && line[check] != 0)
	{
		*actual_val = line[check];
		*actual_id = check;
	}

	if (line[check] != 0 && line[check] == *actual_val && check != initial_val)
	{
		line[*actual_id] += line[check];
		line[check] = 0;
		*actual_val = 0;
		*qty_zeros += 1;
	}

	if (line[check] != 0 && *actual_val != line[check] && check != initial_val)
	{
		line[check - (*qty_zeros * direction)] = line[check];
		*actual_val = line[check];
		*actual_id = check - (*qty_zeros * direction);
		if (*qty_zeros)
			line[check] = 0;
	}
}
/**
 * slide_line - Function that slides an array of integers reproducing
 *				the 2048 game mechanics on a single horizontal line.
 * @line: Points to an array of integers containing size elements, that
 *		  must be slided & merged to the direction represented by direction
 * @size: Number of elements
 * @direction: Can be either SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	int check, direction_mov, actual_val, actual_id, qty_zeros, initial_val;
	int sizeX = (int) size;

	if (!line || (direction != 0 && direction != 1))
		return (0);
	actual_val = 0;
	qty_zeros = 0;
	if (direction == 0)
		direction_mov = 1;
	else
		direction_mov = -1;
	if (direction == 0)
	{
		for (check = initial_val = actual_id =  0; check < sizeX; check++)
		{
			merge(line, direction_mov, check, initial_val,
				&actual_val, &actual_id, &qty_zeros);

		}
	}
	else
	{
		for (check = initial_val = actual_id = sizeX - 1; check >= 0; check--)
		{
			merge(line, direction_mov, check, initial_val,
				&actual_val, &actual_id, &qty_zeros);
		}
	}
	return (1);
}
