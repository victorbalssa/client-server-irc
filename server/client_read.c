/*
** client_read.c for my_irc in /home/balssa_v/my_my_irc
**
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
**
** Started on  Wed Oct 21 09:19:12 2015 BALSSA Victor
** Last update Fri Nov 25 17:49:09 2016 BALSSA Victor
*/

#include	"serveur.h"

t_chan		*get_current_chan(t_chan *list, int fd)
{
  t_chan	*tmp;
  t_client	*user;

  tmp = list;
  while (tmp)
    {
      user = tmp->user;
      while (user)
	{
	  if (user->fd == fd && user->type == FD_CLIENT)
	    return (tmp);
	  user = user->next;
	}
      tmp = tmp->next;
    }
  return (NULL);
}

t_client	*get_current_user(t_client *list, int fd)
{
  t_client	*tmp;

  tmp = list;
  while (tmp)
    {
      if (tmp->fd == fd && tmp->type == FD_CLIENT)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

void		my_disconnect(t_env *e, int fd)
{
  t_client	*tmp;
  t_chan	*current_chan;
  t_client	*tmp_user;

  tmp = e->list;
  close(fd);
  my_putstr("Connection closed\n");
  while (tmp->fd != fd && tmp != NULL)
    tmp = tmp->next;
  if (tmp != NULL && tmp->fd == fd)
    tmp->type = FD_FREE;
  current_chan = get_current_chan(e->chan, fd);
  if (current_chan != NULL)
    {
      tmp_user = current_chan->user;
      while (tmp_user)
	{
	  if (tmp_user->fd == fd && tmp_user->type == FD_CLIENT)
	    {
	      tmp_user->type = FD_FREE;
	      tmp_user->nickname = NULL;
	    }
	  tmp_user = tmp_user->next;
	}
    }
}

void		send_msg_in_chan(t_env *e, int fd, char * buf)
{
  t_client	*user;
  t_chan	*current_chan;
  t_client	*current_user;

  current_chan = get_current_chan(e->chan, fd);
  user = (current_chan == NULL) ? NULL : current_chan->user;
  current_user = (!user) ? NULL : get_current_user(user, fd);
  if (!current_chan)
    my_putstr_fd(fd, "send msg: error join a chan before.\n");
  while (user)
    {
      if (FD_ISSET(user->fd, &e->fd_write) && fd != user->fd &&
	  user->type == FD_CLIENT)
	{
	  if (current_user != NULL && current_user->nickname)
	    {
	      my_putstr_fd(user->fd, current_user->nickname);
	      my_putstr_fd(user->fd, ": ");
	      my_putstr_fd(user->fd, buf);
	      my_putstr_fd(user->fd, "\n");
	    } 
	  else if (current_user != NULL)
	    {
	      my_putstr_fd(user->fd, "unknown: ");
	      my_putstr_fd(user->fd, buf);
	      my_putstr_fd(user->fd, "\n");
	    }
	}
      user = user->next;
    }
}

void		client_read(t_env *e, int fd)
{
  int		r;
  char		buf[BUFF_SIZE];

  r = read(fd, buf, BUFF_SIZE);
  if (r > 0)
    {
      buf[r - 1] = '\0';
      if (!get_cmd(e, buf, fd))
	send_msg_in_chan(e, fd, buf);
    }
  else
    my_disconnect(e, fd);
}
