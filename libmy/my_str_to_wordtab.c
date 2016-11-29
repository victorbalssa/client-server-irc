/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/vico/devc/jour07/balssa_v/my_str_to_wordtab
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Mon Oct 26 11:25:37 2015 BALSSA Victor
** Last update Wed Feb 17 16:13:47 2016 BALSSA Victor
*/

#include <unistd.h>
#include <stdlib.h>

char	*my_strncpy(char *dest, char *src, int n);

int	nb_word(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (str[i++] != '\0')
    if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')
	|| (str[i] >= '0' && str[i] <= '9'))
      {
	nb++;
	while ((str[i] >= 'A' && str[i] <= 'Z')
	       || (str[i] >= 'a' && str[i] <= 'z')
	       || (str[i] >= '0' && str[i] <= '9'))
	  i++;
      }
  return (nb);
}

int	nb_alpha(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')
	 || (str[i] >= '0' && str[i] <= '9'))
    {
      i++;
      nb++;
    }
  return (nb);
}

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	n;
  int	nb_wd;
  char	**t;

  n = 0;
  i = 0;
  nb_wd = nb_word(str);
  if (!(t = malloc((nb_wd + 1) * sizeof(char *))))
    return (0);
  while (nb_wd > 0)
    {
      if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')
	  || (str[i] >= '0' && str[i] <= '9'))
	{
	  t[n] = malloc(nb_alpha(str + i) * sizeof(char));
	  t[n] = my_strncpy(t[n], (str + i), nb_alpha(str + i));
	  i += nb_alpha(str + i);
	  n++;
	  nb_wd--;
	}
      else
	i++;
    }
  t[n] = NULL;
  return (t);
}
