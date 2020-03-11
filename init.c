#include "fdf.h"

t_map 		*map_init()
{
	t_map 	*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	map->clr_arr = NULL;
	map->height = 0;
	map->width = 0;
	map->z_arr = 0;
	return (map);
}

t_cam		*cam_init(t_map *map)
{
	t_cam	*cam;

	if(!(cam = (t_cam *)ft_memalloc(sizeof(t_cam))))
		return (NULL);
	cam->zoom = ft_min((WIDTH - MENU_WIDTH) / map->width / 2,
					   HEIGHT / map->height / 2 );
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	cam->z_divisor = 1;
	cam->x_offset = 0;
	cam->y_offset = 0;
	cam->projection = 0;
	return (cam);
}

t_mlx		*mlx_data(t_map *map)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->mlx_ptr = mlx_init()))
		return (NULL);
	if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "Fdf")))
		return (NULL);
	if (!(mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT)))
		return (NULL);
	mlx->data_ptr = mlx_get_data_addr(mlx->img_ptr, &(mlx->bits_per_pixel),
			&(mlx->size_line), &(mlx->endian));
	if (!mlx->data_ptr)
		return (NULL);
	if (!(mlx->mouse = (t_mouse *)ft_memalloc(sizeof(t_mouse))))
		return (NULL);
	mlx->cam = cam_init(map);
	return (mlx);
}

void		line_init(t_draw *line, t_point *p1, t_point *p2)
{
	line->rise = p2->y - p1->y;
	line->run = p2->x - p1->x;
	line->m = (float)line->rise / line->run;
	line->adjust = line->m >= 0 ? 1 : -1;
	line->offset = 0;
}

