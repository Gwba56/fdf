/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarach- <gbarach-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 03:21:28 by gbarach-          #+#    #+#             */
/*   Updated: 2019/08/01 03:21:34 by gbarach-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		highlight_pixel(t_env *fdf, int x, int y, int color)
{
	int i;

	if (x < IMG_X && x >= 0 && y >= 0 && y < IMG_Y)
	{
		i = (x * fdf->bpp / 8) + (y * fdf->size_line);
		fdf->data_addr[i] = color;
		fdf->data_addr[++i] = color >> 8;
		fdf->data_addr[++i] = color >> 16;
	}
}

void			set_positions(t_seg *s)
{
	s->p_cur.x = s->p0.x;
	s->p_cur.y = s->p0.y;
	s->dx = s->p1.x - s->p0.x;
	s->dy = s->p1.y - s->p0.y;
	s->xinc = (s->dx > 0) ? 1 : -1;
	s->yinc = (s->dy > 0) ? 1 : -1;
	s->dx = ft_abs(s->dx);
	s->dy = ft_abs(s->dy);
}

void			draw_pixels(t_seg *s, t_env *fdf)
{
	int i;

	i = 1;
	s->er = s->dy / 2;
	while (i++ <= s->dy)
	{
		s->p_cur.y += s->yinc;
		s->er += s->dx;
		if (s->er >= s->dy)
		{
			s->er -= s->dy;
			s->p_cur.x += s->xinc;
		}
		highlight_pixel(fdf, s->p_cur.x, s->p_cur.y, get_color(s));
	}
}

void			draw_line(t_seg *s, t_env *fdf)
{
	int i;

	set_positions(s);
	highlight_pixel(fdf, s->p_cur.x, s->p_cur.y, get_color(s));
	if (s->dx > s->dy)
	{
		s->er = s->dx / 2;
		i = 1;
		while (i++ <= s->dx)
		{
			s->p_cur.x += s->xinc;
			s->er += s->dy;
			if (s->er >= s->dx)
			{
				s->er -= s->dx;
				s->p_cur.y += s->yinc;
			}
			highlight_pixel(fdf, s->p_cur.x, s->p_cur.y, get_color(s));
		}
	}
	else
		draw_pixels(s, fdf);
}
