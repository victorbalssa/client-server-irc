/*
** my_putstr_fd.c for my_putstr_fd in /home/balssa_v/my_putstr
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Wed Oct 21 09:19:12 2015 BALSSA Victor
** Last update Fri Nov 25 17:49:09 2016 BALSSA Victor
*/

#include <unistd.h>

void	my_putstr_fd(int fd, char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      write(fd, &str[i], 1);
      i++;
    }
}
