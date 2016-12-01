/*
** freetab.c for freetab in /Users/victorbalssa/freetab
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Thu Dec  1 21:11:40 2016 BALSSA Victor
** Last update Thu Dec  1 21:13:51 2016 BALSSA Victor
*/

#include	<stdlib.h>

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      free (tab[i]);
      i++;
    }
  free(tab);
}
