#include "sudoku.h"

int	present_row(t_pos pos, int **map, int nb)
{
  int	i;

  i = -1;
  while (++i < 9)
    {
      if (map[pos.y][i] == nb)
	return (1);
    }
  return (0);
}

int	present_collum(t_pos pos, int **map, int nb)
{
  int i;

  i = -1;
  while (map[++i] != NULL)
    {
      if (map[i][pos.x] == nb)
	return (1);
    }
  return (0);
}

int	present_carre(t_pos pos, int **map, int nb)
{
  int	i;
  int	z;

  i = -1;
  z = -1;
  pos.x = (pos.x / 3) * 3;
  pos.y = (pos.y / 3) * 3;
  while (++i < 3)
    {
      while (++z < 3)
	{
	  if (map[pos.y][pos.x] == nb)
	    return (1);
	  pos.x = pos.x + 1;
	}
      z = -1;
      pos.y = pos.y + 1;
      pos.x = pos.x - 3;
    }
  return (0);
}
