/*
** borwein.c for borwein in /home/benzah_m//svn/git@github.com:1475963/110borwein.git/sources
** 
** Made by marc benzahra
** Login   <benzah_m@epitech.net>
** 
** Started on  Mon Apr  8 15:24:36 2013 marc benzahra
** Last update Mon Apr  8 17:06:37 2013 marc benzahra
*/

#include "../includes/borwein.h"

void	prompt(double nb1, double nb2, int n, int option)
{
  if (option == 1)
    printf("méthode des rectangles\n");
  else if (option == 2)
    printf("méthode des trapèzes\n");
  else if (option == 3)
    printf("méthode de Simpson\n");
  else
    return ;
  printf("\tI%d = (%f)\n\tdiff = (%f)\n", n, nb1, nb2);
}

void		borwein(int n)
{
  double	i = 0;
  double	k;
  long double	res;
  long double	result;
  double	h;

  h = 5000 / n;
  result = 0;
  while (i < 9999)
    {
      k = 0;
      res = 1;
      while (k < n)
	{
	  if (((2 * k) + 1) != 0 && ((i * h) / ((2 * k) + 1)) != 0)
	    res = res * (sin((i * h) / ((2 * k) + 1)) / ((i * h) / ((2 * k) + 1)));
	  k = k + 1;
	}
      result = result + res;
      i = i + 1;
    }
  result = result * h;
  prompt(result, result - M_PI, n, 1);
}
