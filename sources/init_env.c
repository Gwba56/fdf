/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarach- <gbarach-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:17:02 by gbarach-          #+#    #+#             */
/*   Updated: 2019/08/01 01:29:05 by gbarach-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

int			calc_scale(t_env *fdf)
{
	int		scale;
	int		base;

	base = IMG_X / 1.7;
	if (fdf->map->cols >= IMG_X || fdf->map->rows >= IMG_Y)
		scale = 1;
	else if (fdf->map->cols >= fdf->map->rows)
		scale = base / fdf->map->cols;
	else
		scale = base / fdf->map->rows;
	return (scale);
}

static t_pt	calc_first_coords(t_env *fdf)
{
	t_pt	p1;

	p1.x = (IMG_X - ((fdf->map->cols - 1) * fdf->scale)) / 2;
	p1.y = (IMG_Y - ((fdf->map->rows - 1) * fdf->scale)) / 2;
	p1.z = fdf->map->matrix[0][0].z;
	return (p1);
}

t_pt		calc_iso_diff(t_env *fdf)
{
	t_pt	diff;
	t_pt	next;
	t_pt	tmp;
	t_pt	marg;

	next.x = fdf->p1.x + fdf->scale;
	next.y = fdf->p1.y + fdf->scale;
	tmp.x = next.x;
	tmp.y = next.y;
	next.x = (tmp.x - tmp.y) * cos(0.523599);
	next.y = (tmp.x + tmp.y) * sin(0.523599);
	marg.x = ((fdf->map->cols - 2) * fdf->scale) / 2;
	diff.x = next.x - fdf->p1.x - marg.x;
	diff.y = next.y - fdf->p1.y;
	return (diff);
}

void		init_env(t_env *fdf)
{
	fdf->proj = 0;
	fdf->diff_x = 0;
	fdf->diff_y = 0;
	fdf->dpt = 2;
	fdf->scale = calc_scale(fdf);
	fdf->p1 = calc_first_coords(fdf);
	fdf->diff = calc_iso_diff(fdf);
	fdf->theme = 1;
}
