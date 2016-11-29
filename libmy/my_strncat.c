/*
** my_strncat.c for  my_strncat in /home/vico/svn01/devc/jour04/balssa_v/my_strncat
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Thu Oct 22 14:40:33 2015 BALSSA Victor
** Last update Sat Oct 24 14:23:05 2015 BALSSA Victor
*/

int	my_strlen(char *str);

char	*my_strcpy(char *dest, char *src);

char	*my_strncpy(char *dest, char *src, int n);

char	*my_strncat(char *str1, char *str2, int n)
{
  int	l1;
  int	l2;

  l1 = my_strlen(str1);
  l2 = my_strlen(str2);
  if (l2 < n)
    {
      my_strcpy(&str1[l1], str2);
    }
  else
    {
      my_strncpy(&str1[l1], str2, n);
      str1[l1 + n] = '\0';
    }
  return (str1);
}
