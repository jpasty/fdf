/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:46:42 by jpasty            #+#    #+#             */
/*   Updated: 2020/03/11 22:53:21 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void					*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*res;
	const unsigned char *str;
	size_t				i;

	i = 0;
	res = (unsigned char *)dst;
	str = (unsigned char *)src;
	if (src < dst)
	{
		while (len--)
			res[len] = str[len];
	}
	else
	{
		while (len--)
		{
			res[i] = str[i];
			i++;
		}
	}
	return (res);
}
