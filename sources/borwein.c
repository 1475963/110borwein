/*
** borwein.c for borwein in /home/benzah_m//svn/git@github.com:1475963/110borwein.git/sources
** 
** Made by marc benzahra
** Login   <benzah_m@epitech.net>
** 
** Started on  Mon Apr  8 15:24:36 2013 marc benzahra
** Last update Tue Apr  9 11:43:54 2013 marc benzahra
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
  printf("\tI%d = (%.10f)\n\tdiff = (%.10f)\n", n, nb1, nb2);
}

double		produit(double n, double x)
{
  double	res = 1;
  int		k = 0;

  while (k <= n)
    {
      if (((2 * k) + 1) != 0 && (x / ((2 * k) + 1)) != 0)
	res = res * (sin(x / ((2 * k) + 1)) / (x / ((2 * k) + 1)));
      k = k + 1;
    }
  return (res);
}

void		rectangles(int n)
{
  double	i;
  double	result;
  double	h;
  double	a;
  double	b;

  a = 0;
  b = 5000;
  h = (b - a) / 10000;
  result = 0;
  i = a;
  while (i < b)
    {
      result = result + produit(n, i);
      i = i + h;
    }
  result = result * h;
  prompt(result, result - (M_PI / 2), n, 1);
}

void		trapezes(int n)
{
}

void		simpson(int n)
{
}

void		borwein(int n)
{
  rectangles(n);
  trapezes(n);
  simpson(n);
}
