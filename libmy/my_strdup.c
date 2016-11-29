/*
** my_strdup.c for my_strdup in /home/vico/devc/jour07/balssa_v/my_strdup
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Mon Oct 26 10:54:06 2015 BALSSA Victor
** Last update Mon Oct 26 16:47:51 2015 BALSSA Victor
*/

#include <stdlib.h>

int	my_strlen(char *str);

char	*my_strcpy(char *dest, char *src);

char	*my_strdup(char *str)
{
  char	*str2;

  str2 = malloc((my_strlen(str) + 1) * sizeof(char));
  str2 = my_strcpy(str2, str);
  return (str2);
}
