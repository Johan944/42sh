/*
** pipe.c for 42sh in /home/mourau_a/PSU_2015_42sh/sources
**
** Made by Mouraud Andrea
** Login   <mourau_a@epitech.net>
**
** Started on  Fri Jun  3 19:06:38 2016 Mouraud Andrea
** Last update Sun Jun  5 22:01:29 2016 Johan Ganem--Brunet
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include "42sh.h"
#include "pipe.h"

int	exec_pipe(char **tab, char **env)
{
  int	idx;
  char	**path;

  if (!tab[0])
    return (1);
  idx = 0;
  path = get_path(env);
  if (tab[0][0] == DOT || tab[0][0] == N_SLASH)
    execve(tab[0], tab, env);
  else if (path)
    while (path[idx])
      {
	if (tab[0][0] != DOT && tab[0][0] != N_SLASH)
	  execve(strcat(path[idx], tab[0]), tab, env);
	idx++;
      }
  fprintf(stderr, NOT_FOUND, tab[0]);
  exit(1);
  return (1);
}

void	do_pipe(char ***cmd, char **env, t_pip *pip)
{
  while (*cmd != NULL)
    {
      pipe(pip->p);
      if ((pip->pid = fork()) == -1)
	exit(1);
      else if (pip->pid == 0)
	{
	  dup2(pip->fd_in, 0);
	  if (*(cmd + 1) != NULL)
	    dup2(pip->p[1], 1);
	  close(pip->p[0]);
	  exec_pipe(*cmd, env);
	  exit(1);
	}
      else
	{
	  g_pid = 0;
	  wait(&g_pid);
	  if (g_pid == 256)
	    g_exit = 1;
	  close(pip->p[1]);
	  pip->fd_in = pip->p[0];
	  cmd++;
	}
    }
}

void	loop_pipe(char ***cmd, char **env)
{
  t_pip	pip;

  pip.fd_in = 0;
  g_exit = 0;
  do_pipe(cmd, env, &pip);
}
