/*
** my_exit.c for  in /home/ganem-_j/PSU_2015_42sh/new
**
** Made by Johan Ganem--Brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Thu Jun  2 12:02:55 2016 Johan Ganem--Brunet
** Last update Mon Jun  6 01:12:23 2016 Mouraud Andrea
*/

#include <stdlib.h>
#include "42sh.h"

int	my_atoi(const char *str)
{
  int	result;
  int	i;

  i = 0;
  result = 0;
  if (str == NULL)
    return (-1);
  while (str[i])
    {
      result *= 10;
      if (str[i] < '0' || str[i] > '9')
        return (-1);
      result += str[i++] - 48;
    }
  return (result);
}

int	my_exit(const char *s)
{
  if (s != NULL)
    return (my_atoi(s));
  else
    return (-1);
}
