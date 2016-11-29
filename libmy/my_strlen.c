/*
** my_strlen.c for my_strlen in /home/vico/svn01/devc/jour03/balssa_v
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Wed Oct 21 09:34:50 2015 BALSSA Victor
** Last update Sat Oct 24 14:21:08 2015 BALSSA Victor
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (*(str + i) != '\0')
    {
      i++;
    }
  return (i);
}
