#include "sudoku.h"

int	**init()
{
  int	i;
  int	**map;

  i = -1;
  map = NULL;
  if ((map = malloc(sizeof(int *) * 10)) == NULL)
    return (NULL);
  while (++i < 9)
    {
      if ((map[i] = malloc(sizeof(int) * 9)) == NULL)
	return (NULL);
    }
  map[i] = NULL;
  memset_map(map);
  return (map);
}

int	memset_map(int **map)
{
  int	i;
  int	k;

  i = -1;
  k = -1;
  while (map[++i] != NULL)
    {
      while (++k < 9)
	map[i][k] = 0;
      k = -1;
    }
  return (0);
}
