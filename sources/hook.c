/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarach- <gbarach-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:30:23 by gbarach-          #+#    #+#             */
/*   Updated: 2019/08/01 03:24:10 by gbarach-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>

int		close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int		theme_event(int key, t_env *fdf)
{
	if (key == 83 || key == 18)
		fdf->theme = 1;
	else if (key == 84 || key == 19)
		fdf->theme = 2;
	else if (key == 85 || key == 20)
		fdf->theme = 3;
	return (fdf->theme);
}

void	move(int key, t_env *fdf)
{
	if (key == 126)
	{
		fdf->p1.y -= 5;
		fdf->p1.x = (fdf->proj == 1) ? fdf->p1.x - 5 : fdf->p1.x;
	}
	else if (key == 125)
	{
		fdf->p1.y += 5;
		fdf->p1.x = (fdf->proj == 1) ? fdf->p1.x + 5 : fdf->p1.x;
	}
	else if (key == 124)
	{
		fdf->p1.x += 5;
		fdf->p1.y = (fdf->proj == 1) ? fdf->p1.y - 5 : fdf->p1.y;
	}
	else if (key == 123)
	{
		fdf->p1.x -= 5;
		fdf->p1.y = (fdf->proj == 1) ? fdf->p1.y + 5 : fdf->p1.y;
	}
}

void	zoom(int key, t_env *fdf)
{
	if (key == 6)
		fdf->scale++;
	else if (key == 7 && fdf->scale >= 2)
		fdf->scale--;
}

int		key_event(int key, void *param)
{
	t_env	*fdf;

	fdf = (t_env *)param;
	if (key == 53)
		exit(0);
	else if (key == 24 || key == 69)
		fdf->dpt++;
	else if (key == 27 || key == 78)
		fdf->dpt--;
	else if (key == 6 || key == 7)
		zoom(key, fdf);
	else if (key == 126 || key == 125 || key == 124 || key == 123)
		move(key, fdf);
	else if (key == 34 || key == 35)
		fdf->proj = (key == 34) ? 1 : 0;
	else if (theme_event(key, fdf))
		fdf->theme = theme_event(key, fdf);
	draw_image(fdf);
	return (0);
}
