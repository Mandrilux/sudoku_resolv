#include "sudoku.h"

int	utils_functions(char *str, char c, int size)
{
  int	i;

  i = 0;
  if (size == -1)
    {
      while (str != NULL && str[i] != '\0')
	i++;
      return (i);
    }
  else
    {
      while (i < size)
	{
	  str[i] = c;
	  i++;
	}
    }
  return (0);
}

char	*assign_buff(char *str_tmp, char *buff, int i, int state)
{
  int	j;
  int	k;
  int	size;
  char	*str;

  size = 0;
  if (state == 0)
    size = utils_functions(str_tmp, 0, -1) + READ_SIZE + 1;
  else if (state == 1)
    size = utils_functions(str_tmp, 0, -1) + i + 1;
  str = malloc(sizeof(char) * size);
  if (str == NULL)
    return (NULL);
  utils_functions(str, 0, size);
  j = -1;
  while (++j < utils_functions(str_tmp, 0, -1))
    str[j] = str_tmp[j];
  if (state == 0)
    size = READ_SIZE;
  else if (state == 1)
    size = i;
  k = 0;
  while (k < size)
    str[j++] = buff[k++];
  return (str);
}

char    *everything_line(char *buff, char *str_tmp, int i, int j)
{
  char  *str;
  int   k;

  if (j == -1)
    str = assign_buff(str_tmp, buff, 0, 0);
  else if (j == -2)
    str = assign_buff(str_tmp, buff, i, 1);
  else
    {
      str = malloc(sizeof(char) * (i - j + 1));
      if (str == NULL)
	return (NULL);
      utils_functions(str, 0, i - j + 1);
      k = 0;
      while (j < i)
	{
	  str[k] = buff[j];
	  k++;
	  j++;
	}
    }
  if (str_tmp != NULL)
    free(str_tmp);
  return (str);
}

char	*check_getnextline(const int fd, char **str_tmp, char *buff, int *i)
{
  int	j;

  j = *i;
  while (*i < READ_SIZE && buff[*i] != '\n' && buff[*i] != '\0')
    *i += 1;
  if (j != 0 && *i >= READ_SIZE)
    {
      *str_tmp = everything_line(buff, *str_tmp, *i, j);
      return (get_next_line(fd));
    }
  else if (j == 0 && *i >= READ_SIZE)
    {
      *str_tmp = everything_line(buff, *str_tmp, 0, -1);
      return (get_next_line(fd));
    }
  else if ((*i)++ < READ_SIZE && j == 0)
    return (everything_line(buff, *str_tmp, *i - 1, -2));
  else
    return (everything_line(buff, *str_tmp, *i - 1, j));
  return (NULL);
}

char	*get_next_line(const int fd)
{
  static char	buff[READ_SIZE + 1];
  static char	*str_tmp = NULL;
  static int	i = 0;
  int		size_r;

  if (fd == -1)
    return (NULL);
  if (str_tmp != NULL && buff[i - 1] == '\n')
    str_tmp = NULL;
  if (i == 0 || i >= READ_SIZE || buff[i] == '\0')
    {
      utils_functions(buff, 0, READ_SIZE + 1);
      size_r = read(fd, &buff, READ_SIZE);
      if (size_r == -1)
	return (NULL);
      if (size_r == 0)
	return (NULL);
      i = 0;
    }
  return (check_getnextline(fd, &str_tmp, buff, &i));
}
