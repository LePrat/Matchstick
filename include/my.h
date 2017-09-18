/*
** my.h for Matchstick in /root/Delivery/Sys_Unix/PSU_2016_Matchstick
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Tue May  9 16:20:25 2017 root
** Last update Mon Sep 18 15:20:33 2017 root
*/

#ifndef MY_H_
# define MY_H_

#include <unistd.h>
#include <stdlib.h>

# define MEM 10000
# define ERROR "Error: Wrong input\n"
# define ERRORL "Error: this line is out of range\n"
# define ERRORM1 "Error: you cannot remove more than"
# define ERRORM2 "matches per turn'\n"
# define ERRORIP "Error: invalid input (positive number expected)\n"
# define ERRORM0 "Error: you have to remove at least one match\n"
# define ERRORM "Error: not enough matches on this line\n"
# define YTURN "\nYour turn:\n"
# define AITURN "\nAI's turn...\n"
# define LINE "Line: "
# define MATCHES "Matches: "
# define PREMOVED "Player removed"
# define PVIC "I lost... snif... but I'll get you next time!!\n"
# define AIVIC "You lost, too bad..\n"

typedef struct	s_info
{
  int		nb_line;
  int		nb_match;
  int		u_line;
  int		u_match;
  int		ia_line;
  int		ia_match;
  int		victory;
  char		**bintab;
  int		*numstr;
  int		verif;
  int		i;
  int		j;
  char		*str;
}		t_info;

void	my_putstr(char *);
int	my_strlen(char *);
int	my_getnbr(char *);
void	display_char(char, int);
char	**create_tab(t_info *);
char	**fill_tab(char **, t_info *);
void	show_tab(char **);
void	print_board(char **, t_info *);
void	freeing(char **);
char	*get_next_line(const int);
int	user_data(t_info *, char **);
void	user_datab(t_info *, char *, int *);
char	**ia(char **, t_info *);
char	**player(char **, t_info *);
int	verif_match(t_info *, char **);
void	my_putnbr(int);
void	my_putchar(char);
void	ini_struct(t_info *, char **);
void	display_text(t_info *, char);
int	victory(t_info *, char **);
int	matchstick(t_info *, char **);
char	*my_revstr(char *);
char	*my_bin(int);
int	bintab_ini(t_info *);
void	fill_bintab(t_info *, int *);
char	*pi_converter(t_info *);
int	check_piconvert(char *);
void	create_bintab(t_info *);
void	convert_board_num(t_info *, char **);
char	**convert_num_board(t_info *, char **);
void	show_inttab(int *);
char	**marienbad(t_info *, char **);
void	free_info(t_info *);
char	**info_mari(t_info *, char **, char *);

#endif /*!MY_H_*/
