/*
** my_put_nbr.c for my_put_nbr in /home/vico/devc/jour05/balssa_v
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Fri Oct 23 15:21:26 2015 BALSSA Victor
** Last update Sat Oct 24 14:48:05 2015 BALSSA Victor
*/

void	my_putchar(char c);

void	my_putstr(char *str);

void	my_put_nbr(int n)
{
  int	mod;

  if (n < 0)
    {
      if (n == -2147483648)
	my_putstr("-2147483648");
      else
	{
	  my_putchar('-');
	  n *= -1;
	}
    }
  if (n >= 0)
    {
      if (n >= 10)
	{
	  mod = n % 10;
	  n = (n - mod) / 10;
	  my_put_nbr(n);
	  my_putchar(mod + '0');
	}
      else
	my_putchar(n + '0');
    }
}
