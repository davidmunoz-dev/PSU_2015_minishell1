/*
** my_av.c for  in /PSU_2015_minishell1/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Mar 31 00:59:19 2016 David Munoz
** Last update Thu Mar 31 13:25:35 2016 David Munoz
*/

#include	"my.h"
#include	"my_minishell1.h"

/*
** Parse la tableau char **av;
*/
char		**my_put_in_av(char **buff, char **av, int tmp)
{
  int		i;
  int		j;
  int		k;
  int		a;

  i = k = -1;
  j = 0;
  a = 1;

  while ((*buff)[++i] != '\0')
    {
    if ((*buff)[i] >= 33 && (*buff)[i] <= 126)
      {
        a = 0;
        av[j][++k] = (*buff)[i];
      }
    else if (a == 0)
      {
        a = 1;
        av[j][++k] = '\0';
        k = -1;
        j++;
      }
    }
  (*buff)[tmp] = '\0';
  return (av);
}

/*
** Parse les commandes dans un char** av;
** Ex: ls; pwd; cat *;
** 3 commandes dans une ligne
** Cette fonction les coupes en 3commandes/lignes
*/
char		**my_ini_av(char **buff)
{
  int		i;
  int		nb;
  int		tmp;
  char		**av;

  i = 0;
  nb = 0;
  while ((*buff)[i] >= 33 && (*buff)[i] <= 126)
    i++;
  tmp = i;
  i--;
  while ((*buff)[++i] != '\0')
    if ((*buff)[i] == ' ' && (*buff)[i + 1] >= 33 && (*buff)[i + 1] <= 126)
      nb++;
  av = my_malloc(sizeof(char *) * (nb + 2));
  i = -1;
  while (++i < nb + 1)
    av[i] = my_malloc(sizeof(char) * (my_strlen(*buff) + 1));
  av[i] = NULL;
  av = my_put_in_av(buff, av, tmp);
  return (av);
}
