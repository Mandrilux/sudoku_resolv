#include "sudoku.h"

int	check_enter(int **map, t_pos pos, int *place_one)
{
  int	last_nbr;
  int	nbr_solution;
  int	save_nbr;

  last_nbr = 0;
  nbr_solution = 0;
  save_nbr = 0;
  if (map[pos.y][pos.x] == 0)
    {
      while (++last_nbr < 10)
	{
	  if (present_carre(pos, map, last_nbr) == 0
	      && present_collum(pos, map, last_nbr) == 0
	      && present_row(pos, map, last_nbr) == 0)
	    {
	      nbr_solution++;
	      save_nbr = last_nbr;
	    }
	}
    }
  if (nbr_solution == 1)
    *place_one = 1;
  if (nbr_solution == 1)
    update_map(pos, map, save_nbr);
  return (save_nbr);
}

int	resolv(int **map)
{
  t_pos pos;
  int	place_one;

  if (map == NULL)
    return (-1);
  place_one = 0;
  pos.x = 0;
  pos.y = 0;
  while (map[pos.y] != NULL)
    {
      while (pos.x < 9)
	{
	  check_enter(map, pos, &place_one);
	  pos.x++;
	}
      pos.y++;
      pos.x = 0;
    }
  return (place_one);
}

void   update_map(t_pos pos, int **map, int nplace_one)
{
  map[pos.y][pos.x] = nplace_one;
}
