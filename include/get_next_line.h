/*
** getnextline.h for getnextline.h in /media/picot/2337a639-4d85-4f36-ade6-cdcedffd0cf2/picot_a/rendu/project/bsq
**
** Made by picot_a
** Login   <picot@epitech.net>
**
** Started on  Wed Dec 16 10:54:58 2015 picot_a
** Last update Mon Feb 29 22:11:20 2016 picot_a
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#include <unistd.h>

#ifndef READ_SIZE
#define READ_SIZE (4096)
#endif /* READ_SIZE */

int	utils_functions(char *str, char c, int size);
char	*assign_buff(char *str_tmp, char *buff, int i, int state);
char	*everything_line(char *buff, char *str_tmp, int i, int j);
char	*check_getnextline(int fd, char **str_tmp, char *buff, int *i);
char	*get_next_line(const int fd);

#endif /* GET_NEXT_LINE_H_ */
