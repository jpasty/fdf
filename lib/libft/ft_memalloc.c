/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:04:58 by jpasty            #+#    #+#             */
/*   Updated: 2020/03/11 21:33:02 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = malloc(size)))
		ft_errno(ENOMEM, NULL);
	ft_bzero(mem, size);
	return (mem);
}
