/*
** my_strcmp.c for my_strcmp in /home/vico/svn01/devc/jour04/balssa_v/my_strcmp
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Thu Oct 22 10:56:21 2015 BALSSA Victor
** Last update Thu Oct 22 11:53:17 2015 BALSSA Victor
*/

int	my_strcmp(char *s1, char *s2)
{
  while (*s1 == *s2)
    {
      if (*s1 == '\0')
	return (0);
      s1++;
      s2++;
    }
  return ((*s1 < *s2) ? -1 : +1);
}
