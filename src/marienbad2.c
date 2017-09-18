/*
** marienbad2.c for matchstick in /root/Delivery/CProg_Elem/CPE_2016_matchstick/src
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Fri Jul 14 00:49:20 2017 root
** Last update Fri Jul 14 01:06:05 2017 root
*/

#include "my.h"

char	*my_bin(int n)
{
  int	c;
  int	d;
  int	i;
  char	*str;

  i = 0;
  c = 15;
  if ((str = malloc(sizeof(char) * 32 + 1)) == NULL)
    return (NULL);
  while (c >= 0)
    {
      d = n >> c;
      if (d & 1)
	str[i] = 1 + '0';
      else
	str[i] = 0 + '0';
      i++;
      c--;
    }
  str[i] = '\0';
  return (str);
}

int	bintab_ini(t_info *info)
{
  char	**tab;
  int	*numstr;
  int	i;

  i = 0;
  if ((tab = malloc(sizeof(char *) * ((info->nb_line + 1)))) == NULL)
    return (84);
  while (i < info->nb_line)
    {
      if ((tab[i] = malloc(sizeof(char) * (32 + 1))) == NULL)
	return (84);
      i++;
    }
  if ((numstr = malloc(sizeof(int) * (info->nb_line + 1))) == NULL)
    return (84);
  tab[i] = '\0';
  info->numstr = numstr;
  info->bintab = tab;
  return (0);
}

void	fill_bintab(t_info *info, int *numstr)
{
  int	i;

  i = 0;
  while (numstr[i])
    {
      if (numstr[i] == -1)
	info->bintab[i] = my_bin(0);
      else
	info->bintab[i] = my_bin(numstr[i]);
      i++;
    }
  info->bintab[i] = '\0';
}

char	*pi_converter(t_info *info)
{
  int	i;
  int	j;
  char	*str;
  int	som;

  i = 0;
  j = 1;
  if ((str = malloc(sizeof(char) * my_strlen(info->bintab[0]) + 1)) == NULL)
    return (NULL);
  str[0] = 'z';
  while (j < 16)
    {
      i = 0;
      som = 0;
      while (info->bintab[i])
	{
	  som = som + info->bintab[i][j] - '0';
	  i++;
	}
      str[j] = (som % 2 == 0) ? 'p' : 'i';
      if (som == 0 && str[j - 1] == 'z')
	str[j] = 'z';
      j++;
    }
  str[j] = '\0';
  return (str);
}

int	check_piconvert(char *str)
{
  int	i;
  int	nbi;
  int	nbp;

  i = 0;
  nbi = 0;
  nbp = 0;
  while (str[i])
    {
      if (str[i] == 'i')
	nbi = nbi + 1;
      else if (str[i] == 'p')
	nbp = nbp + 1;
      i++;
    }
  if ((nbp > 1 && nbi == 0) || (nbp == 0 && nbi == 1))
    return (0);
  else
    return (1);
}
