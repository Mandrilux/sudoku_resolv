#include "sudoku.h"

int	usage(char *name)
{
  printf("usage : %s [map]\n", name);
  return (EXIT_SUCCESS);
}

int	recur_map(int **map, t_pos pos)
{
  int	i;

  i = 1;
  while (i < 10)
    {
      if (present_carre(pos, map, i) == 0
	  && present_collum(pos, map, i) == 0
	  && present_row(pos, map, i) == 0)
      	{
	  update_map(pos, map, i);
       	  if (fill_map(map) == 0)
	    return (0);
	  map[pos.y][pos.x] = 0;
	}
      i++;
    }
  return (-1);
}

int	fill_map(int **map)
{
  t_pos	pos;

  pos.y = 0;
  while (map[pos.y] != NULL)
    {
      pos.x = 0;
      while (pos.x < 9)
	{
	  if (map[pos.y][pos.x] == 0)
	    return (recur_map(map, pos));
	  pos.x++;
	}
      pos.y++;
    }
  return (0);
}

int	main(int ac, char **av)
{
  int	**map;

  map = NULL;
  if (ac != 1)
    return (usage(av[0]));
  if ((map = init()) == NULL)
    return (EXIT_FAILURE);
  parser(map);
  while (resolv(map) == 1);
  fill_map(map);
  display_map(map);
  return (EXIT_SUCCESS);
}
