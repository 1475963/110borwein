/*
** borwein.h for borwein in /home/benzah_m//svn/git@github.com:1475963/110borwein.git/sources
** 
** Made by marc benzahra
** Login   <benzah_m@epitech.net>
** 
** Started on  Mon Apr  8 15:14:57 2013 marc benzahra
** Last update Tue Apr  9 13:50:07 2013 marc benzahra
*/

#ifndef BORWEIN_H_
# define BORWEIN_H_
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <SDL/SDL.h>
# include <SDL/SDL_mixer.h>

void	prompt(double nb1, double nb2, double n, int option);
double	produit(double n, double x);
void	rectangles(double n);
void	trapezes(double n);
void	simpson(double n);
void	borwein(double n);

#endif /* !BORWEIN_H_ */
