/*
** data.c for matchstick in /root/Delivery/CProg_Elem/CPE_2016_matchstick/src
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Tue Jul  4 14:02:06 2017 root
** Last update Sun Jul 16 16:30:36 2017 root
*/

#include "my.h"

void	user_datab(t_info *info, char *line, int *verif)
{
  if ((info->u_line = my_getnbr(line)) > info->nb_line || info->u_line < 1)
    {
      my_putstr(ERROR);
      *verif = 1;
    }
}

int	user_data(t_info *info, char **tab)
{
  int	verif;
  char	*line;
  char	*match;

  verif = 1;
  while (verif == 1)
    {
      verif = 0;
      my_putstr(LINE);
      if ((line = get_next_line(0)) == NULL)
	  return (84);
      user_datab(info, line, &verif);
    }
  my_putstr(MATCHES);
  if ((match = get_next_line(0)) == NULL)
    return (84);
  if ((info->u_match = my_getnbr(match)) > info->nb_match
      || verif_match(info, tab) == 84 || info->u_match == 0)
    {
      my_putstr(ERROR);
      user_data(info, tab);
    }
  free(line);
  free(match);
  return (0);
}

int	verif_match(t_info *info, char **tab)
{
  int	i;

  i = 0;
  while (tab[info->u_line - 1][i] == '|')
    i++;
  if (i < info->u_match)
    return (84);
  return (0);
}

char	**player(char **tab, t_info *info)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (tab[info->u_line - 1][my_strlen(tab[info->u_line - 1]) - 1 - j] == ' ')
    j++;
  while (i < info->u_match)
    {
      tab[info->u_line - 1][my_strlen(tab[info->u_line - 1]) - 1 - i - j] = ' ';
      i++;
    }
  info->victory = 2;
  return (tab);
}

char	**ia(char **tab, t_info *info)
{
  int	i;
  int	j;

  i = 0;
  while (tab[i])
    {
      j = my_strlen(tab[i]);
      if (tab[i][0] == '|')
	{
	  while (tab[i][j] != '|')
	    j--;
	  tab[i][j] = ' ';
	  info->ia_line = i + 1;
	  info->ia_match = 1;
	  info->victory = 1;
	  return (tab);
	}
      i++;
    }
  return (tab);
}
