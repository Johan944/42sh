/*
** echo.c for 42sh in /home/mourau/42sh
**
** Made by andrea mouraud
** Login   <mourau@epitech.net>
**
** Started on  Fri May 27 21:44:55 2016 andrea mouraud
** Last update Sun Jun  5 23:50:50 2016 Mouraud Andrea
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "42sh.h"

char	**check_opt(char **tab, t_args *args)
{
  int	i;
  int	j;
  char	**elem;

  i = 0;
  j = 0;
  if ((elem = malloc(sizeof(char **) * 100)) == NULL)
    return (NULL);
  while (tab[++i])
    {
      if (!strcmp(tab[i], NEWLINE_ON))
	args->newline = false;
      else if (!strcmp(tab[i], BACKSLASH_ON))
	args->backslash = true;
      else if (!strcmp(tab[i], BACKSLASH_OFF))
	args->backslash = false;
      else
	elem[j++] = tab[i];
    }
  return (elem);
}

void	do_echo(char **tab, t_args *args)
{
  int	i;
  int	j;

  i = -1;
  while (tab[++i])
    {
      j = -1;
      while (tab[i][++j])
	if (tab[i][j] == BACKSLASH && tab[i][j + 1] == BACKSLASH)
	  my_putchar(BACKSLASH);
	else if (tab[i][j] == BACKSLASH);
	else
	  my_putchar(tab[i][j]);
      if (tab[i + 1])
	my_putchar(SPACE);
    }
  if (args->newline)
    my_putchar(NEWLINE);
}

int	put_backslash(char c)
{
  int	i;
  char	*tab;

  i = -1;
  tab = BACKSLASH_LIST;
  while (tab[++i])
    if (tab[i] == c)
      return (my_putchar(tab[i + 1]));
  my_putchar(BACKSLASH);
  my_putchar(c);
  return (0);
}

void	do_backslash(char **tab, t_args *args)
{
  int	i;
  int	j;

  i = -1;
  while (tab[++i])
    {
      j = -1;
      while (tab[i][++j])
	if (tab[i][j] == 92 && tab[i][j + 1] == 92)
	  {
	    put_backslash(tab[i][++j + 1]);
	    j++;
	  }
	else if (tab[i][j] == 92);
	else
	  my_putchar(tab[i][j]);
      if (tab[i + 1])
	my_putchar(SPACE);
    }
  if (args->newline)
    my_putchar(NEWLINE);
}

int	echo(char *str)
{
  char	**tab;
  t_args args;

  tab = str_to_wordtab(str, SPACE);
  args.newline = true;
  args.backslash = false;
  if ((tab = check_opt(tab, &args)) == NULL)
    return (-1);
  if (!args.backslash)
    do_echo(tab, &args);
  else
    do_backslash(tab, &args);
  return (0);
}
