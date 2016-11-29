/*
** my_putchar.c for my_putchar_main in /home/balssa_v/my_putchar
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Mon Oct 19 10:58:27 2015 BALSSA Victor
** Last update Fri Nov 25 17:48:50 2016 BALSSA Victor
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
