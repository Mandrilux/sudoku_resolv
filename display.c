#include "sudoku.h"

int	display_map(int **map)
{
  int   i;
  int   k;

  printf("|------------------|\n");
  i = 0;
  while (map[i] != NULL)
    {
      k = 0;
      printf("|");
      while (k < 9)
	{
	  printf(" %d", map[i][k]);
	  k++;
	}
      printf("|\n");
      i++;
    }
  printf("|------------------|\n");
  return (0);
}
