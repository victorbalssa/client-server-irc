/*
** client.c for my_irc in /Users/victorbalssa/my_irc
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Wed Nov 23 14:28:50 2016 BALSSA Victor
** Last update Fri Nov 25 23:18:31 2016 BALSSA Victor
*/

#include		<sys/types.h>
#include		<sys/socket.h>
#include		<unistd.h>
#include		<stdlib.h>
#include		<stdio.h>
#include		<netdb.h>
#include		<string.h>
#include		<netinet/in.h>
#include		<arpa/inet.h>
#include		<fcntl.h>
#include		<sys/stat.h>
#include		"client.h"

int			get_input(int s)
{
  char			buff[BUFF_SIZE];
  int			r;

  my_bzero(buff, BUFF_SIZE);
  r = read(0, buff, BUFF_SIZE);
  if (r > 0)
    {
      buff[r] = '\0';
      write(s, buff, r);
      return (1);
    }
  else
    {
      write(1, "exit\n", 5);
      return (0);
    }
}

int			get_msg(int s)
{
  char			buff[BUFF_SIZE];
  int			r;

  my_bzero(buff, BUFF_SIZE);
  r = recv(s, buff, BUFF_SIZE, 0);
  if (r > 0)
    {
      buff[r] = '\0';
      write(1, buff, r);
      return (1);
    }
  else
    {
      write(1, "Connection closed\n", 18);
      return (0);
    }
}

int			my_client(int s)
{
  fd_set		fd_read;

  while (42)
    {
      write(1, "/> ", 3);
      FD_ZERO(&fd_read);
      FD_SET(0, &fd_read);
      FD_SET(s, &fd_read);
      if (select(s + 1, &fd_read, NULL, NULL, NULL) == -1)
	perror("select");
      if (FD_ISSET(0, &fd_read))
	get_input(s);
      if (FD_ISSET(s, &fd_read))
	get_msg(s);
    }
}

int			my_connect(char **cmd)
{
  struct protoent	*pe;
  struct sockaddr_in	sin;
  int			s;
  int			port;

  if (cmd[1] != NULL)
    port = my_getnbr(cmd[1]);
  pe = getprotobyname("TCP");
  if (pe == NULL)
    perror("Getprotobyname() fail");
  s = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (s == -1)
    perror("Socket() fail.");
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = inet_addr(cmd[0]);
  if (connect(s, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
    {
      perror("Error");
      return (-1);
    }
  free_tab(cmd);
  return (s);
}

int			main()
{
  int			s;

  s = get_first_cmd();
  if (my_client(s) == 0)
    return (0);
}
