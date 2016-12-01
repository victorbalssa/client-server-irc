/*
** my_str_to_wordtab.c for my_irc in /Users/victorbalssa/my_irc
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Wed Nov 23 14:57:32 2016 BALSSA Victor
** Last update Wed Nov 23 15:10:45 2016 BALSSA Victor
*/

#include	"serveur.h"

int		tablen(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

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

int		count_word(char *str, char separe)
{
  int		i;
  int		count;

  i = 0;
  count = 1;
  while (str[i] == ' ' || str[i] == '\t' || str[i] == separe)
    i++;
  while (str[i])
    {
      if (str[i] == ' ' || str[i] == '\t' || str[i] == separe)
	{
	  while (str[i] == ' ' || str[i] == '\t' || str[i] == separe)
	    i++;
	  if (str[i])
	    count++;
	}
      if (str[i])
	i++;
    }
  return (count);
}

char		**my_str_to_wordtab(char *str, char separe)
{
  char		**tab;
  int		i;
  int		j;
  int		k;

  i = 0;
  j = 0;
  if ((tab = malloc(sizeof(*tab) * ((count_word(str, separe) + 1)))) == NULL)
    perror("Malloc() fail.");
  while (str[i] == '\t' || str[i] == ' ' || str[i] == separe)
    i++;
  while (str[i])
    {
      if ((tab[j] = malloc(sizeof(**tab) * (my_strlen(str) + 1))) == NULL)
	perror("Malloc() fail.");
      k = 0;
      while (str[i] != ' ' && str[i] != '\t' && str[i] != separe && str[i])
        tab[j][k++] = str[i++];
      tab[j++][k] = '\0';
      while (str[i] == ' ' || str[i] == '\t' || str[i] == separe)
	i++;
    }
  tab[j] = NULL;
  return (tab);
}
