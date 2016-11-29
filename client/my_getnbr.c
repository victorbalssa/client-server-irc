/*
** my_getnbr.c for my_getnbr in /home/balssa_v/my_getnbr
** 
** Made by BALSSA Victor
** Login   <balssa_v@etna-alternance.net>
** 
** Started on  Tue Oct 27 19:49:11 2015 BALSSA Victor
** Last update Wed Nov 23 14:50:36 2016 BALSSA Victor
*/

int	my_getnbr(char *str)
{
  int	neg;
  int	res;
  int	i;

  neg = 1;
  res = 0;
  i = 0;
  while (str[i] && (str[i] < '0' || str[i] > '9'))
    {
      if (str[i] == '-' && neg < 0)
	{
	  neg = 1;
	  i++;
	}
      else if (str[i] == '-' && neg > 0)
	{
	  neg = -1;
	  i++;
	}
      else
	i++;
    }
  while (str[i] >= '0' && str[i] <= '9')
    res = (res * 10) + (str[i++] - '0');
  return (res * neg);
}
