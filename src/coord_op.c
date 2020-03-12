/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 23:20:36 by jpasty            #+#    #+#             */
/*   Updated: 2020/03/11 23:20:38 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_batisa		*extract_coord(t_batisa **coord)
{
	t_batisa	*head;

	head = NULL;
	if (coord && *coord)
	{
		head = *coord;
		*coord = (*coord)->next;
	}
	return (head);
}

void			add_new_coord(t_batisa **lst_coord, t_batisa *new_coord)
{
	if (lst_coord)
	{
		if (new_coord)
		{
			new_coord->next = *lst_coord;
			*lst_coord = new_coord;
		}
	}
}
