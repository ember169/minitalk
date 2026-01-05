/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:43:06 by lgervet           #+#    #+#             */
/*   Updated: 2025/12/26 15:17:13 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	pid_t	target;

	if (!ac)
	{
		ft_printf("CLIENT > Usage: launch server first. \
			Then: './client <server pid> <string to pass>'");
		return (0);
	}
	target = ft_atoi(av[1]);
	kill(target, SIGUSR1);
	ft_printf("CLIENT > Signal 1 sent.\n");
	kill(target, SIGUSR2);
	ft_printf("CLIENT > Signal 2 sent.\n");
}
