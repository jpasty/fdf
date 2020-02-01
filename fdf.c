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
	map->mlx_ptr = 0;
	map->win_ptr = 0;
	return (map);
}

static int 		ft_is_digit(char s, int base)
{
	char		*digit;
	int			i;

	digit = "0123456789ABCDEF";
	i = 0;
	if (!s)
		return (0);
	while (i < base)
	{
		if (digit[i] == ft_toupper(s))
			return (1);
		i++;
	}
	return (0);
}

static int 		ft_is_space(int c)
{
	if (c == ' ' || c == '\t' ||
		c == '\r' || c == '\f' || c == '\v')
		return (1);
	return  (0);
}

static int	 		ft_atoi_base(char *s, int base)
{
	unsigned long	res;
	int				sign;
	int				i;

	res = 0;
	sign = 1;
	i = 0;
	while (ft_is_space(s[i]))
		i++;
	if (base == 10 && (s[i] == '-' || s[i] == '+'))
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	if (base == 2 || base == 16)
		i += 2;
	while (ft_is_digit(s[i], base))
		res = res * base + s[i++] - '0';
	return ((int)(res * sign));
}

static int 		ft_is_num(char *s, int base)
{
	int			i;
	i = 0;
	while (ft_is_space(s[i]))
		i++;
	if (base == 2 || base == 16)
		i += 2;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] && ft_is_digit(s[i], base))
		i++;
	return s[i] ? 0 : 1;
}

void			add_new_coord(t_batisa **lst_coord, t_batisa *new_coord)
{
	if (lst_coord)
	{
		if (new_coord)
		{
			new_coord->next = *lst_coord;
			*lst_coord = new_coord;
		}
	}
}

t_batisa		*get_new_coord(char *s)
{
	t_batisa 	*new_coord;
	char 		**div;

	if (!(new_coord = (t_batisa *)malloc(sizeof(t_batisa))))
		return (NULL);
	div = ft_strsplit(s, ',');
	if (!ft_is_num(div[0], 10))
		return (0);
	new_coord->z = ft_atoi(div[0]);
	if (div[1])
	{
		if (!ft_is_num(div[1], 16))
			return (0);
	}
	new_coord->clr = div[1] ? ft_atoi_base(div[1], 16) : DEF_COLOR;
	new_coord->next = NULL;
	return (new_coord);
}

static int 		check_input(char **split, t_map *map, t_batisa **coord)
{
	int 		width;
	t_batisa	*new_coord;

	width = 0;
	while (split[width])
		add_new_coord(coord, get_new_coord(split[width++]));
	if (map->height == 0)
		map->width = width;
	if (width != map->width)
		return (0);
	return (1);

}

static int		read_input(const int fd,t_map *map, t_batisa **coord)
{
	char 		*line;
	char		**split;

	while (get_next_line(fd, &line))
	{
		if (!(split = ft_strsplit(line, ' ')))
			return (0);
		check_input(split, map, coord);
		map->height++;
	}

}

int 			main(int ac, char **av)
{
	t_batisa	*coord;
	t_map		*map;
	int 		fd;

	coord = NULL;
	if (!(map = map_init()))
		return (0);
	if (!(read_input((fd = open(av[1], O_RDONLY)), map, &coord)))
		return (0);
}
