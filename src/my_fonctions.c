/*
** my_fonctions.c for  in /rendu_ProgShell/PSU_2015_minishell1/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Mar 31 01:00:18 2016 David Munoz
** Last update Thu Mar 31 01:00:25 2016 David Munoz
*/
#include	"my.h"
#include	"my_minishell1.h"


/*
** Prompt ecrit en vert "$>"
*/
void	my_prompt()
{
  my_putstr(GREEN"\n$> "BLANK);
}

/*
** Ecrit un message et renvoi une erreur
*/
void	erx(char *str, int err)
{
  my_putstr(str);
  exit(err);
}

/*
** Verifie les mallocs
*/
void	*my_malloc(int size)
{
  void	*memory;

  if ((memory = malloc(size)) == NULL)
    {
      my_printf("Error : Wrong alloc\n");
      exit(0);
    }
  return (memory);
}

/*
** Check s'il y a bien un '\n' dans la commande
** c'est à dire que l'utilisateur a rentrer une
** commande avec "entrée"
*/
int    	my_check_end(char *str)
{
  int		i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == '\n')
	return (0);
      i++;
    }
  return (1);
}
