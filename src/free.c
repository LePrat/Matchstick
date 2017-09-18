/*
** free.c for matchstick in /root/Delivery/CProg_Elem/CPE_2016_matchstick
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Tue Jul 11 23:51:48 2017 root
** Last update Sun Jul 16 16:42:52 2017 root
*/

#include "my.h"

void	free_info(t_info *info)
{
  int	i;

  i = 0;
  free(info->numstr);
  while (info->bintab[i])
    {
      free(info->bintab[i]);
      i++;
    }
  free(info->bintab);
}

void	show_inttab(int *tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_putnbr(tab[i]);
      write(1, "\n", 1);
      i++;
    }
}

void	display_text(t_info *info, char c)
{
  if (c == 'u')
    {
      my_putstr("Player removed ");
      my_putnbr(info->u_match);
      my_putstr(" match(es) from line ");
      my_putnbr(info->u_line);
      my_putchar('\n');
    }
  if (c == 'i')
    {
      my_putstr("AI removed ");
      my_putnbr(info->ia_match);
      my_putstr(" match(es) from line ");
      my_putnbr(info->ia_line);
      my_putchar('\n');
    }
}

void	ini_struct(t_info *info, char **av)
{
  info->nb_line = my_getnbr(av[1]);
  info->nb_match = my_getnbr(av[2]);
  info->victory = 0;
}
