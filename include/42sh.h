/*
** 42sh.h for 42sh in /home/gassem_a/PSU/PSU_2015_42sh
**
** Made by Aurélien Gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Sun Jun  5 16:41:33 2016 Aurélien Gassemann
// Last update Sun Jun  5 20:33:49 2016 Mouraud Andrea
*/

#ifndef		MY_H_
# define	MY_H_

#include	<stdbool.h>
#include	"pars.h"
#include	"verbose.h"

int		g_pid;
int		g_exit;

typedef struct	s_shell
{
  int		i;
  int		j;
  int		k;
  char		*path;
  char		**ret;
}		t_shell;

typedef struct	s_args
{
  bool		newline;
  bool		backslash;
}		t_args;

void		loop_pipe(char ***cmd, char **env);
void		free_tab(char ***tab);
void		free_word(char **tab);
void		detect_signal(void);
void		xunsetenv(char **args, char ***env);
void		disp_env(char ***env);
void		my_cd(char *dir, char ***env);
void		xsetenv(char **args, char ***env);
bool		check_str(char *str);
bool		my_builtins(char ****tab, char ***env, int i);
int		check_separator(char **tab, char **env, int *i);
int		real_check(char *str);
int		check_invalid(char *new, int i);
int		check_string(char *str);
int		exec_cmd(char **tab, char **env);
int		my_exec(char **tab, char **env);
int		get_prompt();
int		right_redirection(char *file, char *function, char **env);
int		left_redirection(char *file, char *function, char **env);
int		double_right_redirection(char *file, char *function, char **env);
int		double_left_redirection(char *stop, char *function, char **env);
int		my_prog(char **env);
int		my_strcmp(char *s1, char *s2);
int		detect_pipe(char **tab);
int		my_putchar(char c);
int		my_exec(char **tab, char **env);
int		check_invalid(char *new, int i);
int		setlol(char **args, char ***env);
int		echo(char *str);
int		my_exit(const char *s);
int		shell(char *str, char **env);
int		tablen(char **tab);
int		exec_pipe(char **tab, char **env);
int		epur_tab(t_par *par);
int		return_tab(t_par *par);
int		init_struct(t_par *par, int);
int		exec_pipe(char **tab, char **env);
int		exec_pipe(char **tab, char **env);
int		separate_sep(char *str, t_par *par);
char		*fuction_redirect(char *tab);
char		*add_double(char c, int *i, int *k);
char		*add_simple(char c, int *i, int *k);
char		*init_str(char *str);
char		*epur_str(char *s);
char		*without_space(char *str);
char		*fuction_redirect(char *tab);
char		*clear_str(char*str);
char		**get_path(char **env);
char		**check_env(char **environ);
char		**my_str_to_wordtab(char *str);
char		**str_to_wordtab(char *str, char c);
char		**separate2(char *str, t_par *par);
char		***parser(char *str);
char		***parser_pipe(char **tab);

#endif		/* !MY_H_ */
