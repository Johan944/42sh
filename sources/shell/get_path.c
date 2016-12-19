/*
** get_path.c for  in /home/ganem-_j/PSU_2015_42sh/new
**
** Made by Johan Ganem--Brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Wed Jun  1 21:37:09 2016 Johan Ganem--Brunet
** Last update Sun Jun  5 21:31:42 2016 Johan Ganem--Brunet
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "42sh.h"

char		**get_path(char **env)
{
  t_shell	shell;

  shell.i = -1;
  shell.k = 0;
  if ((shell.path = malloc(sizeof(char) * 1000)) == NULL)
    return (NULL);
  while (env[++shell.i])
    if (!strncmp(env[shell.i], PATH_EQUAL, 5))
      {
	shell.j = 5;
	while (env[shell.i][shell.j])
	  shell.path[shell.k++] = env[shell.i][shell.j++];
	shell.path[shell.k] = 0;
	shell.ret = str_to_wordtab(shell.path, DOUBLE);
	free(shell.path);
	shell.i = -1;
	while (shell.ret[++shell.i])
	  shell.ret[shell.i] = strcat(shell.ret[shell.i], SLASH);
	return (shell.ret);
      }
  if ((shell.ret = malloc(sizeof(char **) * 2)) == NULL)
    return (NULL);
  shell.ret[0] = BIN;
  shell.ret[1] = NULL;
  return (shell.ret);
}
