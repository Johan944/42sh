/*
** my_cd.c for  in /home/ganem-_j/PSU_2015_42sh/new
**
** Made by Johan Ganem--Brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Wed Jun  1 11:07:10 2016 Johan Ganem--Brunet
** Last update Sun Jun  5 19:48:40 2016 Mouraud Andrea
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "42sh.h"

char	*my_strcat(char *str1, char *str2)
{
  int	i;
  int	j;
  char	*result;

  i = -1;
  j = -1;
  if ((result = malloc(sizeof(char *) * strlen(str1)
		       + strlen(str2) + 1)) == NULL)
    return (NULL);
  while (str1[++i])
    result[i] = str1[i];
  while (str2[++j])
    result[i++] = str2[j];
  result[i] = 0;
  return (result);
}

void	cd_dash(char new[500], char old[500], char ***env)
{
  int	i;
  int	j;
  int	k;
  char	*buf;

  i = 0;
  k = 0;
  j = 7;
  while (env[0][i])
    {
      if (!strncmp(env[0][i++], OLDPWD, 7))
	while (env[0][i - 1][j])
	  old[k++] = env[0][i - 1][j++];
      old[k] = 0;
    }
  buf = my_strcat(SET_OLDPWD, getcwd(new, 500));
  xsetenv(str_to_wordtab(buf, SPACE), env);
  chdir(old);
}

int	no_dir(char new[500], char ***env)
{
  int	i;
  int	k;
  int	j;
  char	*home;
  char	*buf;

  i = 0;
  k = 0;
  j = 5;
  if ((home = malloc(sizeof(char) * 150)) == NULL)
    return (-1);
  while (env[0][i])
    {
      if (!strncmp(env[0][i++], HOME, 5))
	while (env[0][i - 1][j])
	  home[k++] = env[0][i - 1][j++];
      home[k] = 0;
    }
  buf = my_strcat(SET_OLDPWD, getcwd(new, 500));
  xsetenv(str_to_wordtab(buf, SPACE), env);
  !home[0] ? fprintf(stderr, NO_HOME) : chdir(home);
  return (0);
}

void	my_cd(char *dir, char ***env)
{
  char	old[500];
  char	new[500];
  char	*buf;

  if (!dir)
    no_dir(new, env);
  else if (dir && !strcmp(dir, DASH))
    cd_dash(new, old, env);
  else
    {
      buf = my_strcat(SET_OLDPWD, getcwd(new, 500));
      xsetenv(str_to_wordtab(buf, SPACE), env);
      if (chdir(dir) == -1)
	{
	  g_pid = 256;
	  fprintf(stderr, NO_PERMISSION, dir);
	}
    }
}
