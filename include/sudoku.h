#ifndef SUDOKU_H_
#define SUDOKU_H_

/* #define _BSD_SOURCE */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

typedef struct  s_pos
{
  int x;
  int y;
}               t_pos;

int	usage(char *name);
int	recur_map(int **map, t_pos pos);
int	fill_map(int **map);

		/* parser.c */

int	inside_parser(char *tmp, int **map, int z);
int	parser(int **map);
int	is_num(char *buff);

		/* check.c */

int	present_row(t_pos pos, int **map, int nb);
int	present_collum(t_pos pos, int **map, int nb);
int	present_carre(t_pos pos, int **map, int nb);

                /* init.c */

int	**init();
int	memset_map(int **map);

                /* display.c */

int	display_map(int **map);

		/* resolv.c */

int	resolv(int **map);
void	update_map(t_pos pos, int **map, int nb);
int	check_enter(int **map, t_pos pos, int *place_one);

#endif /* SUDOKU_H_ */
