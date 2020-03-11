/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:28:48 by jpasty            #+#    #+#             */
/*   Updated: 2020/03/11 22:53:20 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dest;

	dest = (unsigned char *)b;
	while (len-- > 0)
		*dest++ = c;
	return (b);
}
