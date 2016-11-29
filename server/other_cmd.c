/*
** other_cmd.c for my_irc in /Users/victorbalssa/my_irc
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Fri Nov 25 17:30:58 2016 BALSSA Victor
** Last update Fri Nov 25 17:32:15 2016 BALSSA Victor
*/

#include	"serveur.h"

int		my_users(t_env *e, char **cmd, int fd)
{
  t_chan	*current_chan;
  t_server	*tmp;

  if (tablen(cmd) != 1)
    {
      my_putstr_fd(fd, "user : error arguments.\n");
      return (0);
    }
  if ((current_chan = get_current_chan(e->chan, fd)) != NULL)
    {
      tmp = current_chan->user;
      while (tmp)
	{
	  if (tmp->nickname)
	    my_putstr_fd(fd, tmp->nickname);
	  else if (!tmp->nickname && tmp->type == FD_CLIENT)
	    my_putstr_fd(fd, "unknown\n");
	  tmp = tmp->next;
	}
    }
  else
    my_putstr_fd(fd, "user : error join a chan before.\n");
  return (0);
}

void		send_msg_to_user(t_server *c_user, t_server *user, char **msg)
{
  int		i;
  char		*tmp;

  i = 2;
  tmp = NULL;
  while (msg[i])
    tmp = my_strcat(tmp, msg[i++]);
  if (c_user != NULL && c_user->nickname)
    {
      my_putstr_fd(user->fd, c_user->nickname);
      my_putstr_fd(user->fd, " : ");
      my_putstr_fd(user->fd, tmp);
      my_putstr_fd(user->fd, "\n");
    }
  else if (c_user != NULL && !c_user->nickname)
    {
      my_putstr_fd(user->fd, "unknown : "); 
      my_putstr_fd(user->fd, tmp);
      my_putstr_fd(user->fd, "\n");
    }
}

int		my_whisp(t_env *e, char **cmd, int fd)
{
  t_chan	*current_chan;
  t_server	*user;
  t_server	*current_user;

  if (tablen(cmd) < 3)
    my_putstr_fd(fd, "msg : error arguments.\n");
  else if ((current_chan = get_current_chan(e->chan, fd)) != NULL)
    {
      user = current_chan->user;
      current_user = (!user) ? NULL : get_current_user(user, fd);
      while (user)
	{
	  if (user->nickname && !my_strcmp(user->nickname, cmd[1]) && fd != user->fd)
	    {
	      send_msg_to_user(current_user, user, cmd);
	      return (1);
	    }
	  user = user->next;
	}
      my_putstr_fd(fd, "msg : error the receiver's nickname doesn't exist.\n");
    }
  else
    my_putstr_fd(fd, "msg : error join a chan before.\n");
  return (0);
}
