/*
** check_prog.c for 42sh in /home/mourau_a/PSU_2015_42sh/sources/shell
**
** Made by Mouraud Andrea
** Login   <mourau_a@epitech.net>
**
** Started on  Sun Jun  5 20:25:29 2016 Mouraud Andrea
** Last update Sun Jun  5 20:35:55 2016 Mouraud Andrea
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "42sh.h"

bool	check_str(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    {
      printf("%d\n", str[i]);
      if (str[i] < 0 || str[i] > 126)
        return (false);
    }
  return (true);
}

int	check_separator(char **tab, char **env, int *i)
{
  (void)i;
  if (!strcmp(tab[0], S_SEP));
  else if (!strcmp(tab[0], S_AND) && g_pid > 0)
    return (-1);
  else if (!strcmp(tab[0], OR) && g_pid == 0)
    return (-1);
  else if (!strcmp(tab[0], S_AND));
  else if (!strcmp(tab[0], OR));
  else
    {
      g_pid = exec_cmd(tab, env);
      wait(&g_pid);
      detect_signal();
    }
  return (0);
}

char	*fuction_redirect(char *tab)
{
  int	i;
  int	j;
  char	*ret;

  i = 0;
  j = 0;
  if ((ret = malloc(sizeof(char) * strlen(tab))) == NULL)
    return (NULL);
  while (tab[i] != SPACE)
    i += 1;
  i += 1;
  while (tab[i] != 0)
    ret[j++] = tab[i++];
  ret[j] = 0;
  return (ret);
}

int	real_check(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] != LEFT && str[i] != RIGHT && str[i] != PIPE
          && str[i] != AND && str[i] != SEPARATOR)
        return (1);
      i += 1;
    }
  return (0);
}
