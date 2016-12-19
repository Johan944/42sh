/*
** parser_pipe.c for  in /home/ganem-_j/PSU_2015_42sh/sources
**
** Made by Johan Ganem--Brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Fri Jun  3 17:49:12 2016 Johan Ganem--Brunet
** Last update Sun Jun  5 20:16:45 2016 Mouraud Andrea
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "42sh.h"

static int	idx;

char		**recup_tab(char **tab)
{
  char		**new;

  if (tab[idx] == NULL)
    return (NULL);
  new = my_str_to_wordtab(tab[idx++]);
  if (tab[idx] != NULL && my_strcmp(tab[idx], S_PIPE) == 0)
    idx += 1;
  return (new);
}

char	***parser_pipe(char **tab)
{
  char	***cmd;
  int	i;
  int	len;

  if ((cmd = malloc(sizeof(char ***) * (len = tablen(tab) * 2))) == NULL)
    return (NULL);
  i = -1;
  while (++i != len)
    if ((cmd[i] = malloc(sizeof(char **) * len)) == NULL)
      return (NULL);
  i = -1;
  while ((cmd[++i] = recup_tab(tab)) != NULL);
  idx = 0;
  i = -1;
  return (cmd);
}
