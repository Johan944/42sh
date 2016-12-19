/*
** free_tab.c for  in /home/ganem-_j/PSU_2015_42sh/new
**
** Made by Johan Ganem--Brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Wed Jun  1 12:03:32 2016 Johan Ganem--Brunet
** Last update Sun Jun  5 01:22:11 2016 sereptf
*/

#include <stdlib.h>

void	free_word(char **tab)
{
  int	i;

  i = 0;
  if (tab == NULL)
    return ;
  while (tab[i])
    free(tab[i++]);
}

void	free_tab(char ***tab)
{
  int	i;
  int	j;

  i = 0;
  if (tab == NULL)
    return ;
  while (tab[i])
    {
      j = 0;
      while (tab[i][j])
	free(tab[i][j++]);
      free(tab[i++]);
    }
  free(tab);
}
