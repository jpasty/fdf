/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:41:08 by cshinoha          #+#    #+#             */
/*   Updated: 2020/03/11 22:19:38 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
				   65, 20, TEXT_COLOR, "How to Use");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
				   15, 55, TEXT_COLOR, "Zoom: Scroll or +/-");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
				   15, 85, TEXT_COLOR, "Move: Arrows");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
				   15, 115, TEXT_COLOR, "Flatten: </>");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
				   15, 145, TEXT_COLOR, "Rotate: Press & Move");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 15, 175, TEXT_COLOR, "Rotate:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
			57, 200, TEXT_COLOR, "X-Axis - 2/8");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
			57, 225, TEXT_COLOR, "Y-Axis - 4/6");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
			57, 255, TEXT_COLOR, "Z-Axis - 1(3)/7(9)");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
			15, 285, TEXT_COLOR, "Projection");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
			57, 315, TEXT_COLOR, "ISO: I Key");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
			57, 330, TEXT_COLOR, "Parallel: P Key");
}