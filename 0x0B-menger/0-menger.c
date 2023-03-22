#include "menger.h"
/**
 * Space - Checks if a cell is a space
 * @row: row index
 * @col: col index
 *
 * Return: 1 if cell is a space, 0 otherwise.
 */

int Space(int row, int col)
{
	while (col && row)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (1);
		row = row / 3, col = col / 3;
	}
	return (0);
}

/**
 * menger - Print the 2D menger sponge
 *
 * @level: level of the Menger Sponge to draw
 */
void menger(int level)
{
	int i, j;
	int dim = pow(3, level);

	for (i = 0; i < dim; i++)
	{
		for (j = 0; j < dim; j++)
		{
			if (Space(i, j))
				printf(" ");
			else
				printf("#");
		}
		puts("");
	}
}
