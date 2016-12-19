/*
** redirections.c for  in /home/ganem-_j/PSU_2015_42sh/sources
**
** Made by Johan Ganem--Brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Sat Jun  4 18:53:47 2016 Johan Ganem--Brunet
** Last update Mon Jun  6 00:23:58 2016 Mouraud Andrea
*/

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "42sh.h"

int	double_left_redirection(char *function, char *stop, char **env)
{
  int	i;
  char	*s;
  char	**buf;

  i = 1;
  if ((buf = malloc(sizeof(char *) * 4096)) == NULL)
    return (-1);
  buf[0] = function;
  if (stop[0])
    while (42)
      {
	write(1, "> ", 2);
	s = get_next_line(0);
	if (!s || !strcmp(s, stop))
	  break ;
	buf[i++] = s;
      }
  i = -1;
  my_exec(buf, env);
  return (0);
}

int	right_redirection(char *file, char *function, char **env)
{
  int	fd;

  if (file[0] && function[0])
    {
      if ((fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1)
	return (-1);
      if (dup2(fd, 1) == -1)
	return (-1);
      my_exec(my_str_to_wordtab(function), env);
      dup2(0, 1);
      close(fd);
    }
  return (0);
}

int	left_redirection(char *file, char *function, char **env)
{
  int	fd;

  (void)env;
  (void)function;
  if (file == NULL)
    return (0);
  if ((fd = open(file, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP)) == -1)
    return (-1);
  dup2(fd, 0);
  return (0);
}

int	double_right_redirection(char *file, char *function, char **env)
{
  int	fd;

  if (file && function)
    {
      if ((fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644)) == -1)
	return (-1);
      if (dup2(fd, 1) == -1)
	return (-1);
      my_exec(my_str_to_wordtab(function), env);
      dup2(0, 1);
      close(fd);
    }
  return (0);
}
