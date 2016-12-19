/*
** tablen.c for  in /home/ganem-_j/PSU_2015_42sh/sources
**
** Made by Johan Ganem--Brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Sat Jun  4 18:03:13 2016 Johan Ganem--Brunet
** Last update Sun Jun  5 20:02:30 2016 Mouraud Andrea
*/

#include <unistd.h>

int	my_putchar(char c)
{
  return (write(1, &c, 1));
}

int	tablen(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i]);
  return (i);
}
