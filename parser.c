#include "sudoku.h"

int	inside_parser(char *tmp, int **map, int z)
{
  int	i;
  int	k;

  k = 0;
  i = 0;
  tmp = &tmp[1];
  while (i < 18)
    {
      if (i % 2 != 0)
	{
	  if (tmp[i] != ' ')
	    map[z][k] = tmp[i] - '0';
	  k++;
	}
      i++;
    }
  return (0);
}

int	parser(int **map)
{
  char	*tmp;
  int	z;
  int	stop;

  z = -1;
  stop = 0;
  while (stop == 0)
    {
      tmp = get_next_line(0);
      if (tmp != NULL && is_num(tmp) == 1)
	inside_parser(tmp, map, z);
      else if (tmp == NULL)
	stop = 1;
      if (tmp != NULL)
	free(tmp);
      z++;
    }
  return (0);
}

int	is_num(char *buff)
{
  int	i;

  i = -1;
  while (buff[++i] != '\0')
    {
      if (buff[i] >= '1' && buff[i] <= '9')
	return (1);
    }
  return (0);
}
