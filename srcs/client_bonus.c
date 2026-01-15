/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:43:06 by lgervet           #+#    #+#             */
/*   Updated: 2026/01/15 15:50:13 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	client_handle_signal(int sig)
{
	if (sig)
		;
	return ;
}

/*
** send_binary:
**     Sends bit by bit to server. Waits for ack between each bit. 
**	   Sends a null char when finished.
**
**     @param target  server pid
**     @param **s  	  str (in binary) to send
**     @return 1 if success / 0 if error
*/
static int	send_binary(int target, char **s, struct sigaction sa)
{
	int					i;
	int					j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == '0')
				kill(target, SIGUSR1);
			else if (s[i][j] == '1')
				kill(target, SIGUSR2);
			else
				return (0);
			wait_for_ack(sa);
			j++;
		}
		i++;
	}
	send_null_char(target, sa);
	return (1);
}

/*
** process_string:
**     Main handler dispatching arguments.
**
**     @param *s  	  string given by user (av[2])
**     @param target  pid given by user (av[1])
**     @return 1 if success / 0 if error
*/
static int	process_string(char *s, int target, struct sigaction sa)
{
	size_t	i;
	int		j;
	char	**encoded;
	size_t	len;

	len = ft_strlen(s);
	encoded = (char **)malloc(sizeof(*encoded) * (len + 1));
	if (!encoded)
		return (1);
	ft_bzero(encoded, sizeof(*encoded) * (len + 1));
	i = 0;
	while (i < len)
	{
		encoded[i] = convert_char_to_binary((int)s[i]);
		i++;
	}
	i = send_binary(target, encoded, sa);
	j = 0;
	while (encoded[j])
	{
		free(encoded[j]);
		j++;
	}
	return (free(encoded), i);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	sigset_t			sigset;
	pid_t				target;
	int					i;

	if (ac != 3)
	{
		ft_printf("[x] Client usage: launch server first.\
			Then: './client <server pid> <string to pass>'");
		return (0);
	}
	ft_bzero(&sa, sizeof(struct sigaction));
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGUSR1);
	sigprocmask(SIG_BLOCK, &sigset, NULL);
	sa.sa_handler = &client_handle_signal;
	target = ft_atoi(av[1]);
	i = process_string(av[2], target, sa);
	if (!i)
		ft_printf("[x] Error\n");
	return (i);
}
