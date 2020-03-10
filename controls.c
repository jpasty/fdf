#include "controls.h"
#include "fdf.h"

void	zoom(int key, t_mlx *mlx)
{
	if (key == NUM_PAD_PLUS ||
		key == MAIN_PAD_PLUS ||
		key == MOUSE_SCROLL_UP)
		mlx->cam->zoom++;
	else if (key == NUM_PAD_MINUS ||
			 key == MAIN_PAD_MINUS ||
			 key == MOUSE_SCROLL_DOWN)
		mlx->cam->zoom--;
	if (mlx->cam->zoom < 1)
		mlx->cam->zoom = 1;
	draw(mlx->map, mlx);
}

void	move(int key, t_mlx *mlx)
{
	if (key == ARROW_LEFT)
		mlx->cam->x_offset -= 10;
	else if (key == ARROW_RIGHT)
		mlx->cam->x_offset += 10;
	else if (key == ARROW_UP)
		mlx->cam->y_offset -= 10;
	else
		mlx->cam->y_offset += 10;
	draw(mlx->map, mlx);
}

void	rotate(int key, t_mlx *mlx)
{
	if (key == NUM_PAD_2 || key == MAIN_PAD_2)
		mlx->cam->alpha += 0.05;
	else if (key == NUM_PAD_8 || key == MAIN_PAD_8)
		mlx->cam->alpha -= 0.05;
	else if (key == NUM_PAD_4 || key == MAIN_PAD_4)
		mlx->cam->beta -= 0.05;
	else if (key == NUM_PAD_6 || key == MAIN_PAD_6)
		mlx->cam->beta += 0.05;
	else if (key == NUM_PAD_1 || key == MAIN_PAD_1
			 || key == NUM_PAD_3 || key == MAIN_PAD_3)
		mlx->cam->gamma += 0.05;
	else if (key == NUM_PAD_7 || key == MAIN_PAD_7
			 || key == NUM_PAD_9 || key == MAIN_PAD_9)
		mlx->cam->gamma -= 0.05;
	draw(mlx->map, mlx);
}

void	flatten(int key, t_mlx *mlx)
{
	if (key == MAIN_PAD_LESS)
		mlx->cam->z_divisor -= 0.1;
	else if (key == MAIN_PAD_MORE)
		mlx->cam->z_divisor += 0.1;
	if (mlx->cam->z_divisor < 0.1)
		mlx->cam->z_divisor = 0.1;
	else if (mlx->cam->z_divisor > 10)
		mlx->cam->z_divisor = 10;
	draw(mlx->map, mlx);
}

void	change_projection(int key, t_mlx *mlx)
{
	mlx->cam->alpha = 0;
	mlx->cam->beta = 0;
	mlx->cam->gamma = 0;
	if (key == MAIN_PAD_I)
		mlx->cam->projection = 0;
	else if (key == MAIN_PAD_P)
		mlx->cam->projection = 1;
	draw(mlx->map, mlx);
}