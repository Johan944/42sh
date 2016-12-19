/*
** prompt.c for  in /home/ganem-_j/PSU_2015_42sh/new
**
** Made by Johan Ganem--Brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Wed Jun  1 11:12:51 2016 Johan Ganem--Brunet
** Last update Sun Jun  5 20:11:25 2016 Mouraud Andrea
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "42sh.h"

int	 get_prompt()
{
  char	*buf;
  int	i;

  i = 0;
  if ((buf = malloc(sizeof(char *) * 4096)) == NULL)
    return (-1);
  if ((buf = getcwd(buf, 4096)) == NULL)
    return (-1);
  while (buf[i] != 0)
    i += 1;
  buf[i] = RIGHT;
  buf[++i] = SPACE;
  buf[++i] = 0;
  write(isatty(1), buf, strlen(buf));
  free(buf);
  return (0);
}
