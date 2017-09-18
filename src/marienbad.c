/*
** ia.c for matchstick in /root/Delivery/CProg_Elem/CPE_2016_matchstick
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Sun Jul  9 18:16:53 2017 root
** Last update Tue Sep  5 13:01:36 2017 root
*/

#include "my.h"

void	convert_board_num(t_info *info, char **tab)
{
  int	i;
  int	j;
  int	m_left;

  i = 0;
  while (tab[i])
    {
      j = 0;
      m_left = 0;
      while (tab[i][j])
	{
	  if (tab[i][j] == '|')
	    m_left = m_left + 1;
	  j++;
	}
      if (m_left == 0)
	m_left = -1;
      info->numstr[i] = m_left;
      i++;
    }
  info->numstr[i] = '\0';
}

char	**convert_num_board(t_info *info, char **tab)
{
  int	i;
  int	j;

  i = 0;
  while (tab[i])
    {
      j = 0;
      while (tab[i][j])
	{
	  if (info->numstr[i] != -1)
	    {
	      if (j < info->numstr[i])
		tab[i][j] = '|';
	      else
		tab[i][j] = ' ';
	    }
	  else
	    tab[i][j] = ' ';
	  j++;
	}
      i++;
    }
  return (tab);
}

int	*inttab_cpy(int *tab, t_info *info)
{
  int	i;
  int	*numstr;

  i = 0;
  if ((numstr = malloc(sizeof(int) * (info->nb_line + 1))) == NULL)
    return (NULL);
  while (tab[i])
    {
      numstr[i] = tab[i];
      i++;
    }
  numstr[i] = '\0';
  info->verif = 0;
  if (numstr[info->i] - info->j >= 0)
    {
      numstr[info->i] = numstr[info->i] - info->j;
      info->verif = 1;
    }
  if (numstr[info->i] == 0)
    {
      numstr[info->i] = -1;
      info->verif = 1;
    }
  return (numstr);
}

char	**info_mari(t_info *info, char **tab, char *str)
{
  info->ia_match = info->j;
  info->ia_line = info->i + 1;
  tab = convert_num_board(info, tab);
  info->victory = 1;
  free(str);
  return (tab);
}

char	**marienbad(t_info *info, char **tab)
{
  int	*numstr;

  info->i = 0;
  while (info->numstr[info->i])
    {
      info->j = 1;
      while (info->j <= info->nb_match)
	{
	  numstr = inttab_cpy(info->numstr, info);
	  if (info->verif == 1)
	    {
	      fill_bintab(info, numstr);
	      info->str = pi_converter(info);
	      if (check_piconvert(info->str) == 0)
		{
		  info->numstr = numstr;
		  tab = info_mari(info, tab, info->str);
		  return (tab);
		}
	    }
	  info->j = info->j + 1;
	}
      info->i = info->i + 1;
    }
  tab = ia(tab, info);
  return (tab);
}
