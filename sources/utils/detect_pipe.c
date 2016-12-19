/*
** detect_pipe.c for  in /home/ganem-_j/PSU_2015_42sh/sources
**
** Made by Johan Ganem--Brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Fri Jun  3 18:23:47 2016 Johan Ganem--Brunet
** Last update Sun Jun  5 20:02:11 2016 Mouraud Andrea
*/

#include "42sh.h"

int	detect_pipe(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    if (my_strcmp(tab[i++], S_PIPE) == 0)
      return (1);
  return (0);
}
