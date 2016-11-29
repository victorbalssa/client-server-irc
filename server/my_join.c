/*
** my_join.c for my_irc in /Users/victorbalssa/my_irc/server
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Fri Nov 25 17:07:31 2016 BALSSA Victor
** Last update Fri Nov 25 17:30:01 2016 BALSSA Victor
*/

#include	"serveur.h"

void		change_chan(t_chan *list, char *name_chan, int fd)
{
  t_chan	*tmp;
  t_server	*user;

  tmp = list;
  while (tmp)
    {
      if (my_strcmp(tmp->name, name_chan))
	{
	  user = tmp->user;
	  while (user)
	    {
	      if (user->fd == fd && user->type == FD_CLIENT)
		user->type = FD_FREE;
	      user = user->next;
	    }
	}
      tmp = tmp->next;
    }
}

int		check_user_in_chan(t_server *user, int fd)
{
  t_server	*tmp;

  tmp = user;
  while (tmp)
    {
      if (tmp->fd == fd && tmp->type == FD_CLIENT)
	{
	  my_putstr_fd(fd, "join : error you already exist in this chan.\n");
	  return (1);
	}
      else if (tmp->fd == fd)
	{
	  tmp->type = FD_CLIENT;
	  return (1);
	}
      tmp = tmp->next;
    }
  return (0);
}

int		my_join(t_env *e, char **cmd, int fd)
{
  t_chan	*tmp;

  tmp = e->chan;
  if (tablen(cmd) != 2)
    {
      my_putstr_fd(fd, "join : error arguments.\n");
      return (0);
    }
  else
    while (tmp)
      {
	if (!my_strcmp(tmp->name, cmd[1]))
	  {
	    change_chan(e->chan, cmd[1], fd);
	    if (!check_user_in_chan(tmp->user, fd))
	      {
		add_elem_fd(&tmp->user, fd, FD_CLIENT, client_read);
		return (1);
	      }
	    else
	      return (0);
	  }
	tmp = tmp->next;
      }
  my_putstr_fd(fd, "join : error chan doesn't exist.\n");
  return (0);
}
