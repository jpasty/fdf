#include "fdf.h"



int 			main(int ac, char **av)
{
	t_batisa	*coord;
	t_map		*map;
	t_mlx		*mlx;

	coord = NULL;
	if (!(map = map_init()))
		return (0);
	if (!(read_input(open(av[1], O_RDONLY), map, &coord)))
		return (0);
	coord_to_arr(&coord, map);
	mlx = mlx_data(map);
	draw(map, mlx);
	set_hook(mlx, map);
	mlx_loop(mlx->mlx_ptr);
}
