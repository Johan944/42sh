/*
** epur_str.c for  in /home/ganem-_j/PSU_2015_42sh/new
**
** Made by Johan Ganem--Brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Wed Jun  1 11:30:10 2016 Johan Ganem--Brunet
** Last update Sun Jun  5 20:03:11 2016 Mouraud Andrea
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "42sh.h"

char	*epur_str(char *s)
{
  int	i;
  int	k;
  char	*ret;

  if (s == NULL || s[0] == 0)
    return (NULL);
  if ((ret = malloc(sizeof(char) * strlen(s) * 20)) == NULL)
    return (NULL);
  i = 0;
  k = 0;
  while (s[i])
    {
      while (s[i] != 0 && (s[i] == SPACE || s[i] == TAB))
	i += 1;
      while (s[i] != 0 && s[i] != SPACE && s[i] != TAB)
	ret[k++] = s[i++];
      while (s[i] != 0 && (s[i] == SPACE || s[i] == TAB))
	i += 1;
      if (s[i] != 0)
	ret[k++] = SPACE;
    }
  ret[k] = 0;
  return (ret);
  }
