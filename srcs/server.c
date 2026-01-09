/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:43:41 by lgervet           #+#    #+#             */
/*   Updated: 2026/01/09 15:43:16 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	handle_signal1(int sig)
{
	ft_printf("SERVER > Received signal 1\n");
	// kill(client, SIGUSR1);
	exit(sig);
}

static void	handle_signal2(int sig)
{
	ft_printf("SERVER > Received signal 2\n");
	// kill(client, SIGUSR2);
	exit(sig);
}

static void	wait_for_signals(void)
{
	signal(SIGUSR1, handle_signal1);
	signal(SIGUSR2, handle_signal2);
	while (1)
		usleep(100000);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("[x] Server PID: %d\n", pid);
	wait_for_signals();
	return (1);
}
