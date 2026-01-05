/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:43:41 by lgervet           #+#    #+#             */
/*   Updated: 2025/12/26 15:20:17 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handle_signal1(int sig)
{
	ft_printf("SERVER > Received signal 1\n");
	// kill(client, SIGUSR1);
	exit(sig);
}

void	handle_signal2(int sig)
{
	ft_printf("SERVER > Received signal 2\n");
	// kill(client, SIGUSR2);
	exit(sig);
}

void	wait_for_signal(void)
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
	ft_printf("SERVER > PID: %d\n", pid);
	wait_for_signal();
	return (1);
}
