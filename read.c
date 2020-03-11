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
	map->z_arr = (int *)ft_memalloc(arr_size);
	map->clr_arr = (int *)ft_memalloc(arr_size);
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
		ft_errno(ENOMEM, "t_batisa allocation error");
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
			ft_errno(0, "Read file error");
		if (!check_input(split, map, coord))
			ft_errno(0, "Wrong map");
		map->height++;
		free(split);
		free(line);
	}
	if (res == -1)
		ft_errno(0, "Read file error");
	return (res);
}
