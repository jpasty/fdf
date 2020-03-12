/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 22:28:14 by jpasty            #+#    #+#             */
/*   Updated: 2020/03/11 22:28:19 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			set_default_clr(int z, t_map *map)
{
	double	percent;

	percent = ratio(map->z_min, map->z_max, z);
	if (percent < 0.2)
		return (COLOR_SKY);
	else if (percent < 0.4)
		return (COLOR_OCEAN);
	else if (percent < 0.6)
		return (COLOR_YELLOW);
	else if (percent < 0.8)
		return (COLOR_GREEN);
	else
		return (COLOR_ORANGE);
}

int			get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int			set_clr(t_point cur, t_point ps, t_point pe)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;
	t_point	d;

	d.x = abs(pe.x - ps.x);
	d.y = abs(pe.y - ps.y);
	if (cur.clr == pe.clr)
		return (cur.clr);
	if (d.x > d.y)
		percentage = ratio(ps.x, pe.x, cur.x);
	else
		percentage = ratio(ps.y, pe.y, cur.y);
	red = get_light((ps.clr >> 16) & 0xFF,
			(pe.clr >> 16) & 0xFF, percentage);
	green = get_light((ps.clr >> 8) & 0xFF,
			(pe.clr >> 8) & 0xFF, percentage);
	blue = get_light(ps.clr & 0xFF,
			pe.clr & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
