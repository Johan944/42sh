/*
** my_strcmp.c for  in /home/ganem-_j/PSU_2015_42sh/new
**
** Made by Johan Ganem--Brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Thu Jun  2 11:36:11 2016 Johan Ganem--Brunet
** Last update Thu Jun  2 11:38:02 2016 Johan Ganem--Brunet
*/

#include <stdlib.h>

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  if (s1 == NULL || s2 == NULL)
    return (-1);
  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i])
    i += 1;
  return (s1[i] - s2[i]);
}
