/*
** my_putstr.c for my_putstr in /home/vico/svn01/devc/jour03/balssa_v/my_putstr
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Wed Oct 21 09:19:12 2015 BALSSA Victor
** Last update Sat Oct 24 14:26:18 2015 BALSSA Victor
*/

void	my_putchar(char c);

void	my_putstr(char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str++;
    }
}
