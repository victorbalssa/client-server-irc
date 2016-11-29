/*
** my_strstr.c for my_strstr in balssa_v/my_strstr
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Thu Oct 22 17:34:04 2015 BALSSA Victor
** Last update Sat Apr  9 19:39:00 2016 BALSSA Victor
*/

#include <string.h>

char	*my_strstr(char *s1, char *s2)
{
  int	i;
  int	j;
  int	a;

  i = 0;
  j = 0;
  if (s2[i] == '\0')
    return ((char*)s1);
  while (s1[i])
    {
      if (s1[i] == s2[j])
	{
	  a = i;
	  while (s1[a] == s2[j] && s1[a] != '\0' && s2[j] != '\0')
	    {
	      a++;
	      j++;
	    }
	  if (s2[j] == '\0')
	    return ((char*)(s1 + i));
	  j = 0;
	}
      i++;
    }
  return (NULL);
}
