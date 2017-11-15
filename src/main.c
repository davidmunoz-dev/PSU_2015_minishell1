/*
** main.c for  in /PSU_2015_minishell1/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Mar 17 15:53:00 2016 David Munoz
** Last update Thu Mar 31 00:21:22 2016 David Munoz
*/

#include	"my.h"
#include	"my_minishell1.h"

int	main(int ac, char **av, char **environ)
{
  char	buff_com[8192];
  int	nb;

  (void) ac;
  (void) av;
  signal(SIGINT, my_prompt);
  signal(SIGTSTP, my_prompt);
  while (1)
    {
      my_putstr(GREEN"$> "BLANK);
      nb = read(0, buff_com, 8192);
      buff_com[nb] = '\0';
      if ((nb = my_check_end(buff_com)) == 1)
        return (err_int("No char\n", 0));
      else if (buff_com[0] != '\n')
        my_pars_command(buff_com, environ);
    }
  my_free_env(environ);
}
