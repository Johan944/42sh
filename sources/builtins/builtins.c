/*
** builtins.c for 42sh in /home/mourau_a/PSU_2015_42sh/new
**
** Made by Mouraud Andrea
** Login   <mourau_a@epitech.net>
**
** Started on  Thu Jun  2 13:58:45 2016 Mouraud Andrea
** Last update Sun Jun  5 20:27:44 2016 Mouraud Andrea
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "42sh.h"

void	disp_env(char ***env)
{
  int	i;

  i = -1;
  while (env[0][++i])
    printf("%s\n", env[0][i]);
}

void	xunsetenv(char **args, char ***env)
{
  int	i;
  int	j;
  int	k;
  char	*elem;

  i = 0;
  while (args[++i])
    {
      j = -1;
      elem = strcat(args[i], SIGN_EQUAL);
      while (env[0][++j] && my_strcmp(PATH_EQUAL, elem) != 0)
	{
	  if (!strncmp(env[0][j], elem, strlen(elem)))
	    {
	      k = j;
	      while (env[0][k + 1])
		{
		  env[0][k] = env[0][k + 1];
		  k++;
		}
	      env[0][k] = 0;
	    }
	}
    }
}

int	setlol(char **args, char ***env)
{
  int	i;
  int	j;
  char	**unset;
  char	*elem;

  i = 0;
  j = 0;
  if ((unset = malloc(sizeof(char **) * 100)) == NULL)
    return (-1);
  unset[0] = args[1];
  unset[1] = args[1];
  xunsetenv(unset, env);
  if ((elem = malloc(sizeof(char *) * 4096)) == NULL)
    return (-1);
  while (args[1][j])
    elem[i++] = args[1][j++];
  j = 0;
  if (args[2] != 0)
    while (args[2][j])
      elem[i++] = args[2][j++];
  j = 0;
  while (env[0][j++]);
  env[0][j - 1] = elem;
  env[0][j] = 0;
  return (0);
}

void	xsetenv(char **args, char ***env)
{
  if (my_strcmp(args[1], PATH) == 0 && args[2] == NULL)
    return ;
  if (!args[1])
    disp_env(env);
  else if (!args[3])
    setlol(args, env);
  else
    fprintf(stderr, SETENV_ERROR);
}

bool    my_builtins(char ****tab, char ***env, int i)
{
  if (!strcmp(*tab[0][i], "env"))
    disp_env(env);
  else if (!strncmp(*tab[0][i], "setenv", 6))
    xsetenv(str_to_wordtab(*tab[0][i], ' '), env);
  else if (!strncmp(*tab[0][i], "unsetenv", 8))
    xunsetenv(str_to_wordtab(*tab[0][i], ' '), env);
  else if (!strncmp(*tab[0][i], "cd", 2))
    my_cd(str_to_wordtab(*tab[0][i], ' ')[1], env);
  else if (!strncmp(*tab[0][i], "echo", 4))
    echo(*tab[0][i]);
  else
    return (false);
  return (true);
}
