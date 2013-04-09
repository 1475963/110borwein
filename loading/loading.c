/*
** loading.c for loading in /home/benzah_m//svn/git@github.com:1475963/110borwein.git/loading
** 
** Made by marc benzahra
** Login   <benzah_m@epitech.net>
** 
** Started on  Tue Apr  9 14:48:56 2013 marc benzahra
** Last update Tue Apr  9 15:12:23 2013 marc benzahra
*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void	main(int ac, char **av)
{
  int	count;
  int	i = 0;

  srand(time(NULL));
  while (i <= 50)
    {
      count = 0;
      usleep(50000);
      showit("\x1B[48;5;%dm  ", rand() % 256);
      showit("\033[%sm", "30");
      showit("\r[ %d", i * 2);
      my_putstr("% ]\r");
      i++;
    }
  showit("\x1B[0m\n");
}
