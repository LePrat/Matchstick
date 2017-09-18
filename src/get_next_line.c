/*
** get_next_line.c for navy in /root/Delivery/CProg_Elem/CPE_2016_matchstick
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Mon Jul  3 13:42:06 2017 root
** Last update Sun Jul 16 17:01:55 2017 root
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

char	*my_strncpy(char *dest, char *src, int n)
{
  int		i;

  i = 0;
  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i++;
    }
  if (n < i)
    dest[i] = '\0';
  return (dest);
}

static char	*adding_l(char *l, int n, char *buffer, int *begin)
{
  char		*lenght;
  int		oldlen;

  oldlen = (l != 0) ? my_strlen(l) : 0;
  lenght = malloc((oldlen + n + 1) * sizeof(*lenght));
  if (l != 0)
    my_strncpy(lenght, l, oldlen);
  else
    my_strncpy(lenght, "", oldlen);
  lenght[oldlen + n] = 0;
  my_strncpy(lenght + oldlen, buffer + *begin, n);
  if (l)
    free(l);
  *begin = *begin + (n + 1);
  return (lenght);
}

char		*get_next_line(const int fd)
{
  static char	buffer[MEM];
  static int	nbinbuff = 0;
  static int	begin;
  int		n;
  char		*l;

  l = 0;
  n = 0;
  while (42)
    {
      if (nbinbuff <= begin)
	{
	  begin = 0;
	  if (!(nbinbuff = read(fd, buffer, MEM)))
	    return (l);
	  if (nbinbuff == -1)
	    return (NULL);
	  n = 0;
	}
      if (buffer[begin + n] == '\n')
	return (l = adding_l(l, n, buffer, &begin));
      if (begin + n == nbinbuff - 1)
	l = adding_l(l, n + 1, buffer, &begin);
      n = n + 1;
    }
}
