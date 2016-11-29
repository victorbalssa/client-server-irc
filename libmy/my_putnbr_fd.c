/*
** my_putnbr_fd.c for my_putnbr_fd in /home/balssa_v/my_putnbr_fd
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Fri Oct 23 15:21:26 2015 BALSSA Victor
** Last update Fri Nov 25 19:49:34 2016 BALSSA Victor
*/

#include <unistd.h>

void	my_putstr_fd(int fd, char *str);

void	my_putchar_fd(int fd, char c)
{
  write(fd, &c, 1);
}

void	my_putnbr_fd(int fd, int n)
{
  int	mod;

  if (n < 0)
    {
      if (n == -2147483648)
	my_putstr_fd(fd, "-2147483648");
      else
	{
	  my_putstr_fd(fd, "-");
	  n *= -1;
	}
    }
  if (n >= 0)
    {
      if (n >= 10)
	{
	  mod = n % 10;
	  n = (n - mod) / 10;
	  my_putnbr_fd(fd, n);
	  my_putchar_fd(fd, mod + '0');
	}
      else
	my_putchar_fd(fd, n + '0');
    }
}
