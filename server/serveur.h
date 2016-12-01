/*
** serveur.h for my_irc in /Users/victorbalssa/my_irc
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Fri Nov 25 16:54:18 2016 BALSSA Victor
** Last update Fri Nov 25 17:42:31 2016 BALSSA Victor
*/

#ifndef		__SERVEUR_H__
# define	__SERVEUR_H__

# define	FD_FREE		0
# define	FD_CLIENT	1
# define	FD_SERVER	2
# define	MAX_FD		255
# define	BUFF_SIZE	3000

#include <sys/socket.h>
#include <sys/select.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef				void(*vfptr)();

typedef struct			s_client
{
  char				*nickname;
  int				fd;
  int				type;
  vfptr				fptr_read;
  struct s_client		*next;
}				t_client;

typedef struct			s_chan
{
  char				*name;
  t_client			*user;
  int				pos;
  struct s_chan			*next;
}				t_chan;

typedef struct			s_env
{
  int				port;
  fd_set			fd_write;
  fd_set			fd_read;
  int				fd_max;
  t_client			*list;
  t_chan			*chan;
}				t_env;

typedef				int(*ifptr)(t_env *, char **, int);

typedef struct			s_cmd
{
  char				*cmd;
  ifptr				fptr_cmd;
}				t_cmd;

void				client_read(t_env *, int);
int				check_fd(t_client **, int);
void				add_elem_fd(t_client **, int, int, vfptr);
void				add_elem_chan(t_chan **, char *);
void				show_list_chan(t_chan *, int);
void				show_all_user(t_chan *);
int				disconnect_chan(t_client *, t_chan *, int);
int				get_cmd(t_env *, char *, int);
int				my_list(t_env *, char **, int);
int				my_join(t_env *, char **, int);
int				my_quit(t_env *, char **, int);
int				my_exit(t_env *, char **, int);
int				my_nick(t_env *, char **, int);
int				my_users(t_env *, char **, int);
int				my_whisp(t_env *, char **, int);
t_chan				*get_current_chan(t_chan *, int);
t_client			*get_current_user(t_client *, int);
char				*my_strcat(char *, char *);
char				**my_str_to_wordtab(char *, char);
void				my_putstr(char *);
void				my_putstr_fd(int, char *);
void				my_putnbr_fd(int, int);
char				*my_strdup(char *);
int				my_strncmp(char *, char *, int);
int				my_strcmp(char *, char *);
int				my_strlen(char *);
int				tablen(char **);
int				my_getnbr(char *);

#endif
