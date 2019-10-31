/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarach- <gbarach-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 03:20:42 by gbarach-          #+#    #+#             */
/*   Updated: 2019/08/01 03:20:52 by gbarach-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

t_pt	calc_position(t_pt *pt, t_env *fdf)
{
	t_pt	new_pt;
	t_pt	tmp;

	new_pt.x = fdf->p1.x + (pt->x * fdf->scale);
	new_pt.y = fdf->p1.y + (pt->y * fdf->scale);
	if (fdf->proj == 1)
	{
		tmp.x = new_pt.x;
		tmp.y = new_pt.y;
		new_pt.x = (tmp.x - tmp.y) * cos(0.523599);
		new_pt.y = (tmp.x + tmp.y) * sin(0.523599);
		new_pt.x -= fdf->diff.x;
		new_pt.y -= fdf->diff.y;
	}
	new_pt.y -= ((pt->z - fdf->p1.z) * fdf->dpt);
	new_pt.color = define_color(pt->z, fdf);
	return (new_pt);
}

void	draw_cols(t_env *fdf)
{
	int		i;
	int		j;
	t_seg	s;

	j = 0;
	while (j < fdf->map->cols)
	{
		if (!fdf->map->matrix)
			break ;
		i = 0;
		while (i < fdf->map->rows - 1)
		{
			s.p0 = calc_position(&(fdf->map->matrix[i][j]), fdf);
			s.p1 = calc_position(&(fdf->map->matrix[i + 1][j]), fdf);
			draw_line(&s, fdf);
			i++;
		}
		j++;
	}
}

void	draw_rows(t_env *fdf)
{
	int		i;
	int		j;
	t_seg	s;

	i = 0;
	while (i < fdf->map->rows)
	{
		if (!fdf->map->matrix)
			break ;
		j = 0;
		while (j < fdf->map->cols - 1)
		{
			s.p0 = calc_position(&(fdf->map->matrix[i][j]), fdf);
			s.p1 = calc_position(&(fdf->map->matrix[i][j + 1]), fdf);
			draw_line(&s, fdf);
			j++;
		}
		i++;
	}
}

void	draw_image(t_env *fdf)
{
	int		*image;

	ft_bzero(fdf->data_addr, IMG_X * IMG_Y * (fdf->bpp / 8));
	image = (int *)(fdf->data_addr);
	draw_rows(fdf);
	draw_cols(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

void	draw(t_env *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_X, WIN_Y, "Fdf");
	fdf->img = mlx_new_image(fdf->mlx, IMG_X, IMG_Y);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bpp),
	&(fdf->size_line), &(fdf->endian));
	ui(fdf);
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
	mlx_hook(fdf->win, 2, 0, key_event, fdf);
	draw_image(fdf);
	mlx_loop(fdf->mlx);
}
