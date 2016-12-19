/*
** parser.c for  in /home/ganem-_j/PSU_2015_42sh/sources
**
** Made by Johan Ganem--Brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Sun Jun  5 12:03:37 2016 Johan Ganem--Brunet
** Last update Sun Jun  5 20:30:38 2016 Johan Ganem--Brunet
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "42sh.h"
#include "pars.h"

char	*add(char c, int *i, int *k)
{
  *k = 0;
  if (c == AND)
    {
      *i += 2;
      return (S_AND);
    }
  if (c == PIPE)
    {
      *i += 2;
      return (OR);
    }
  *i += 1;
  return (S_SEP);
}

int	init_struct(t_par *par, int idx)
{
  if (par->len == -2)
    return (-1);
  if (idx == 1)
    {
      if ((par->tab = malloc(sizeof(char **) * par->len)) == NULL)
	return (-1);
      par->i = 0;
      par->j = 0;
      while (par->j != par->len)
	if ((par->tab[par->j++] = malloc(sizeof(char *) * par->len)) == NULL)
	  return (-1);
      par->j = 0;
      par->k = 0;
      return (0);
    }
  if ((par->tab2 = malloc(sizeof(char **) * par->len)) == NULL)
    return (-1);
  par->i = 0;
  par->j = 0;
  while (par->j != par->len)
    if ((par->tab2[par->j++] = malloc(sizeof(char *) * par->len)) == NULL)
      return (-1);
  par->j = 0;
  par->k = 0;
  return (0);
}

int	separate_sep(char *str, t_par *par)
{
  if (init_struct(par, 1) == -1)
    return (-1);
  while (str[par->i])
    {
      if ((str[par->i] == SEPARATOR) ||
	  (str[par->i] == PIPE && str[par->i + 1] == PIPE)
	  || (str[par->i] == AND && str[par->i + 1] == AND))
	{
	  par->tab[par->j++][par->k] = 0;
	  par->tab[par->j++] = add(str[par->i], &par->i, &par->k);
	}
      else
	par->tab[par->j][par->k++] = str[par->i++];
    }
  par->tab[par->j++][par->k] = 0;
  par->tab[par->j] = NULL;
  return (0);
}

char	*add_double(char c, int *i, int *k)
{
  *i += 2;
  *k = 0;
  if (c == RIGHT)
    return (">>");
  return ("<<");
}

char	*add_simple(char c, int *i, int *k)
{
  *i += 1;
  *k = 0;
  if (c == PIPE)
    return (S_PIPE);
  if (c == LEFT)
    return ("<");
  return (">");
}
