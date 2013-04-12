/*
** borwein.c for borwein in /home/benzah_m//svn/git@github.com:1475963/110borwein.git/sources
** 
** Made by marc benzahra
** Login   <benzah_m@epitech.net>
** 
** Started on  Mon Apr  8 15:24:36 2013 marc benzahra
** Last update Fri Apr 12 13:34:48 2013 marc benzahra
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
      if (x != 0)
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
      result = result + produit(n, (a + i * h));
      i = i + 1;
    }
  result = result * h;
  prompt(result, result - (M_PI / 2), n, 1);
}

void		trapezes(double n)
{
  double	a = 0;
  double	b = 5000;
  double	i = 1;
  double	h = (b - a) / 10000;
  double	result = 0;

  while (i < b)
    {
      result = result + produit(n, (a + i * h));
      i = i + 1;
    }
  result = ((result * 2) + produit(n, a) + produit(n, b)) * ((b - a) / 20000);
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
      result = result + produit(n, (a + i * h) + (h / 2));
      i = i + 1;
    }
  i = 1;
  while (i < b)
    {
      res = res + produit(n, (a + i * h));
      i = i + 1;
    }
  final = ((result * 4) + (res * 2) + produit(n, a) + produit(n, b)) * ((b - a) / 60000);
  prompt(final, final - (M_PI / 2), n, 3);
}

Mix_Music	*set_music(char *str)
{
  Mix_Music	*music;

  if ((music = Mix_LoadMUS(str)) == NULL)
    {
      printf("%s\n", Mix_GetError());
      exit(EXIT_FAILURE);
    }
  if (Mix_PlayMusic(music, -1) == -1)
    {
      printf("%s\n", Mix_GetError());
      exit(EXIT_FAILURE);
    }
  return (music);
}

void		event_story_bro(Mix_Music *music, int volume, SDL_Event event)
{
  int	go;

  go = 1;
  while (go)
    {
      SDL_WaitEvent(&event);
      switch (event.type)
	{
	case SDL_KEYDOWN:
	  switch (event.key.keysym.sym)
	    {
	    case SDLK_ESCAPE:
	      go = 0;
	      break;
	    case SDLK_SPACE:
	      if (Mix_VolumeMusic(-1) > 0)
		Mix_VolumeMusic(0);
	      else
		Mix_VolumeMusic(volume);
	      break;
	    case SDLK_LEFT:
	      if (volume - 10 > 0)
		Mix_VolumeMusic((volume = volume - 10));
	      break;
	    case SDLK_RIGHT:
	      if (volume + 10 < 128)
		Mix_VolumeMusic((volume = volume + 10));
	      break;
	    case SDLK_UP:
	      {
		Mix_FreeMusic(music);
		music = set_music("songs/shit_gets_real.wav");
	      }
	      break;
	    case SDLK_DOWN:
	      {
		Mix_FreeMusic(music);
		music = set_music("songs/chirac.wav");
	      }
	      break;
	    }
	  break;
	}
    }
}

void		borwein(double n)
{
  int		volume;
  SDL_Surface	*screen;
  SDL_Event	event;
  Mix_Music	*music;

  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    exit_write("sdl failed to initialize");
  if ((screen = SDL_SetVideoMode(1, 1, 32, SDL_HWSURFACE)) == NULL)
    exit_write("video mode failed");
  if (Mix_OpenAudio(22050, AUDIO_S16, 2, 4096) == -1)
    exit_write("sdl_mixer failed to open audio channels");
  music = set_music("songs/draaaaagoooonz.wav");
  volume = Mix_VolumeMusic(-1);
  rectangles(n);
  trapezes(n);
  simpson(n);
  event_story_bro(music, volume, event);
  Mix_FreeMusic(music);
  Mix_CloseAudio();
  SDL_Quit();
}
