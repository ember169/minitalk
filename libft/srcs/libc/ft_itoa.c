/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:38:43 by lgervet           #+#    #+#             */
/*   Updated: 2025/12/20 10:20:07 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*  FUNCTION: ft_itoa                                                         */
/*                                                                            */
/*  Allocates memory (using malloc(3)) and returns a string representing      */
/*  the integer received as an argument. Negative numbers must be handled.    */
/*                                                                            */
/*  @param n      The integer to convert.                                     */
/*  @return       The string representing the integer / NULL if alloc failed. */
/*                                                                            */
/*  Example:                                                                  */
/*     char *str = ft_itoa("123");                                            */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	_charactercounter(long nb)
{
	size_t	i;

	i = 1;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	if (nb == 0)
		return (i);
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t	len;
	char	*s;

	nb = n;
	len = _charactercounter(nb);
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (nb == 0)
		s[0] = '0';
	if (nb < 0)
	{
		s[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		s[--len] = '0' + nb % 10;
		nb /= 10;
	}
	return (s);
}
