/*
** common.c for common in /home/benzah_m//svn/minishell2-2017-benzah_m
** 
** Made by marc benzahra
** Login   <benzah_m@epitech.net>
** 
** Started on  Mon Feb 25 15:36:56 2013 marc benzahra
** Last update Tue Apr  9 15:04:51 2013 marc benzahra
*/

void    my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}

int     my_put_nbr(int nb)
{
  int   i;

  i = 1;
  if (nb == 0)
    {
      my_putchar('0');
      return (0);
    }
  if ((nb >= 2147483647) || (nb <= -2147483648))
    return (0);
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  while ((nb / i) != 0)
    i = i * 10;
  i = i / 10;
  while (i != 0)
    {
      my_putchar(48 + (nb / i) % 10);
      nb = nb % i;
      i = i / 10;
    }
  return (0);
}
