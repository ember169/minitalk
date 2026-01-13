/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:40:28 by lgervet           #+#    #+#             */
/*   Updated: 2026/01/13 16:54:37 by lgervet          ###   ########.fr       */
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
void	client_wait_for_signal(struct sigaction sa);

#endif