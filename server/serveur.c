/*
** serveur.c for my_irc in /Users/victorbalssa/my_irc
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Fri Nov 25 17:32:51 2016 BALSSA Victor
** Last update Thu Dec  1 22:50:12 2016 BALSSA Victor
*/

#include		"serveur.h"

void			server_read(t_env *e, int s)
{
  int			cs;
  struct sockaddr_in	client_sin;
  socklen_t		*client_sin_len;

  cs = accept(s, (struct sockaddr *)&client_sin, 
	      (socklen_t *)&client_sin_len);
  if (cs == -1)
    return ;
  my_putstr("New client connected\n");
  add_elem_fd(&e->list, cs, FD_CLIENT, client_read);
  my_putstr_fd(cs, "Welcome to the world's coolest irc server.\n");
  my_putstr_fd(cs, "List channels with /list (/l) and /join it\n");
  my_putstr_fd(cs, "to start discussing !!\n");
}

void			add_client(t_env *e)
{
  int			s;
  struct sockaddr_in	sin;
  int			pos;
  char			*name;

  pos = 1;
  if ((s = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    return ;
  sin.sin_family = AF_INET;
  sin.sin_port = htons(e->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(s, (struct sockaddr*)&sin, sizeof(sin)) == -1)
    return ;
  if (listen(s, 42) == -1)
    return ;
  add_elem_fd(&e->list, s, FD_SERVER, server_read);
  if ((name = malloc(sizeof(char) * 2)) == NULL)
    return ;
  while (pos <= 9)
    {
      name[0] = pos + '0';
      name[1] = '\0';
      add_elem_chan(&e->chan, my_strdup(name));
      pos++;
    }
}

int			my_server(t_env *e)
{
  t_client		*tmp;

  FD_ZERO(&e->fd_read);
  FD_ZERO(&e->fd_write);
  e->fd_max = 0;
  tmp = e->list;
  while (tmp != NULL)
    {
      if (tmp->type != FD_FREE)
	{
	  FD_SET(tmp->fd, &e->fd_read);
	  FD_SET(tmp->fd, &e->fd_write);
	  e->fd_max = tmp->fd;
	}
      tmp = tmp->next;
    }
  if (select(e->fd_max + 1, 
	     &e->fd_read, &e->fd_write, NULL, NULL) == -1)
    return (0);
  tmp = e->list;
  while (tmp != NULL)
    {
      if (FD_ISSET(tmp->fd, &e->fd_read))
	tmp->fptr_read(e, tmp->fd);
      tmp = tmp->next;
    }
  return (1);
}

int			main(int argc, char **argv)
{
  t_env			e;

  if (argc != 2 || my_getnbr(argv[1]) < 1025)
    {
      my_putstr("Usage: ./server_bin [port > 1025]\n\n");
      return (0);
    }
  e.port = my_getnbr(argv[1]);
  e.list = NULL;
  e.chan = NULL;
  add_client(&e);
  while (my_server(&e));
  return (0);
}
