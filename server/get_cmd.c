/*
** get_cmd.c for my_irc in /Users/victorbalssa/my_irc
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Fri Nov 25 16:57:45 2016 BALSSA Victor
** Last update Fri Nov 25 23:37:51 2016 BALSSA Victor
*/

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	"serveur.h"

t_cmd		g_tab[] =
  {
    {"/nick", &my_nick},
    {"/list", &my_list},
    {"/join", &my_join},
    {"/part", &my_quit},
    {"/exit", &my_exit},
    {"/users", &my_users},
    {"/whisp", &my_whisp},
    {NULL, NULL}
  };

int		get_cmd(t_env *e, char *buff, int fd)
{
  char		**cmd;
  int		i;

  i = -1;
  if (buff[0] != '\0')
    {
      my_putstr("test 1 \n");
      cmd = my_str_to_wordtab(buff, ' ');
      if (cmd[0] == NULL)
	return (0);
      while (g_tab[++i].cmd != NULL && my_strcmp(cmd[0], g_tab[i].cmd));
      if (g_tab[i].cmd == NULL)
	return (0);
      else
	g_tab[i].fptr_cmd(e, cmd, fd);
      show_all_user(e->chan);
      return (1);
    }
  return (0);
}

int		my_exit(t_env *e, char **cmd, int fd)
{
  t_chan        *tmp;

  tmp = e->chan;
  if (tablen(cmd) != 2)
    {
      my_putstr_fd(fd, "part : error arguments.\n");
      return (0);
    }
  while (tmp)
    {
      if (!my_strcmp(tmp->name, cmd[1]))
        {
          disconnect_part(tmp->user, fd);
          return (0);
        }
      tmp = tmp->next;
    }
  my_putstr_fd(fd, "part : error chan doesn't exist.\n");
  return (0);
}

int		my_list(t_env *e, char **cmd, int fd)
{
  t_chan	*tmp;

  if (tablen(cmd) == 1)
    show_list_chan(e->chan, fd);
  else if (tablen(cmd) == 2)
    {
      tmp = e->chan;
      while (tmp)
	{
	  if (!my_strncmp(tmp->name, cmd[1], my_strlen(cmd[1])))
	    my_putstr_fd(fd, tmp->name);
	  tmp = tmp->next;
	}
    }
  else
    my_putstr_fd(fd, "list : error arguments.\n");
  return (0);
}

int		disconnect_part(t_server *list, int fd)
{
  t_server	*user;

  user = list;
  while (user)
    {
      if (user->fd == fd && user->type == FD_CLIENT)
	{
	  user->type = FD_FREE;
	  user->nickname = NULL;
	  return (0);
	}
      user = user->next;
    }
  my_putstr_fd(fd, "part : error client doesn't exist in this chan.\n");
  return (0);
}

int		my_quit(t_env *e, char **cmd, int fd)
{
  t_chan	*tmp;

  tmp = e->chan;
  if (tablen(cmd) != 2)
    {
      my_putstr_fd(fd, "part : error arguments.\n");
      return (0);
    }
  while (tmp)
    {
      if (!my_strcmp(tmp->name, cmd[1]))
	{
	  disconnect_part(tmp->user, fd);
	  return (0);
	}
      tmp = tmp->next;
    }
  my_putstr_fd(fd, "part : error chan doesn't exist.\n");
  return (0);
}

int		my_nick(t_env *e, char **cmd, int fd)
{
  t_chan	*current_chan;
  t_server	*tmp;

  if (tablen(cmd) != 2)
    {
      my_putstr_fd(fd, "nick : error arguments.\n");
      return (0);
    }
  if ((current_chan = get_current_chan(e->chan, fd)) != NULL)
    {
      tmp = current_chan->user;
      while (tmp)
	{
	  if (tmp->fd == fd && tmp->type == FD_CLIENT)
	    {
	      tmp->nickname = my_strdup(cmd[1]);
	      return (0);
	    }
	  tmp = tmp->next;
	}
    }
  my_putstr_fd(fd, "nick : error join a chan before.\n");
  return (0);
}
