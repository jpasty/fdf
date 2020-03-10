#include "fdf.h"

t_batisa		*extract_coord(t_batisa **coord)
{
	t_batisa	*head;

	head = NULL;
	if (coord && *coord)
	{
		head = *coord;
		*coord = (*coord)->next;
	}
	return (head);
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

void			coord_to_arr(t_batisa **coord, t_map *map)
{
	t_batisa	*curr;
	long 		i;
	size_t 		arr_size;

	i = map->width * map->height - 1;
	arr_size = map->width * map->height * sizeof(int);
	if (!(map->z_arr = (int *)ft_memalloc( arr_size))
			|| !(map->clr_arr = (int *)ft_memalloc(arr_size)))
		return ;
	while ((curr = extract_coord(coord)) && i >= 0)
	{
		map->z_arr[i] = curr->z;
		map->clr_arr[i] = curr->clr;
		if (curr->z > map->z_max)
			map->z_max = curr->z;
		if (curr->z < map->z_min)
			map->z_min = curr->z;
		free(curr);
		i--;
	}
	map->z_range = map->z_max - map->z_min;
}

static t_batisa	*get_new_coord(char *s)
{
	t_batisa 	*new_coord;
	char 		**div;

	if (!(new_coord = (t_batisa *)malloc(sizeof(t_batisa))))
		return (NULL);
	div = ft_strsplit(s, ',');
	if (!ft_is_num(div[0], 10))
		return (0);
	new_coord->z = ft_atoi(div[0]);
	new_coord->clr =  div[1] ? ft_atoi_base(div[1], 16) : -1;
	new_coord->next = NULL;
	return (new_coord);
}

static int 		check_input(char **split, t_map *map, t_batisa **coord)
{
	int 		width;
	t_batisa	*new_coord;

	width = 0;
	while (split[width])
	{
		new_coord = get_new_coord(split[width++]);
		add_new_coord(coord, new_coord);
	}
	if (map->height == 0)
		map->width = width;
	if (width != map->width)
		return (0);
	return (1);

}

int			read_input(int fd,t_map *map, t_batisa **coord)
{
	char 	*line;
	char 	**split;
	int 	res;

	while ((res = get_next_line(fd, &line)) == 1)
	{
		if (!(split = ft_strsplit(line, ' ')))
			return (0);
		check_input(split, map, coord);
		map->height++;
		free(split);
		free(line);
	}
	return (1);
	/*while (coord)
	{
		while(j < map->height)
		{
			for (int i = 0; i < map->width; i++)
			{
				printf("%3d", coord->z);
				printf("-|_%d", coord->clr);
				coord = coord->next;
			}
			printf("\n");
			j++;
		}
	}*/
}

/*
static int 		ft_get_base(char **s)
{
	int 		base;
	int 		i;

	base = 10;
	i = 0;
	if (s[i] == 0)
	{
		if (s[i] == 'b' || s[i] == 'B')
			return (base = 2);
		else if (s[i] == 'x' || s[i] == 'X')
			return (base = 16);
	}
	return (base);
}

static int 		ft_find_prefix(char *s, int base)
{
	int i;

	i = 0;
	if (s[i++])
	if (base == 2 && ())
}

static int 		ft_isnumber(char *s, int base)
{
	int			i;
	int 		d;

	i = 0;

	if (base == 16)
		i += 2;
	if (base != 10 && !(ft_find_prefix(s, base)))
	while (s[i])
	{

		i++;
			return (0);
	}
}

}

static int 		check_line(char **split, t_mlx *map, t_list **z_arr)
{
	int 		i;
	int 		base;
	char 		**div;
	t_list		*z_coord;

	i = 0;
	while (split[i])
	{
		if (!(div = ft_strsplit(split[i], ',')))
			return (0);
		if (!(ft_isnumber(div[0], 10);
			return (0);
		i++;
	}
	map->arr = *z_arr;
	return (1);
}

static int		check_input(char **split, t_mlx *map, t_list **z_arr)
{

	int 		width;
	int 		i;

	width = 0;
	i = 0;
	while (split[i++])
		width++;
	if (map->height == 0)
		map->width = width;
	if (map->width != width)
		return (0);
	check_line(split, map, z_arr);
	return (width);
}

void	 	read_input(const int fd, t_mlx *map, t_list **z_arr)
{
	char **split;
	char *line;
	int j;
	int i;

	j = 0;
	while (get_next_line(fd, &line))
	{
		i = 0;
		if (!(split = ft_strsplit(line,' ')))
			return (NULL);
		if (!(check_input(split, map, z_arr)))
			while (map->z_point[j])
			printf("%d", map->z_point[j++]);
		map->height++;
	}
}

0kj 0 0 0 0 0 0 0 2 2 4 4 0 0
int check_inputs(char *s, t_list *map)
{
	int i;
	int elem;

	i = 0;
	elem = 1;
	while (s[i])
	{
		while (ft_is_spase(s[i]))
			i++;
		while (s[i] || ft_is_spase(s[i])))
		{
			if (s[i] = ',')
			{

			}
			if (!(ft_is_digit(s[i])))
				return (0);
			i++;
		}
		elem++;
	}
}
*/
