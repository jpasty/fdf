/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 22:29:18 by jpasty            #+#    #+#             */
/*   Updated: 2020/03/11 22:29:23 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int ac, char **av)
{
	t_batisa	*coord;
	t_map		*map;
	t_mlx		*mlx;

	if (ac != 2)
		ft_errno(E2BIG, "Invalid number of arguments");
	coord = NULL;
	map = map_init();
	read_input(open(av[1], O_RDONLY), map, &coord);
	coord_to_arr(&coord, map);
	mlx = mlx_data(map);
	draw(map, mlx);
	set_hook(mlx, map);
	mlx_loop(mlx->mlx_ptr);
}
