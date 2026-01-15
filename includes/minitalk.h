/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:40:28 by lgervet           #+#    #+#             */
/*   Updated: 2026/01/15 14:20:22 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# ifndef BITS_NB
#  define BITS_NB	8
# endif

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>
# include "../libft/includes/libft.h"

char	*convert_char_to_binary(int char_int);
void	wait_for_ack(struct sigaction sa);
void	send_null_char(int target, struct sigaction sa);

#endif