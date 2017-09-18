/*
** main.c for test in /root/Delivery/CProg_Elem/CPE_2016_matchstick/src/test
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Sat Sep 16 17:28:11 2017 root
** Last update Sat Sep 16 17:35:09 2017 root
*/

#include <unistd.h>

char	*get_next_line(const int);

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

int	main()
{
  char	*str;

  while (str = get_next_line(0))
    {
      my_putstr(str);
      my_putstr("\n");
    }
  return (0);
}
