/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradients.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarach- <gbarach-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:21:48 by tefourge          #+#    #+#             */
/*   Updated: 2019/08/06 16:59:57 by gbarach-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	define_theme(t_env *fdf)
{
	if (fdf->theme == 1)
	{
		fdf->th.color_1 = TURQUOISE;
		fdf->th.color_2 = IRIS;
		fdf->th.color_3 = VIOLET;
		fdf->th.color_4 = RUBY;
		fdf->th.color_5 = YELLOW;
	}
	else if (fdf->theme == 2)
	{
		fdf->th.color_1 = GREEN_SHEEN;
		fdf->th.color_2 = GHOST_WHITE;
		fdf->th.color_3 = LAPIS_LAZULI;
		fdf->th.color_4 = PALE_YELLOW;
		fdf->th.color_5 = AWESOME;
	}
	else if (fdf->theme == 3)
	{
		fdf->th.color_1 = RUSSIAN_VIOLET;
		fdf->th.color_2 = SAPPHIRE;
		fdf->th.color_3 = AWESOME;
		fdf->th.color_4 = GREEN_YELLOW;
		fdf->th.color_5 = GHOST_WHITE;
	}
}

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		define_color(int z, t_env *fdf)
{
	define_theme(fdf);
	if (z < -5)
		return (fdf->th.color_1);
	else if (z <= 0)
		return (fdf->th.color_2);
	else if (z <= 5)
		return (fdf->th.color_3);
	else if (z <= 10)
		return (fdf->th.color_4);
	else
		return (fdf->th.color_5);
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		get_color(t_seg *s)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (s->p_cur.color == s->p1.color)
		return (s->p_cur.color);
	if (s->dx > s->dy)
		percentage = percent(s->p0.x, s->p1.x, s->p_cur.x);
	else
		percentage = percent(s->p0.y, s->p1.y, s->p_cur.y);
	red = get_light((s->p0.color >> 16) & 0xFF,
	(s->p1.color >> 16) & 0xFF, percentage);
	green = get_light((s->p0.color >> 8) & 0xFF,
	(s->p1.color >> 8) & 0xFF, percentage);
	blue = get_light(s->p0.color & 0xFF, s->p1.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
