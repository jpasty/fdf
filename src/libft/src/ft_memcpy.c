/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:14:36 by jpasty            #+#    #+#             */
/*   Updated: 2020/03/11 22:53:21 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void					*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*str;
	unsigned char		*res;
	size_t				i;

	res = (unsigned char *)dst;
	str = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}
