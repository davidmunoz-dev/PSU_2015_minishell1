/*
** my_path.c for  in /rendu_ProgShell/PSU_2015_minishell1/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Mar 31 00:46:03 2016 David Munoz
** Last update Thu Mar 31 13:41:25 2016 David Munoz
*/

#include	"my.h"
#include	"my_minishell1.h"

/*
** Parse le tableau du PATH
*/
char		**my_put_in_path(int i, char **path, char **env)
{
  int		j;
  int		k;
  int		nb;

  j = 4;
  k = -1;
  nb = 0;
  while (env[i][++j] != '\0')
    {
    if (env[i][j] == ':')
      {
        path[nb][++k] = '\0';
        nb++;
        k = -1;
      }
    else
      path[nb][++k] = env[i][j];
    }
  return (path);
}

/*
** Creer le tableau du PATH
*/
char		**my_pars_path(char **env)
{
  char		**path;
  int		i;
  int		j;
  int		k;
  int		nb;

  i = 0;
  while (my_strncmp("PATH=", env[i], 5) != '\0')
    i++;
  j = -1;
  nb = 0;
  while (env[i][++j] != '\0')
    if (env[i][j] == ':')
      nb++;
  path = my_malloc(sizeof(char *) * (nb + 2));
  k = -1;
  while (++k < nb + 1)
    path[k] = my_malloc(sizeof(char) * my_strlen(env[i]));
  path[nb + 1] = NULL;
  path = my_put_in_path(i, path, env);
  return (path);
}
