/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:43:06 by lgervet           #+#    #+#             */
/*   Updated: 2025/12/25 19:59:40 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	pid_t	pid;
	pid_t	target;
	int		arr;

	if (!ac)
	{
		ft_printf("Usage: launch server first. \
			Then: './client <server pid> <string to pass>'");
		return (0);
	}
	pid = getpid();
	ft_printf("CLIENT > PID: %d\n", pid);
	encode_data(av[2]);
	kill(target, SIGUSR1);
	ft_printf("CLIENT > Signal sent.");
}
