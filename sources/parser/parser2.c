/*
** parser2.c for parser2 in /home/gassem_a/PSU/PSU_2015_42sh
**
** Made by Aurélien Gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Sun Jun  5 17:02:35 2016 Aurélien Gassemann
** Last update Sun Jun  5 20:21:32 2016 Johan Ganem--Brunet
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "42sh.h"
#include "pars.h"

char	**separate2(char *str, t_par *par)
{
  if (init_struct(par, 2) == -1)
    return (NULL);
  while (str[par->i])
    {
      if ((str[par->i] == RIGHT && str[par->i + 1] == RIGHT)
	  || (str[par->i] == LEFT && str[par->i + 1] == LEFT))
	{
	  if (par->tab2[0][0] != 0)
	    par->tab2[par->j++][par->k] = 0;
	  par->tab2[par->j++] = add_double(str[par->i], &par->i, &par->k);
	}
      else if (str[par->i] == RIGHT || str[par->i] == LEFT ||
	       str[par->i] == PIPE)
	{
	  if (par->tab2[0][0] != 0)
	    par->tab2[par->j++][par->k] = 0;
	  par->tab2[par->j++] = add_simple(str[par->i], &par->i, &par->k);
	}
      else
	par->tab2[par->j][par->k++] = str[par->i++];
    }
  if (par->tab2[par->j][0] != 0)
    par->tab2[par->j++][par->k] = 0;
  par->tab2[par->j] = NULL;
  return (par->tab2);
}

int	epur_tab(t_par *par)
{
  int	i;
  int	j;

  i = -1;
  while (par->pars[++i])
    {
      j = -1;
      while (par->pars[i][++j])
	if ((par->pars[i][j] = epur_str(par->pars[i][j])) == NULL)
	  return (-1);
    }
  return (0);
}

int	return_tab(t_par *par)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (par->tab[i])
    {
      if (strcmp(par->tab[i], OR) != 0 && strcmp(par->tab[i], S_AND) != 0
	  && strcmp(par->tab[i], S_SEP) != 0)
	{
	  if ((par->pars[j++] = separate2(par->tab[i], par)) == NULL)
	    return (-1);
	}
      else if ((par->pars[j] = malloc(sizeof(char *) * par->len)) != NULL)
	{
	  par->pars[j][0] = par->tab[i];
	  par->pars[j++][1] = NULL;
	}
      else
	return (-1);
      i++;
    }
  par->pars[j] = NULL;
  return (epur_tab(par));
}

char	***parser(char *str)
{
  t_par	par;

  if ((str = init_str(str)) == NULL)
    return (NULL);
  par.len = strlen(str) * 2;
  if ((str == NULL) || (separate_sep(str, &par)) == -1)
    return (NULL);
  if ((par.pars = malloc(sizeof(char ***) * par.len)) == NULL)
    return (NULL);
  if (return_tab(&par) == -1)
    return (NULL);
  return (par.pars);
}
