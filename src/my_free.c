/*
** my_free.c for q in /rendu_ProgShell/PSU_2015_minishell1/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Mar 31 01:00:33 2016 David Munoz
** Last update Thu Mar 31 14:26:48 2016 David Munoz
*/
#include	"my.h"
#include	"my_minishell1.h"

int	err_int(char *msg, int status)
{
  write(2, msg, my_strlen(msg));
  return (status);
}

/* int	err_tab2D(char *msg, char status) */
/* { */
/*   write(2, msg, my_strlen(msg)); */
/*   return (status); */
/* } */

void		my_free(char **path, char **av)
{
  int		i;

  i = -1;
  while (path[++i] != NULL)
    free(path[i]);
  free(path);
  i = -1;
  while (av[++i] != NULL)
    free(av[i]);
  free(av);
}

void		my_free_env(char **env)
{
  int		i;

  i = 0;
  while (env[i] != NULL)
    {
      free(env[i]);
      i++;
    }
  free(env);
}
