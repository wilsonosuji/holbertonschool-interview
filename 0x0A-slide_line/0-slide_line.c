#include "slide_line.h"
/**
 * slide_line -  reproduce the 2048 game mechanics on a single horizontal line.
 *
 * @line: Pointer to the array of integer to be printed
 * @size: Number of elements in the array
 * @direction: Represents the slided & merged to the right or left direction
 *
 * Return: 1 upon success, or 0 upon failure
 */
 int slide_line(int *line, size_t size, int direction)
 {
	 int i = 0, k = 0, size_n = size, data = 0;

	 if (line == NULL || (direction != 0 && direction != 1))
		 return (0);

	 if (direction == 0)
	 {
		 for (i = 0; i < size_n; i++)
		 {
			 if (line[i] == line[i + 1]  && line[i] != 0)
			 {
				 line[k++] = line[i] + line[i + 1], i++;
				 line[k] = 0;
			 }
			 else if (line[i] != 0)
			 {
				 if (data == line[i])
				 {
					 line[--k] = data * 2;
					 k++;
					 data = 0;
				 }
				 else
					 line[k++] = line[i], data = line[i];
			 }
		 }
		 for (i = k; i < size_n; i++)
			 line[i] = 0;
	 }
	 else
	 {
		 k = size - 1;
		 for (i = size_n - 1; i > -1; i--)
		 {
			 if (line[i] == line[i - 1]  && line[i] != 0)
			 {
				 line[k--] = line[i] + line[i - 1], i--;
				 line[k] = 0;
			 }
			 else if (line[i] != 0)
			 {
				 if (data == line[i])
				 {
					 line[++k] = data * 2;
					 k--;
					 data = 0;
				 }
				 else
					 line[k--] = line[i], data = line[i];
			 }
		 }
		 for (i = k; i > -1; i--)
			 line[i] = 0;
	 } return (1);
 }
