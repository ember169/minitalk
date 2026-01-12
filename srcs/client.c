/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:43:06 by lgervet           #+#    #+#             */
/*   Updated: 2026/01/12 17:54:02 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

// static int	handle_ack(int sig)
// {
// 	printf("[ ] Received ACK\n");
// 	return (1);
// }

// static int	wait_for_ack(void)
// {
// 	signal(SIGUSR1, handle_ack);
// 	while (1)
// 		usleep(1);
// 	return (handle_ack);
// }

/*
** send_binary:
**     Sends bit by bit to server. Waits for ack between each bit(/byte?).
**
**     @param target  server pid
**     @param **s  	  str (in binary) to send
**     @return 1 if success / 0 if error
*/
static int	send_binary(int target, char **s)
{
	int			i;
	int			j;

	i = 0;
	while (s[i])
	{
		j = 0;
		ft_printf("[ ] Sending '%s'\n", s[i]);
		while (s[i][j])
		{
			if (s[i][j] == '0')
				kill(target, SIGUSR1);
			else if (s[i][j] == '1')
				kill(target, SIGUSR2);
			else
				ft_printf("[!] Wrong bit read.");
			client_wait_for_signal();
			j++;
		}
		i++;
	}
	ft_printf ("[ ] Binary data sent.\n");
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
static int	process_string(char *s, int target)
{
	size_t	i;
	char	**encoded;
	size_t	len;

	len = ft_strlen(s);
	encoded = (char **)malloc(sizeof(*encoded) * (len + 1));
	if (!encoded)
		return (1);
	i = 0;
	while (i < len)
	{
		encoded[i] = convert_char_to_binary((int)s[i]);
		i++;
	}
	ft_printf("[ ] Str encoded in binary.\n");
	i = send_binary(target, encoded);
	return (free(encoded), i);
}

int	main(int ac, char **av)
{
	pid_t	target;
	int		i;

	if (ac < 3)
	{
		ft_printf("[x] Client usage: launch server first. \
			Then: './client <server pid> <string to pass>'");
		return (0);
	}
	target = ft_atoi(av[1]);
	i = process_string(av[2], target);
	if (!i)
		ft_printf("[x] Error\n");
	return (i);
}
