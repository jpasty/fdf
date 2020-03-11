/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 21:38:33 by cshinoha          #+#    #+#             */
/*   Updated: 2020/03/11 18:30:44 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			key_press(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (key == MAIN_PAD_ESC)
		exit(0);
	if (key == NUM_PAD_PLUS || key == MAIN_PAD_PLUS
		|| key == NUM_PAD_MINUS || key == MAIN_PAD_MINUS)
		zoom(key, mlx);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT
			 || key == ARROW_UP || key == ARROW_DOWN)
		move(key, mlx);
	else if (key == NUM_PAD_1 || key == MAIN_PAD_1
			 || key == NUM_PAD_2 || key == MAIN_PAD_2
			 || key == NUM_PAD_3 || key == MAIN_PAD_3
			 || key == NUM_PAD_4 || key == MAIN_PAD_4
			 || key == NUM_PAD_6 || key == MAIN_PAD_6
			 || key == NUM_PAD_7 || key == MAIN_PAD_7
			 || key == NUM_PAD_8 || key == MAIN_PAD_8
			 || key == NUM_PAD_9 || key == MAIN_PAD_9)
		rotate(key, mlx);
	else if (key == MAIN_PAD_LESS || key == MAIN_PAD_MORE)
		flatten(key, mlx);
	else if (key == MAIN_PAD_P || key == MAIN_PAD_I)
		change_projection(key, mlx);
	return (0);
}
//
//static int			mouse_press(int button, int x, int y, void *param)
//{
//	t_fdf	*fdf;
//
//	(void)x;
//	(void)y;
//	fdf = (t_fdf *)param;
//	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
//		zoom(button, fdf);
//	else if (button == MOUSE_LEFT_BUTTON)
//		fdf->mouse->is_pressed = true;
//	return (0);
//}
//
///*
//** Handle mouse release
//*/
//
//static int			mouse_release(int button, int x, int y, void *param)
//{
//	t_fdf	*fdf;
//
//	(void)x;
//	(void)y;
//	(void)button;
//	fdf = (t_fdf *)param;
//	fdf->mouse->is_pressed = false;
//	return (0);
//}
//
///*
//** Handle mouse move
//*/
//
//static int			mouse_move(int x, int y, void *param)
//{
//	t_fdf	*fdf;
//
//	fdf = (t_fdf *)param;
//	fdf->mouse->previous_x = fdf->mouse->x;
//	fdf->mouse->previous_y = fdf->mouse->y;
//	fdf->mouse->x = x;
//	fdf->mouse->y = y;
//	if (fdf->mouse->is_pressed)
//	{
//		fdf->camera->beta += (x - fdf->mouse->previous_x) * 0.002;
//		fdf->camera->alpha += (y - fdf->mouse->previous_y) * 0.002;
//		draw(fdf->map, fdf);
//	}
//	return (0);
//}

void	set_hook(t_mlx *mlx, t_map *map)
{
	mlx->map = map;
	mlx_hook(mlx->win_ptr, 2, 0, key_press, mlx);
//	mlx_hook(mlx->win_ptr, 17, 0, close, mlx);
//	mlx_hook(mlx->win_ptr, 4, 0, mouse_press, mlx);
//	mlx_hook(mlx->win_ptr, 5, 0, mouse_release, mlx);
//	mlx_hook(mlx->win_ptr, 6, 0, mouse_move, mlx);
}