/*
** lib_client.c for my_irc in /Users/victorbalssa/my_irc
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Wed Nov 23 15:04:08 2016 BALSSA Victor
** Last update Fri Nov 25 22:28:27 2016 BALSSA Victor
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"client.h"

int		get_first_cmd()
{
  char		buff[BUFF_SIZE];
  char		**tmp;
  char		**tmp2;
  int		i;

  while (42)
    {
      write(1, "/> ", 3);
      i = read(0, buff, BUFF_SIZE);
      if (i > 0)
	{
	  buff[i] = '\0';
	  tmp = my_str_to_wordtab(buff, ' ');
	  if (tablen(tmp) == 2 && my_strcmp(tmp[0], "/server") == 0)
	    {
	      tmp2 = my_str_to_wordtab(tmp[1], ':');
	      if ((i = my_connect(tmp2)) != -1)
		return (i);
	    }
	  else
	    my_putstr("Use the command server for specify a host and a port\n");
	}
      else
	perror("exit");
    }
}
