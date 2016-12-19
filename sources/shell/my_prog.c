/*
** my_prog.c for  in /home/ganem-_j/PSU_2015_42sh/sources
**
** Made by Johan Ganem--Brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Sat Jun  4 18:53:37 2016 Johan Ganem--Brunet
** Last update Sun Jun  5 23:49:22 2016 Mouraud Andrea
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "get_next_line.h"
#include "42sh.h"

int	my_exec(char **tab, char **env)
{
  int	pid;
  int	idx;
  char	**path;

  if (tab == NULL)
    return (-1);
  path = get_path(env);
  idx = 0;
  if ((pid = fork()) == 0)
    {
      execve(tab[0], tab, env);
      if (path)
	while (path[idx])
	  {
	    if (tab[0][0] != DOT && tab[0][0] != N_SLASH)
	      execve(strcat(path[idx], tab[0]), tab, env);
	    idx++;
	  }
      fprintf(stderr, NOT_FOUND, tab[0]);
      exit(1);
    }
  return (pid);
}

int	exec_cmd(char **tab, char **env)
{
  if (detect_pipe(tab) == 1)
    loop_pipe(parser_pipe(tab), env);
  else if (my_strcmp(tab[0], ">") == 0)
    right_redirection(tab[1], tab[2], env);
  else if (my_strcmp(tab[1], ">") == 0)
    right_redirection(tab[2], tab[0], env);
  else if (my_strcmp(tab[0], ">>") == 0)
    double_right_redirection(tab[1], tab[2], env);
  else if (my_strcmp(tab[1], ">>") == 0)
    double_right_redirection(tab[2], tab[0], env);
  else if (my_strcmp(tab[0], "<") == 0)
    left_redirection(tab[1], tab[2], env);
  else if (my_strcmp(tab[1], "<") == 0)
    left_redirection(tab[2], tab[0], env);
  else if (my_strcmp(tab[0], "<<") == 0)
    double_left_redirection(tab[1], tab[2], env);
  else if (my_strcmp(tab[1], "<<") == 0)
    double_left_redirection(tab[2], tab[0], env);
  else
    my_exec(my_str_to_wordtab(tab[0]), env);
  return (0);
}

void	detect_signal(void)
{
  if (WIFSIGNALED(g_pid))
    {
      if (WTERMSIG(g_pid) == SIGSEGV)
	fprintf(stderr, SEGFAULT);
      else if (WTERMSIG(g_pid) == SIGFPE)
	fprintf(stderr, FLOATING);
    }
}

int	shell(char *str, char **env)
{
  int	i;
  char	***tab;
  char	**wordtab;

  i = -1;
  if ((tab = parser(str)) == NULL)
    return (0);
  if (tab[0])
    while (tab[++i])
      {
	if ((wordtab = my_str_to_wordtab(tab[i][0])) == NULL)
	  break ;
	if (my_strcmp(wordtab[0], "exit") == 0)
	  return (my_exit(my_str_to_wordtab(tab[i][0])[1]));
	else if (!my_builtins(&tab, &env, i))
	  if (check_separator(tab[i], env, &i) == -1)
	    break ;
      }
  return (0);
}

int	my_prog(char **env)
{
  char	*str;
  int	val_ret;

  get_prompt();
  while ((str = get_next_line(0)) != NULL)
    {
      if (str[0] != '\0')
	str = clear_str(str);
      if (real_check(str) == 1)
	{
	  if (str[0] || !check_str(str))
	    val_ret = shell(str, env);
	}
      if (val_ret != 0)
	{
	  if (val_ret == -1)
	    val_ret = 0;
	  break ;
	}
      free(str);
      get_prompt();
    }
  write(isatty(1), "exit\n", 5);
  return (val_ret);
}
