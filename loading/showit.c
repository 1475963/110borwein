/*
** showit.c for showit in /home/benzah_m//allum1
** 
** Made by marc benzahra
** Login   <benzah_m@epitech.net>
** 
** Started on  Tue Feb  5 11:55:51 2013 marc benzahra
** Last update Tue Apr  9 15:05:03 2013 marc benzahra
*/

#include <stdarg.h>

static void	cflag(va_list ap)
{
  char  c;

  c = (char) va_arg(ap, int);
  my_putchar(c);
}

static void	d_iflag(va_list ap)
{
  int   d;

  d = va_arg(ap, int);
  my_put_nbr(d);
}

static void	sflag(va_list ap)
{
  char		*s;

  s = va_arg(ap, char *);
  my_putstr(s);
}

static void	find_flag(const char *format, va_list ap)
{
  if (*format == 's')
    sflag(ap);
  else if (*format == 'd' || *format == 'i')
    d_iflag(ap);
  else if (*format == 'c')
    cflag(ap);
}

int		showit(const char *format, ...)
{
  va_list       ap;

  va_start(ap, format);
  while (*format)
    {
      if (*format == '%')
        {
          *format++;
          find_flag(format, ap);
        }
      else if ((*format >= 0) && (*format <= 127))
        my_putchar(*format);
      *format++;
    }
  va_end(ap);
}
