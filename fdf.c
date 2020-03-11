#include "fdf.h"



int 			main(int ac, char **av)
{
	t_batisa	*coord;
	t_map		*map;
	t_mlx		*mlx;

	coord = NULL;

	map = map_init();
	read_input(open(av[1], O_RDONLY), map, &coord);
	coord_to_arr(&coord, map);
	mlx = mlx_data(map);
	draw(map, mlx);
	set_hook(mlx, map);
	mlx_loop(mlx->mlx_ptr);
}
