/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:55:20 by jpasty            #+#    #+#             */
/*   Updated: 2020/03/11 22:53:20 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	len;
	char	*str;

	len = ft_strlen(s1);
	str = (char *)s2;
	while (n-- && *str)
		s1[len++] = *str++;
	s1[len] = '\0';
	return (s1);
}
