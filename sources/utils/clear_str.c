/*
** clear_str.c for  in /home/sereptf/PSU_2015_42sh/sources
**
** Made by sereptf
** Login   <sereptf@epitech.net>
**
** Started on  Sat Jun  4 19:05:32 2016 sereptf
** Last update Sun Jun  5 20:20:10 2016 Mouraud Andrea
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "42sh.h"

char	*clear_str(char *str)
{
  char	*new;
  int	i;
  int	j;

  i = 0;
  j = 0;
  str = epur_str(str);
  if ((new = malloc(sizeof(char *) * strlen(str))) == NULL)
    return (NULL);
  while (str[i] == ';' && str[i] != 0)
    i += 1;
  while (str[i] != 0)
    {
      if ((str[i] == SEPARATOR && str[i + 1] == SEPARATOR)
	  || (str[i] == SEPARATOR && str[i + 1] == SPACE &&
	      str[i + 2] == SEPARATOR)
	  || (str[i] == SEPARATOR && str[i + 1] == TAB &&
	      str[i + 2] == SEPARATOR));
      else
	new[j++] = str[i];
      i += 1;
    }
  new[j] = 0;
  free(str);
  return (new);
}
