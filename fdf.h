#ifndef UNTITLED_FDF_H
#define UNTITLED_FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "get_next_line.h"

#define  DEF_COLOR	0xFECA99

typedef struct		s_batisa
{
	int 			z;
	int 			clr;
	struct s_coord	*next;
}					t_batisa;

typedef struct		s_map
{
	int				width;
	int				height;
	int				*clr_arr;
	int				*z_arr;
	void			*mlx_ptr;
	void			*win_ptr;
}					t_map;



typedef struct		s_point
{
	int				x;
	int				y;
	int 			z;
	int				color;
}					t_point;

typedef struct		s_event
{

}					t_event;


int					get_next_line(const int fd, char **line);

#endif
