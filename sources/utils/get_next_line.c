/*
** get_next_line.c for  in /home/sepret_f/progelem/CPE_2015_getnextline
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Sun Jan 17 12:14:31 2016 fabrice sepret
** Last update Sun Jun  5 20:03:24 2016 Mouraud Andrea
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "42sh.h"

char		*get_next_line(const int fd)
{
  static s_var	var;

  if (((var.i == 0
	&& (var.r = (int)read(fd, var.buf, READ_SIZE)) < 1))
      || (var.j == 0 && (var.result = malloc(PRINT_MAX)) == NULL))
    return (NULL);
  while (var.i != var.r)
    {
      if (var.buf[var.i] == 0 || var.buf[var.i] == NEWLINE)
	{
	  var.i++;
	  var.result[var.j] = 0;
	  var.j = 0;
	  return (var.result);
	}
      var.result[var.j++] = var.buf[var.i++];
    }
  var.i = 0;
  return (get_next_line(fd));
}
