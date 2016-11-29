/*
** list2.c for my_irc in /Users/victorbalssa/my_irc
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Fri Nov 25 23:25:44 2016 BALSSA Victor
** Last update Fri Nov 25 23:30:14 2016 BALSSA Victor
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"serveur.h"

void		show_all_user(t_chan *list)
{
  t_chan	*tmp;
  t_server	*tmp_user;

  tmp = list;
  while (tmp)
    {
      my_putstr("chan");
      my_putstr(tmp->name);
      my_putstr("\n");
      tmp_user = tmp->user;
      while (tmp_user)
	{
	  if (tmp_user->type != FD_FREE)
	    {
	      if (tmp_user->nickname)
		{
		  my_putstr("fd -> %d : nickname -> %s\n");
		  my_putstr(tmp_user->nickname);
		}
	      else
		{
		  my_putstr("fd -> %d : nickname -> unknown\n");
		}
	    }
	  tmp_user = tmp_user->next;
	}
      tmp = tmp->next;
    }
}
