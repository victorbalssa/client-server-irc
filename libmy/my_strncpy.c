/*
** my_strncpy.c for my_strncpy in /home/vico/svn01/devc/jour04/balssa_v/my_strncpy
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Thu Oct 22 10:27:13 2015 BALSSA Victor
** Last update Thu Oct 22 10:37:48 2015 BALSSA Victor
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  char	*tmp;

  tmp = dest;
  while (n > 0 && *src != '\0')
    {
      *tmp++ = *src++;
      n--;
    }
  while (n > 0)
    {
      *tmp++ = 0;
      n--;
    }
  return (dest);
}
