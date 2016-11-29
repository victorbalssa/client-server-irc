/*
** my_strcat.c for my_strcat in /home/vico/svn01/devc/jour04/balssa_v/my_strcat
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Thu Oct 22 14:21:26 2015 BALSSA Victor
** Last update Sat Oct 24 14:20:23 2015 BALSSA Victor
*/

int	my_strlen(char *str);

char	*my_strcpy(char *dest, char *src);

char	*my_strcat(char *str1, char *str2)
{
  my_strcpy(&str1[my_strlen(str1)], str2);
  return (str1);
}
