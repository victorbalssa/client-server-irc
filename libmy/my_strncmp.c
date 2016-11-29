/*
** my_strncmp.c for  my_strncmp in /home/vico/svn01/devc/jour04/balssa_v/my_strncmp
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Thu Oct 22 13:36:23 2015 BALSSA Victor
** Last update Thu Oct 22 14:05:22 2015 BALSSA Victor
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  while (n > 0)
    {
      if (*s1 != *s2)
	return ((*s1 < *s2) ? -1 : +1);
      else if (*s1 == '\0')
	return (0);
      s1++;
      s2++;
      n--;
    }
  return (0);
}
