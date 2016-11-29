/*
** my_strcpy.c for my_strcpy in /home/vico/svn01/devc/jour04/balssa_v/my_strcpy
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Thu Oct 22 09:55:17 2015 BALSSA Victor
** Last update Fri Oct 23 17:36:45 2015 BALSSA Victor
*/

char	*my_strcpy(char *dest, char *src)
{
  char	*tmp;

  tmp = dest;
  while (*src != '\0')
    {
      *tmp = *src;
      tmp++;
      src++;
    }
  *tmp = 0;
  return (dest);
}
