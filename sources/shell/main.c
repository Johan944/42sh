/*
** main.c for  in /home/ganem-_j/PSU_2015_42sh/new
**
** Made by Johan Ganem--Brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Wed Jun  1 11:04:02 2016 Johan Ganem--Brunet
** Last update Sun Jun  5 20:05:55 2016 Mouraud Andrea
*/

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include "42sh.h"

void	my_signal()
{
  printf("\n");
  get_prompt();
}

int	check_path(char **env)
{
  int	i;

  i = 0;
  while (env[i])
    if (strncmp(env[i++], PATH_EQUAL, 5) == 0)
      return (1);
  return (0);
}

char	**check_env(char **environ)
{
  char	**env;

  if ((env = malloc(sizeof(char *) * 10)) == NULL)
    return (environ);
  if (environ[0] == 0)
    {
      env[0] = BASIC_PATH;
      return (env);
    }
  if (check_path(environ) == 0)
    environ[tablen(environ) - 1] = BASIC_PATH;
  environ[tablen(environ)] = NULL;
  return (environ);
}

int	main(int ac, char **av, char **env)
{
  int	val_ret;

  (void)(ac);
  (void)(av);
  g_exit = 0;
  env = check_env(env);
  signal(SIGINT, my_signal);
  val_ret = my_prog(env);
  if ((g_pid != 0 && val_ret == 0) || g_exit == 1)
    return (1);
  else
    return (val_ret);
}
