/*
** borwein.c for borwein in /home/benzah_m//svn/git@github.com:1475963/110borwein.git/sources
** 
** Made by marc benzahra
** Login   <benzah_m@epitech.net>
** 
** Started on  Mon Apr  8 15:24:36 2013 marc benzahra
** Last update Tue Apr  9 13:39:50 2013 marc benzahra
*/

#include "../includes/borwein.h"

void	prompt(double nb1, double nb2, double n, int option)
{
  if (option == 1)
    printf("méthode des rectangles\n");
  else if (option == 2)
    printf("méthode des trapèzes\n");
  else if (option == 3)
    printf("méthode de Simpson\n");
  else
    return ;
  printf("\tI%.0f = %.10f\n\tdiff = %.10f\n", n, nb1, nb2);
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

void		rectangles(double n)
{
  double	a = 0;
  double	b = 5000;
  double	i = a;
  double	h = (b - a) / 10000;
  double	result = 0;

  while (i < b)
    {
      result = result + produit(n, i);
      i = i + h;
    }
  result = result * h;
  prompt(result, result - (M_PI / 2), n, 1);
}

void		trapezes(double n)
{
  double	a = 0;
  double	b = 5000;
  double	i = a;
  double	h = (b - a) / 10000;
  double	result = 0;

  i = 1;
  while (i < b)
    {
      result = result + produit(n, i);
      i = i + h;
    }
  result = ((result * 2)/* + produit(n, a) */+ produit(n, b)) * ((b - a) / 20000);
  prompt(result, result - (M_PI / 2), n, 2);
}

void		simpson(double n)
{
  double	a = 0;
  double	b = 5000;
  double	i = a;
  double	h = (b - a) / 10000;
  double	result = 0;
  double	res = 0;
  double	final;

  while (i < b)
    {
      result = result + produit(n, i + (h / 2));
      i = i + h;
    }
  i = 1;
  while (i < b)
    {
      res = res + produit(n, i);
      i = i + h;
    }
  final = ((result * 4) + (res * 2)/* + produit(n, a) */+ produit(n, b)) * ((b - a) / 60000);
  prompt(final, final - (M_PI / 2), n, 3);
}

void		borwein(double n)
{
  rectangles(n);
  trapezes(n);
  simpson(n);
}
