#include "fdf.h"
int 		set_default_clr(int z, t_map *map)
{
	double percent;

	percent = ratio(map->z_min, map->z_max, z);
	if (percent < 0.2)
		return (COLOR_DISCO);
	else if (percent < 0.4)
		return (COLOR_BRICK_RED);
	else if (percent < 0.6)
		return (COLOR_FLAMINGO);
	else if (percent < 0.8)
		return (COLOR_JAFFA);
	else
		return (COLOR_SAFFRON);
}

int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	set_clr(int cury, int curx, t_point cur, t_point ps, t_point pe)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;
	t_point	d;

	d.x = abs(pe.x - ps.x);
	d.y = abs(pe.y - ps.y);
	if (cur.clr == pe.clr)
		return (cur.clr);
	if (d.x > d.y)
		percentage = ratio(ps.x, pe.x, curx);
	else
		percentage = ratio(ps.y, pe.y, cury);
	red = get_light((ps.clr >> 16) & 0xFF,
					(pe.clr >> 16) & 0xFF,
					percentage);
	green = get_light((ps.clr >> 8) & 0xFF,
					  (pe.clr >> 8) & 0xFF,
					  percentage);
	blue = get_light(ps.clr & 0xFF,
					 pe.clr & 0xFF,
					 percentage);
	return ((red << 16) | (green << 8) | blue);
}