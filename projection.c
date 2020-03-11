#include "fdf.h"

void		rotate_x(int *y, int *z, double alpha)
{
	int 	prev_y;

	prev_y = *y;
	*y = prev_y * cos(alpha) - *z * sin(alpha);
	*z = prev_y * sin(alpha) + *z * cos(alpha);
}

void		rotate_y(int *x, int *z, double betta)
{
	int 	prev_x;

	prev_x = *x;
	*x = prev_x * cos(betta) - *z * sin(betta);
	*z = prev_x * sin(betta) + *z * cos(betta);
}

void		rotate_z(int *x, int *y, double gamma)
{
	int 	prev_x;
	int		prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(gamma) - prev_y * sin(gamma);
	*y = prev_x * sin(gamma) + prev_y * cos(gamma);
}

void		set_iso_projection(int *x, int *y, int z)
{
	int 	prev_x;
	int 	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = -z + (prev_x + prev_y) * sin(0.523599);
}
t_point		projection(t_point p, t_mlx *mlx, t_map *map)
{
	p.x *= mlx->cam->zoom;
	p.y *= mlx->cam->zoom;
	p.z *= mlx->cam->zoom / mlx->cam->z_divisor;
	p.x -= (mlx->cam->zoom * map->width) / 2;
	p.y -= (mlx->cam->zoom * map->height) /2;
	rotate_x(&p.y, &p.z, mlx->cam->alpha);
	rotate_y(&p.x, &p.z, mlx->cam->beta);
	rotate_z(&p.x, &p.y, mlx->cam->gamma);
	if (!mlx->cam->projection)
		set_iso_projection(&p.x, &p.y, p.z);
	p.x += (WIDTH - MENU_WIDTH) / 2 + mlx->cam->x_offset + MENU_WIDTH;
	p.y += (HEIGHT + map->height * mlx->cam->zoom) / 3 + mlx->cam->y_offset;
	return (p);
}