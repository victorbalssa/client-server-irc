/*
** my_bzero.c for libmy in balssa_v/libmy
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Sat Apr  9 20:48:24 2016 BALSSA Victor
** Last update Sat Apr  9 20:49:03 2016 BALSSA Victor
*/

void	my_bzero(void *s1, int n)
{
  char	*t;

  t = (char *)s1;
  while (n != 0)
    {
      *t++ = 0;
      n--;
    }
}
