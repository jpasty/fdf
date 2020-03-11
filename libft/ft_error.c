/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:41:45 by cshinoha          #+#    #+#             */
/*   Updated: 2020/03/11 21:49:54 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void		ft_error_fd(int fd, char *mes, int code)
{
	write(fd, mes, ft_strlen(mes));
	exit(code);
}

void		ft_error(char *mes, int code)
{
	ft_error_fd(2, mes, code);
}

void		ft_errno_fd(int fd, char err, char *mes)
{
	if (err)
		errno = err;
	ft_error_fd(fd, (mes ? mes : strerror(errno)), errno);
}

void		ft_errno(char err, char *mes)
{
	if (err)
		errno = err;
	perror(mes ? mes : strerror(errno));
	exit(errno);
}
