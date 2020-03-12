/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brsnhm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 22:28:04 by jpasty            #+#    #+#             */
/*   Updated: 2020/03/11 22:28:06 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	pixel_put(t_mlx *mlx, int x, int y, int color)
{
	int		i;

	if (x >= MENU_WIDTH && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * mlx->bits_per_pixel / 8) + (y * mlx->size_line);
		mlx->data_ptr[i] = color;
		mlx->data_ptr[++i] = color >> 8;
		mlx->data_ptr[++i] = color >> 16;
	}
}

static void	run_is_gather(t_draw line, t_point p1, t_point p2, t_mlx *mlx)
{
	int		y;
	t_point	strt;

	ft_memcpy(&strt, &p1, sizeof(t_point));
	y = p1.y;
	line.delta = abs(line.rise) * 2;
	line.threshold = abs(line.run);
	line.thresholdinc = abs(line.run) * 2;
	if (p2.x < p1.x)
	{
		y = p2.y;
		ft_swap(&p1.x, &p2.x);
	}
	while (p1.x != p2.x + 1)
	{
		pixel_put(mlx, p1.x, y,
				set_clr((t_point){p1.x, y, p1.z, p1.clr}, strt, p2));
		line.offset += line.delta;
		if (line.offset >= line.threshold)
		{
			y += line.adjust;
			line.threshold += line.thresholdinc;
		}
		p1.x++;
	}
}

static void	rise_is_gather(t_draw line, t_point p1, t_point p2, t_mlx *mlx)
{
	int		x;
	t_point	strt;

	ft_memcpy(&strt, &p1, sizeof(t_point));
	x = p1.x;
	line.delta = abs(line.run) * 2;
	line.threshold = abs(line.rise);
	line.thresholdinc = abs(line.rise) * 2;
	if (p2.y < p1.y)
	{
		x = p2.x;
		ft_swap(&p1.y, &p2.y);
	}
	while (p1.y != p2.y + 1)
	{
		pixel_put(mlx, x, p1.y,
				set_clr((t_point){x, p1.y, p1.z, p1.clr}, strt, p2));
		line.offset += line.delta;
		if (line.offset >= line.threshold)
		{
			x += line.adjust;
			line.threshold += line.thresholdinc;
		}
		p1.y++;
	}
}

void		brsnhm(t_point p1, t_point p2, t_mlx *mlx)
{
	t_draw	line;
	t_point	strt;

	ft_memcpy(&strt, &p1, sizeof(t_point));
	line_init(&line, &p1, &p2);
	if (line.run == 0)
	{
		if (p2.y < p1.y)
			ft_swap(&p1.y, &p2.y);
		while (p1.y != p2.y + 1)
			pixel_put(mlx, p1.x, p1.y,
					set_clr((t_point){p1.x, p1.y++, p1.z, p1.clr}, strt, p2));
	}
	if (line.m >= -1 && line.m <= 1)
		run_is_gather(line, p1, p2, mlx);
	else
		rise_is_gather(line, p1, p2, mlx);
}
