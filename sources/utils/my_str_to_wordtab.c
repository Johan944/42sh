/*
** my_str_to_wordtab.c for  in /home/ganem-_j/PSU_2015_42sh/new
**
** Made by Johan Ganem--Brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Wed Jun  1 11:50:02 2016 Johan Ganem--Brunet
** Last update Sun Jun  5 20:02:55 2016 Mouraud Andrea
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "42sh.h"

char	**str_to_wordtab(char *str, char c)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  if (str == NULL)
    return (NULL);
  if ((tab = malloc(sizeof(char **) * strlen(str))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str[i] != 0)
    {
      k = 0;
      if ((tab[j] = malloc(sizeof(char *) * strlen(str))) == NULL)
	return (NULL);
      while ((str[i] == c) && str[i++] != 0);
      while (str[i] != c && str[i] != 0)
	tab[j][k++] = str[i++];
      tab[j++][k] = 0;
      while ((str[i] == c) && str[i++] != 0);
    }
  tab[j] = NULL;
  return (tab);
}

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  if (!str)
    return (NULL);
  if ((tab = malloc(sizeof(char **) * strlen(str) * 2)) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str[i] != 0)
    {
      k = 0;
      if ((tab[j] = malloc(sizeof(char *) * strlen(str) * 2)) == NULL)
	return (NULL);
      while ((str[i] == SPACE || str[i] == TAB) && str[i++] != 0);
      while (str[i] != SPACE && str[i] != TAB && str[i] != 0)
	tab[j][k++] = str[i++];
      tab[j++][k] = 0;
      while ((str[i] == SPACE || str[i] == TAB) && str[i++] != 0);
    }
  tab[j] = NULL;
  return (tab);
}
