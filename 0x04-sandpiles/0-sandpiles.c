#include "sandpiles.h"
/**
 * print_grid - print the result of the grid
 * @grid: bidimensional array
 *
 * Return: void statement
 **/
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: bidimentional array x
 * @grid2: bidimentional array y
 *
 * Return: Void function
 **/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int x = 0, y = 0, status;

	while (1)
	{
		for (x = 0; x < 3; x++)
		{
			for (y = 0; y < 3; y++)
			{
				grid1[x][y] = grid1[x][y] + grid2[x][y], grid2[x][y] = 0;
			}
		}
		status = valid(grid1);
		if (status)
		{
			printf("=\n");
			print_grid(grid1);
			path_grid(grid1, grid2);
		}
		else
			break;
	}
}
/**
 * path_grid - make the sanpiles stable
 * @grid1: bidimentional array x
 * @grid2: bidimentional array y
 *
 * Return: void statement
 **/
void path_grid(int grid1[3][3], int grid2[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid1[x][y] >= 4)
			{
				grid1[x][y] = grid1[x][y] - 4;
				if ((x + 1 >= 0) && (x + 1 < 3))
					grid2[x + 1][y]++;
				if ((x + 1 >= 0) && (x - 1 < 3))
					grid2[x - 1][y]++;
				if ((y + 1 >= 0) && (y + 1 < 3))
					grid2[x][y + 1]++;
				if ((y - 1 >= 0) && (y - 1 < 3))
					grid2[x][y - 1]++;
			}
		}
	}
}
/**
 * valid - make the sanpiles stable
 * @grid: bidimentional array
 *
 * Return: 1 if is higher than 4 or 0 if not
 **/
int valid(int grid[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid[x][y] >= 4)
			{
				return (1);
			}
		}
	}
	return (0);
}
