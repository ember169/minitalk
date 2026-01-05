/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:44:01 by lgervet           #+#    #+#             */
/*   Updated: 2025/12/30 14:24:54 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/*
** encode_string:
**     Encode string to binary
**
**     @param str  string to encode
**     @return integer array of bytes
*/
int	*encode_string(char *str)
{
	unsigned int	len;
	unsigned int	i;
	unsigned int	*arr;

	len = ft_strlen(str);
	arr = malloc(len * sizeof(char));
	if (!arr)
		return (NULL);
	i = 0;
	while (str[i])
	{
		return (0);
	}
	return (0);
}


