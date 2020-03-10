#include "fdf.h"

double 		ratio(int z_min, int z_max, int z)
{
	double	position;
	double	length;

	position = z - z_min;
	length = z_max - z_min;

	return (length == 0) ? 1.0 : (position / length);
}

int 		set_default_clr(int z, t_map *map)
{
	double percent;

	percent = ratio(map->z_min, map->z_max, z);
	if (percent < 0.2)
		return (COLOR_DISCO);
	else if (percent < 0.4)
		return (COLOR_BRICK_RED);
	else if (percent < 0.6)
		return (COLOR_FLAMINGO);
	else if (percent < 0.8)
		return (COLOR_JAFFA);
	else
		return (COLOR_SAFFRON);
}

t_point		get_point(int x, int y, t_map *map)
{
	t_point	new;
	int		i;

	i = y * map->width + x;
	new.x = x;
	new.y = y;
	new.z = map->z_arr[i];
	new.clr = (map->clr_arr[i] == -1) ? set_default_clr(new.z, map) :
				map->clr_arr[i];
	return  (new);

}

static void	draw_background(t_mlx *mlx)
{
	int	*image;
	int	i;

	ft_bzero(mlx->data_ptr, WIDTH * HEIGHT * (mlx->bits_per_pixel / 8));
	image = (int *)(mlx->data_ptr);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		image[i] = (i % WIDTH < MENU_WIDTH) ? MENU_BACKGROUND : BACKGROUND;
		i++;
	}
}

void		draw(t_map *map, t_mlx *mlx)
{
	int		x;
	int 	y;

	draw_background(mlx);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != map->width - 1)
				brsnhm(projection(get_point(x, y, map), mlx, map),
						projection(get_point(x + 1, y, map), mlx, map), mlx);
			if (y != map->height - 1)
				brsnhm(projection(get_point(x, y, map), mlx, map),
					   projection(get_point(x, y + 1, map), mlx, map), mlx);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}