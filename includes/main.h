/*
** main.h for main in /home/benzah_m//svn/git@github.com:1475963/110borwein.git/includes
** 
** Made by marc benzahra
** Login   <benzah_m@epitech.net>
** 
** Started on  Tue Apr  9 11:52:54 2013 marc benzahra
** Last update Tue Apr  9 12:01:15 2013 marc benzahra
*/

#ifndef MAIN_H_
# define MAIN_H_
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

void	exit_error(char *function, char *file, char *block);
void	exit_write(char *str);
void	check_arg(char *av);
double	check_n(double n);
void	main(int ac, char **av);

#endif /* !MAIN_H_ */
