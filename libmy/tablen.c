/*
** tablen.c for tablen in /home/balssa_v/tablen
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Fri Nov 25 19:50:42 2016 BALSSA Victor
** Last update Fri Nov 25 19:51:33 2016 BALSSA Victor
*/

int	tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
