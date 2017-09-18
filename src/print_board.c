/*
** bootstrap.c for bootstrap in /root/Delivery/CProg_Elem/CPE_2016_matchstick
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Mon Jul  3 12:02:35 2017 root
** Last update Tue Jul 25 14:36:02 2017 root
*/

#include "my.h"

char	**create_tab(t_info *info)
{
  char	**tab;
  int	i;
  int	j;

  i = 0;
  j = 1;
  if ((tab = malloc(sizeof(char *) * ((info->nb_line + 1)))) == NULL)
    return (NULL);
  while (i < info->nb_line)
    {
      if ((tab[i] = malloc(sizeof(char) * (j + 1))) == NULL)
	return (NULL);
      i++;
      j+=2;
    }
  tab[i] = '\0';
  return (tab);
}

char	**fill_tab(char **tab, t_info *info)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 1;
  while (i < info->nb_line)
    {
      k = 0;
      while (k < j)
	{
	  tab[i][k] = '|';
	  k++;
	}
      tab[i][k] = '\0';
      i++;
      j+=2;
    }
  tab[i] = '\0';
  return (tab);
}

void	show_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putstr("\n");
      i++;
    }
}

void	print_board(char **tab, t_info *info)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  display_char('*', (info->nb_line * 2 + 1));
  my_putstr("\n");
  while (i < info->nb_line)
    {
      my_putstr("*");
      display_char(' ', info->nb_line - 1 - j);
      my_putstr(tab[i]);
      display_char(' ', info->nb_line - 1 - j);
      my_putstr("*\n");
      i++;
      j++;
    }
  display_char('*', (info->nb_line * 2 + 1));
  my_putstr("\n");
}

void	freeing(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}
