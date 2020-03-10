#include "fdf.h"

//void	set_hook(t_mlx *mlx)
//{
//	mlx_hook(mlx->win_ptr, 2, 0, key_press, mlx);
//	mlx_hook(mlx->win_ptr, 17, 0, close, mlx);
//	mlx_hook(mlx->win_ptr, 4, 0, mouse_press, mlx);
//	mlx_hook(mlx->win_ptr, 5, 0, mouse_release, mlx);
//	mlx_hook(mlx->win_ptr, 6, 0, mouse_move, mlx);
//}

int 			main(int ac, char **av)
{
	t_batisa	*coord;
	t_map		*map;
	t_mlx		*mlx;
	int 		fd;
	int j = 0;

	coord = NULL;
	if (!(map = map_init()))
		return (0);
	if (!(read_input((fd = open(av[1], O_RDONLY)), map, &coord)))
		return (0);
	coord_to_arr(&coord, map);
	mlx = mlx_data(map);
	draw(map, mlx);
//	set_hook(mlx);
	mlx_loop(mlx->mlx_ptr);
//	while (coord)
//	{
//		while(j < map->height)
//		{
//			for (int i = 0; i < map->width; i++)
//			{
//				printf("%3d", coord->z);
////				printf("-|_%d", coord->clr);
//				coord = coord->next;
//			}
//			printf("\n");
//			j++;
//		}
//	}
}
