/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brsnhm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:51:42 by jpasty            #+#    #+#             */
/*   Updated: 2020/02/10 18:15:04 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

void			brsnhm(t_point p1, t_point p2)
{
	int			slope;
	int			delta;
	int			dx;
	int			dy;
	int			threshold;
	float		m;	

	dy = p2.y - p1.y;
	dx = p2.x - p1.x;
	m = dy/dx;
	if (dy == 0)
	{
		if (p2.y < p1.y)
			swap(p2.y, p1.y);
		while (p1.y != p2.y)
			draw_pixel(p1.x, p1.y++);
	}
	if (m >= -1 && m <= 1)
	{
		if (p2.x < p1.x)
			swap(p2.x, p1.x);
		while (x1 != x2)

	}
}

int				main(void)
{
	t_point		p1;
	t_point		p2;

}
