/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:43:41 by lgervet           #+#    #+#             */
/*   Updated: 2026/01/15 15:06:16 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	manage_character(char c)
{
	static char	buf[1024];
	static int	i;

	buf[i] = c;
	i++;
	if (c == '\0' || i == 1024)
	{
		write(1, &buf, i);
		memset(buf, 0, i);
		i = 0;
	}
	return ;
}

static void	server_handle_signal(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	i;

	if (context)
		(void)0;
	if (sig == SIGUSR1)
	{
		c = (c << 1) | 0;
		i++;
	}
	if (sig == SIGUSR2)
	{
		c = (c << 1) | 1;
		i++;
	}
	if (i == 8)
	{
		manage_character(c);
		i = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;
	static char			*bin_str;

	bin_str = (char *)malloc((BITS_NB + 1) * sizeof(char));
	pid = getpid();
	ft_printf("[x] Server PID: %d\n", pid);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &server_handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		sigsuspend(&sa.sa_mask);
	return (1);
}
