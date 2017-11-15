#include	"my.h"
#include	"my_minishell1.h"

/*
** Recupere le path et rajoute la commande au bout
** Ex: $>ls     =    /bin/ls
*/
char		*my_ini_exe(char *name, char *path)
{
  char		*exe;
  int		i;
  int		j;

  exe = my_malloc(sizeof(char) * (my_strlen(name) + my_strlen(path) + 2));
  i = -1;
  j = -1;
  while (path[++i] != '\0')
    exe[++j] = path[i];
  exe[++j] = '/';
  i = 0;
  while (name[i] < 33 || name[i] > 126)
    i++;
  i--;
  while (name[++i] != '\0')
    exe[++j] = name[i];
  exe[++j] = '\0';
  return (exe);
}

/*
** Duplique le processus pour executer la commande
*/
void		my_exe_command(char *exe, char **av, char **env)
{
  pid_t		pid;

  pid = fork();
  if (pid > 0)
    wait(NULL);
  else if (pid == 0)
    if (execve(exe, av, env) == -1)
      exit(0);
}

/*
** Recode de la fonction 'cd'
*/
void		my_cd(char *buff)
{
  char		*str;
  int		i;
  int		j;

  str = my_malloc(sizeof(char) * my_strlen(buff));
  i = -1;
  while (buff[++i] != ' ' && buff[i] != '\n');
  if (buff[i] == '\n')
    {
      my_printf("%s : not a directory\n", str);
      return;
    }
  j = -1;
  while (buff[++i] != ' ' && buff[i] != '\n')
    str[++j] = buff[i];
  str[++j] = 0;
  if (str[0] == 0 || chdir(str) == -1)
    my_printf("%s : not a directory\n", str);
  free(str);
}
