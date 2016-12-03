/*
** get_first_cmd.c for my_irc in /Users/victorbalssa/my_irc
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Wed Nov 23 15:04:08 2016 BALSSA Victor
** Last update Thu Dec  1 21:38:17 2016 BALSSA Victor
*/

#include		"client.h"

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
    return (-1);
  s = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (s == -1)
    return (-1);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = inet_addr(cmd[0]);
  if (connect(s, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
    {
      my_putstr("Error connect()\n");
      return (-1);
    }
  free_tab(cmd);
  return (s);
}

int			get_first_cmd()
{
  char			buff[BUFF_SIZE];
  char			**tmp;
  char			**tmp2;
  int			i;
  int			r;

  r = 1;
  while (r)
    {
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
	    my_putstr("Usage: /server [address]:[port]\n");
	}
      else
	r = 0;
    }
  return (0);
}
