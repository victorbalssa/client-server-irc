/*
** client.h for my_irc in /Users/victorbalssa/my_irc
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Wed Nov 23 14:27:13 2016 BALSSA Victor
** Last update Thu Dec  1 21:49:49 2016 BALSSA Victor
*/

#ifndef		__CLIENT_H__
# define	__CLIENT_H__

# define	BUFF_SIZE	3000

# include	<unistd.h>
# include	<sys/socket.h>
# include	<netdb.h>
# include	<arpa/inet.h>

int		my_connect(char **);
int		get_first_cmd();

char		**my_str_to_wordtab(char *, char);
void		my_bzero(char *, int);
void		free_tab(char **);
int		tablen(char **);
int		my_getnbr(char *);
int		my_strcmp(char *, char *);
void		my_putstr(char *);
int		my_strlen(char *);

#endif
