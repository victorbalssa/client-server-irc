/*
** my_swap.c for my_swap in /home/vico/svn01/devc/jour03/balssa_v/my_swap
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Wed Oct 21 11:32:44 2015 BALSSA Victor
** Last update Sat Oct 24 14:28:45 2015 BALSSA Victor
*/

void	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
}
