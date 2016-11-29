/*
** list.c for my_irc in /Users/victorbalssa/my_irc
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Fri Nov 25 17:24:42 2016 BALSSA Victor
** Last update Sat Nov 26 17:39:38 2016 BALSSA Victor
*/

#include	"serveur.h"

int		check_fd(t_server **list, int fd)
{
  t_server	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->fd == fd)
	{
	  tmp->type = FD_CLIENT;
	  return (1);
	}
      tmp = tmp->next;
    }
  return (0);
}

void		add_elem_fd(t_server **list, int fd, int type, vfptr fptr_read)
{
  t_server	*new;
  t_server	*tmp;

  if (check_fd(list, fd))
    return ;
  if ((new = malloc(sizeof(*new))) == NULL)
    return ;
  new->fd = fd;
  new->type = type;
  new->fptr_read = fptr_read;
  new->nickname = NULL;
  new->next = NULL;
  if (*list == NULL)
    *list = new;
  else
    {
      tmp = *list;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
    }
}

void		add_elem_chan(t_chan **list, char *name)
{
  t_chan	*new;
  t_chan	*tmp;

  if ((new = malloc(sizeof(*new))) == NULL)
    return ;
  if (name == NULL)
    return ;
  new->name = name;
  new->next = NULL;
  new->user = NULL;
  if (*list == NULL)
    *list = new;
  else
    {
      tmp = *list;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
    }

}

void		show_list(t_server *list, int fd)
{
  t_server	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      //my_putstr_fd(fd, "fd -> ");
      //my_putnbr_fd(fd, tmp->fd);
      //my_putstr_fd(fd, "\n");
      dprintf(fd, "toto\n");
      tmp = tmp->next;
    }
}

void		show_list_chan(t_chan *list, int fd)
{
  t_chan	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      //my_putstr_fd(fd, tmp->name);
      //my_putstr_fd(fd, "\n");
      dprintf(fd, "toto\n");
      tmp = tmp->next;
    }
}
