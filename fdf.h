#ifndef UNTITLED_FDF_H
#define UNTITLED_FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"
# include "controls.h"
# include "stdio.h"

# define HEIGHT			1080
# define WIDTH			1920
# define MENU_WIDTH		250

# define HEAD_COLOR			0x35bbca
# define TEXT_COLOR			0xffb836
# define BACKGROUND			0x282a36
# define MENU_BACKGROUND	0x262626

# define COLOR_SKY		0x35bbca
# define COLOR_OCEAN	0x0191b4
# define COLOR_YELLOW	0xf8d90f
# define COLOR_GREEN	0xd3dd18
# define COLOR_ORANGE	0xfe7a15

typedef struct		s_batisa
{
	int 			z;
	int 			clr;
	struct s_batisa	*next;
}					t_batisa;

typedef struct		s_map
{
	int				width;
	int				height;
	int				*clr_arr;
	int				*z_arr;
	int 			z_max;
	int				z_min;
}					t_map;

typedef struct 		s_cam
{
	int 			projection;
	int 			zoom;
	double			alpha;
	double			beta;
	double			gamma;
	float			z_divisor;
	int				x_offset;
	int				y_offset;
}					t_cam;

typedef struct		s_mouse
{
	int				is_pressed;
	int				x;
	int				y;
	int				previous_x;
	int				previous_y;
}					t_mouse;

typedef struct 		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data_ptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	t_cam			*cam;
	t_map			*map;
	t_mouse			*mouse;
}					t_mlx;

typedef struct 		s_draw
{
	int 			rise;
	int 			run;
	float 			m;
	int 			threshold;
	int 			thresholdInc;
	int 			offset;
	int 			adjust;
	int 			delta;
}					t_draw;

typedef struct		s_point
{
	int				x;
	int				y;
	int 			z;
	int				clr;
}					t_point;

void				print_menu(t_mlx *mlx);
void				set_hook(t_mlx *mlx, t_map *map);
int					read_input(int fd,t_map *map, t_batisa **coord);
int 				ft_is_digit(char s, int base);
int 				ft_is_space(int c);
int	 				ft_atoi_base(char *s, int base);
int 				ft_is_num(char *s, int base);
void				coord_to_arr(t_batisa **coord, t_map *map);
void 				brsnhm(t_point p1, t_point p2, t_mlx *mlx);
void				add_new_coord(t_batisa **lst_coord, t_batisa *new_coord);
t_batisa			*extract_coord(t_batisa **coord);
t_map 				*map_init();
t_mlx 				*mlx_data(t_map *map);
void				line_init(t_draw *line, t_point *p1, t_point *p2);
void				draw(t_map *map, t_mlx *mlx);
t_point 			projection(t_point p, t_mlx *mlx, t_map *map);
void				zoom(int key, t_mlx *mlx);
void				move(int key, t_mlx *mlx);
void				rotate(int key, t_mlx *mlx);
void				altitude(int key, t_mlx *mlx);
void				change_projection(int key, t_mlx *mlx);
double 				ratio(int z_min, int z_max, int z);
int 				set_default_clr(int z, t_map *map);
int					set_clr(int cury, int curx, t_point cur, t_point ps, t_point pe);
int 				closed(void *param);

#endif
