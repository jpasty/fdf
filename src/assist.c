/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 22:27:56 by jpasty            #+#    #+#             */
/*   Updated: 2020/03/11 22:27:59 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					ft_is_digit(char s, int base)
{
	char			*digit;
	int				i;

	digit = "0123456789ABCDEF";
	i = 0;
	if (!s)
		return (0);
	while (i < base)
	{
		if (digit[i] == ft_toupper(s))
			return (i);
		i++;
	}
	return (-1);
}

int					ft_is_space(int c)
{
	if (c == ' ' || c == '\t' ||
		c == '\r' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

int					ft_atoi_base(char *s, int base)
{
	unsigned long	res;
	int				sign;
	int				i;
	int				digit;

	res = 0;
	sign = 1;
	i = 0;
	digit = 0;
	if (*s)
	{
		while (ft_is_space(s[i]))
			i++;
		if (base == 10 && (s[i] == '-' || s[i] == '+'))
		{
			if (s[i] == '-')
				sign = -1;
			i++;
		}
		if (base == 16)
			i += 2;
		while (s[i] && (digit = ft_is_digit(s[i++], base)) >= 0)
			res = res * base + digit;
	}
	return ((int)(res * sign));
}

int					ft_is_num(char *s, int base)
{
	int				i;

	i = 0;
	while (ft_is_space(s[i]))
		i++;
	if (base == 2 || base == 16)
		i += 2;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] && (ft_is_digit(s[i], base) >= 0))
		i++;
	return (s[i] ? 0 : 1);
}
