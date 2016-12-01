/*
** list2.c for my_irc in /Users/victorbalssa/my_irc
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Fri Nov 25 23:25:44 2016 BALSSA Victor
** Last update Fri Nov 25 23:30:14 2016 BALSSA Victor
*/

#include	"serveur.h"

void		show_all_user(t_chan *list)
{
  t_chan	*tmp;
  t_client	*tmp_user;

  tmp = list;
  while (tmp)
    {
      my_putstr("chan ");
      my_putstr(tmp->name);
      my_putstr(" :\n");
      tmp_user = tmp->user;
      while (tmp_user)
	{
	  if (tmp_user->type != FD_FREE)
	    {
	      if (tmp_user->nickname)
		{
		  my_putstr("-  fd -> ");
		  my_putnbr_fd(1, tmp_user->fd);
		  my_putstr(" : nickname -> ");
		  my_putstr(tmp_user->nickname);
		  my_putstr(" \n\n");
		}
	      else
		{
		  my_putstr("-  fd -> ");
		  my_putnbr_fd(1, tmp_user->fd);
                  my_putstr(" : nickname -> unknown \n\n");
		}
	    }
	  tmp_user = tmp_user->next;
	}
      tmp = tmp->next;
    }
}
