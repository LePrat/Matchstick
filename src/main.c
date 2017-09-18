/*
** main.c for matchstick in /root/Delivery/CProg_Elem/CPE_2016_matchstick/src
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Tue Jul  4 01:19:59 2017 root
** Last update Sun Jul 16 17:29:28 2017 root
*/

#include "my.h"

int	victory(t_info *info, char **tab)
{
  int	i;
  int	j;
  int	verif_victory;

  i = 0;
  verif_victory = 0;
  while (tab[i])
    {
      j = 0;
      while (tab[i][j] != '\0')
	{
	  if (tab[i][j] == '|')
	    verif_victory = 1;
	  j++;
	}
      i++;
    }
  if (verif_victory == 0 && info->victory == 2)
    return (2);
  if (verif_victory == 0 && info->victory == 1)
    return (1);
  return (0);
}

char	**matchstick_ini(t_info *info, char **av)
{
  char	**tab;

  ini_struct(info, av);
  bintab_ini(info);
  tab = create_tab(info);
  fill_tab(tab, info);
  print_board(tab, info);
  convert_board_num(info, tab);
  fill_bintab(info, info->numstr);
  return (tab);
}

char	**matchstick_iaturn(t_info *info, char **tab)
{
  my_putstr(AITURN);
  tab = marienbad(info, tab);
  display_text(info, 'i');
  print_board(tab, info);
  convert_board_num(info, tab);
  fill_bintab(info, info->numstr);
  return (tab);
}

int	matchstick(t_info *info, char **av)
{
  char	**tab;

  tab = matchstick_ini(info, av);
  while (victory(info, tab) == 0)
    {
      my_putstr(YTURN);
      if (user_data(info, tab) == 84)
	return (84);
      display_text(info, 'u');
      tab = player(tab, info);
      print_board(tab, info);
      convert_board_num(info, tab);
      fill_bintab(info, info->numstr);
      if (victory(info, tab) == 2)
	{
	  my_putstr(AIVIC);
	  freeing(tab);
	  return (2);
	}
      matchstick_iaturn(info, tab);
    }
  my_putstr(PVIC);
  freeing(tab);
  return (1);
}

int		main(int ac, char **av)
{
  t_info	*info;
  int		victory;

  if (ac == 3 && my_getnbr(av[1]) >= 1 && my_getnbr(av[1]) <= 100
      && my_getnbr(av[2]) >= 1)
    {
      if ((info = malloc(sizeof(t_info) + 1)) == '\0')
	return (0);
      victory = matchstick(info, av);
      free_info(info);
      free(info);
      if (victory == 1)
	return (1);
      else if (victory == 2)
	return (2);
      else
	return (0);
    }
  return (0);
}
