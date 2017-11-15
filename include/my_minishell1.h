/*
** my_minishell1.h for  in /PSU_2015_minishell1/include
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Mar 17 14:09:26 2016 David Munoz
** Last update Thu Mar 31 00:45:33 2016 David Munoz
*/

#ifndef		MY_MINISHELL1_H_
# define	MY_MINISHELL1_H_

#include <sys/types.h>
#include <sys/wait.h>
#include <termios.h>
#include <ncurses.h>
#include <unistd.h>
#include <signal.h>
#include <dirent.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

# define RED                    "\033[1;31m"
# define GREEN                  "\033[1;32m"
# define PURPLE                 "\033[1;35m"
# define CYAN                   "\033[1;36m"
# define BROWN                  "\033[0;33m"
# define BLUE                   "\033[1;34m"
# define YELLOW                 "\033[1;33m"
# define BLANK                  "\033[0m"

/*
**	my_path.c
*/
char	**my_put_in_path(int i, char **path, char **env);
char	**my_pars_path(char **env);

/*
**	my_free.c
*/
int     err_int(char *msg, int status);
void	my_free(char **path, char **av);
void	my_free_env(char **env);

/*
**	my_fonctions.c
*/
void	my_prompt();
void	erx(char *str, int err);
void	*my_malloc(int size);
int	my_check_end(char *str);

/*
**	my_command.c
*/
int	my_cmd_strncmp(char *buff);
void	my_command(char *buff, char **env);
char	**my_put_in_command(char *buff_com, char **command);
char	**my_nb_command(char *buff_com);
int	my_pars_command(char *buff_com, char **env);


/*
**	my_av.c
*/
char	**my_put_in_av(char **buff, char **av, int tmp);
char	**my_ini_av(char **buff);

/*
**	my_exe.c
*/
char	*my_ini_exe(char *name, char *path);
void	my_exe_command(char *exe, char **av, char **env);
void	my_cd(char *buff);

/*
**	signal.c
*/
void	signal_quit();
void	signal_int();

/*
**	main.c
*/

#endif /* MY_MINISHELL1_ ! */
