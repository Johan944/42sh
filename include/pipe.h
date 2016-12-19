/*
** pipe.h for  in /home/ganem-_j/PSU_2015_42sh
**
** Made by Johan Ganem--Brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Sun Jun  5 21:36:09 2016 Johan Ganem--Brunet
// Last update Sun Jun  5 23:55:13 2016 Mouraud Andrea
*/

#ifndef		PIPE_H_
# define	PIPE_H_

typedef	struct	s_pip
{
  int		p[2];
  int		fd_in;
  pid_t		pid;
}		t_pip;

#endif		/* !PIPE_H_ */
