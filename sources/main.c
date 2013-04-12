/*
** main.c for main in /home/benzah_m//svn/git@github.com:1475963/110borwein.git/sources
** 
** Made by marc benzahra
** Login   <benzah_m@epitech.net>
** 
** Started on  Mon Apr  8 15:13:27 2013 marc benzahra
** Last update Fri Apr 12 12:33:39 2013 marc benzahra
*/

#include "../includes/main.h"

void	exit_error(char *function, char *file, char *block)
{
  printf("/!\\ %s failed /!\\\nfile : %s\nfunction : %s\n", function, file, block);
  exit(EXIT_FAILURE);
}

void	exit_write(char *str)
{
  printf("%s\n", str);
  exit(EXIT_FAILURE);
}

void	check_arg(char *av)
{
  int	i;

  i = 0;
  while (av[i] != '\0')
    if (av[i] >= '0' && av[i] <= '9')
      i = i + 1;
    else
      exit_write("Please put correct arguments");
}

double	check_n(double n)
{
  if (n >= 0)
    return (n);
  else
    exit_write("n must be a number positive or equal to 0");
}

void	main(int ac, char **av)
{
  if (ac == 2)
    {
      check_arg(av[1]);
      borwein(check_n(atof(av[1])));
    }
  else
    exit_write("Usage\t./110borwein [n]\tWhen n is a number superior or equal to 0");
}
