/*
** get_next_line.h for  in /home/sepret_f/progelem/CPE_2015_getnextline
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Sun Jan 17 12:15:06 2016 fabrice sepret
// Last update Sun Jun  5 19:34:46 2016 Mouraud Andrea
*/

#ifndef		GET_NEXT_LINE_H_
# define	GET_NEXT_LINE_H_

# define	READ_SIZE (10)
# define	PRINT_MAX (4096)

typedef struct	t_var
{
  int		i;
  int		j;
  int		k;
  int		r;
  char		buf[READ_SIZE];
  char		*result;
}		s_var;

char		*get_next_line(const int fd);

#endif		/* !GET_NEXT_LINE_H_ */
