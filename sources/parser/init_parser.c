/*
** init_parser.c for  in /home/ganem-_j/PSU_2015_42sh/sources
**
** Made by Johan Ganem--Brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Sat Jun  4 18:04:22 2016 Johan Ganem--Brunet
** Last update Sun Jun  5 20:18:21 2016 Mouraud Andrea
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "42sh.h"

int	check_end(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] == PIPE && (str[i + 1] == SPACE)
	   && (str[i + 2] == PIPE || str[i + 2] == AND
	       || str[i + 2] == RIGHT || str[i + 2] == LEFT))
          || (str[i] == PIPE && str[i + 1] == 0))
	{
	  fprintf(stderr, INVALID_NULL);
	  return (1);
	}
      i++;
    }
  return (0);
}

int	check_string(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] == PIPE && (str[i + 1] == SPACE)
	  && (str[i + 2] == PIPE || str[i + 2] == AND
	      || str[i + 2] == RIGHT || str[i + 2] == LEFT))
	  || (str[i] == PIPE && str[i + 1] == 0))
	{
	  fprintf(stderr, INVALID_NULL);
	  return (1);
	}
      if (str[i] == SEPARATOR || str[i] == SPACE || str[i] == TAB);
      else if ((str[i] == PIPE && str[i + 1] == PIPE)
               || (str[i] == AND && str[i + 1] == AND))
	i += 1;
      else
	return (check_end(str));
      i += 1;
    }
  return (1);
}

char	*without_space(char *str)
{
  char	*new;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((new = malloc(sizeof(char *) * strlen(str))) == NULL)
    return (NULL);
  while (str[i])
    {
      if (str[i] != SPACE)
	new[j++] = str[i];
      i += 1;
    }
  new[j] = 0;
  return (new);
}

int	check_invalid(char *new, int i)
{
  if (new == NULL)
    return (1);
  while (new[++i])
    {
      if ((new[i] == AND && new[i + 1] == AND && new[i + 2] == AND)
	  || (new[i] == PIPE && new[i + 1] == PIPE && new[i + 2] == PIPE))
	return (fprintf(stderr, INVALID_NULL));
      if ((new[i] == RIGHT && new[i + 1] == LEFT)
	  || (new[i] == LEFT && new[i + 1] == RIGHT)
	  || ((new[i] == RIGHT || new[i] == LEFT)
	      && (new[i + 1] == RIGHT || new[i + 1] == LEFT)
	      && (new[i + 2] == RIGHT || new[i + 2] == LEFT))
	  || ((new[i] == RIGHT || new[i] == LEFT)
	      && (new[i + 1] == 0 || new[i + 1] == SEPARATOR ||
		  new[i + 1] == PIPE || new[i + 1] == AND)))
	return (fprintf(stderr, INVALID_NULL));
    }
  return (0);
}

char	*init_str(char *str)
{
  int	j;

  str = epur_str(str);
  if (str == NULL)
    return (NULL);
  if (check_string(str) == 1)
    return (NULL);
  if (check_invalid(without_space(str), -1) != 0)
    return (NULL);
  j = strlen(str) - 1;
  if ((str[j] == PIPE && str[j - 1] == PIPE)
      || (str[j] == AND && str[j - 1] == PIPE))
    str[j - 1] = 0;
  return (str);
}
