/*
** my_command.c for q in /rendu_ProgShell/PSU_2015_minishell1/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Mar 31 00:59:40 2016 David Munoz
** Last update Thu Mar 31 14:26:12 2016 David Munoz
*/
#include	"my.h"
#include	"my_minishell1.h"

/*
** STRNCMP du 'cd' et 'exit'
*/
int		my_cmd_strncmp(char *buff)
{
  if (my_strncmp("cd", buff, 2) == 0)
    {
      my_cd(buff);
      return (1);
    }
  if (my_strncmp("exit", buff, 4) == 0)
    exit(1);
  return (0);
}

/*
** Parse les commandes, recupere le path
** puis execute les commandes
*/
void		my_command(char *buff, char **env)
{
  char		**path;
  char		**av;
  char		*exe;
  int		i;
  int		cmd;

  i = 0;
  if ((cmd = my_cmd_strncmp(buff)) == 1)
    return;
  av = my_ini_av(&buff);
  path = my_pars_path(env);
  exe = my_ini_exe(buff, path[i]);
  while (access(exe, X_OK) != 0 && path[i] != NULL)
    if (path[++i] != NULL)
      exe = my_ini_exe(buff, path[i]);
  if (path[i] != NULL)
    {
      my_exe_command(exe, av, env);
      free(exe);
    }
  else
    my_printf("%s : command not found\n", buff);
  my_free(path, av);
}

/*
** Chaque commande qui contient un ';' a la fin
** est enlevé pour pouvoir etre executé par le BIN
** Gère aussi les '!' et '~'
*/
char		**my_put_in_command(char *buff_com, char **command)
{
  int	i;
  int  	j;
  int	k;
  int	a;

  i = k = -1;
  j = a = 0;
  while (buff_com[++i] != '\0')
    if (i != 0 && buff_com[i] == ';')
      {
        command[j][++k] = ' ';
        command[j][++k] = '\0';
        k = -1;
        j++;
        a = 0;
      }
    else if (a == 1 || (buff_com[i] >= 33 && buff_com[i] <= 126 && buff_com[i] != ';'))
      {
        command[j][++k] = buff_com[i];
        a = 1;
      }
  command[j][++k] = 0;
  return (command);
}

/*
** Compte le nombre de commandes ';' et les mets
** dans un char** + malloc
** Elle renvoi les commandes exactes a interprétés
** par le bin
*/
char		**my_nb_command(char *buff_com)
{
  char		**command;
  int		i;
  int		nb;

  i = 0;
  nb = 0;
  while (buff_com[i] != '\0')
    {
      if (i != 0 && buff_com[i] == ';' && buff_com[i - 1] != ';')
	nb++;
      else if ((buff_com[0] == ';')
	       || (buff_com[i] == ';' && buff_com[i-1] == ';'))
    {
      my_putstr("bash: Erreur de syntaxe près du symbole « ; » \n");
      return (NULL);
    }
      i++;
    }
  command = my_malloc(sizeof(char *) * (nb + 2));
  i = 0;
  while (i <= nb)
    {
      command[i] = my_malloc(sizeof(char) * (my_strlen(buff_com) + 1));
      i++;
    }
  command[i] = NULL;
  command = my_put_in_command(buff_com, command);
  return (command);
}

/*
** Parse commandes et envoi chaque commande clean
** au bin afin d'etre executer
*/
int	my_pars_command(char *buff_com, char **env)
{
  char	**command;
  int	i;

  if ((command = my_nb_command(buff_com)) == NULL)
    return (1);
  i = 0;
  while (command[i] != NULL)
    {
      if (command[i][0] != 0)
	my_command(command[i], env);
      i++;
    }
  return (0);
}
