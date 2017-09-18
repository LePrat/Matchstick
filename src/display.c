/*
** display.c for matchstick in /root/Delivery/CProg_Elem/CPE_2016_matchstick
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Mon Jul  3 16:48:40 2017 root
** Last update Fri Jul  7 13:23:31 2017 root
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void	my_putnbr(int n)
{
  if (n < 0)
    {
      my_putchar('-');
      n = -n;
    }
  if (n >= 10)
    {
      my_putnbr(n / 10);
      my_putchar(n % 10 + '0');
    }
  if (n < 10)
    my_putchar(n % 10 + '0');
}

int	my_getnbr(char *str)
{
  int	i;
  int	j;
  int	nb;

  nb = str[my_strlen(str) - 1] - 48;
  i = my_strlen(str) - 1;
  j = 1;
  while (i > 0)
    {
      if (str[i] >= '0' && str[i] <= '9' && str[i-1] >= '0' && str[i-1] <= '9')
	{
	  nb = 10 * j * (str[i - 1] - 48) + nb;
	  j = j * 10;
	}
      i = i - 1;
    }
  if (str[0] == '-')
    nb = nb * (-1);
  return (nb);
}

void	display_char(char c, int n)
{
  int	i;

  i = 0;
  while (i < n)
    {
      write(1, &c, 1);
      i++;
    }
}
