/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarach- <gbarach-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:31:44 by gbarach-          #+#    #+#             */
/*   Updated: 2019/07/31 18:32:26 by gbarach-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	color_background(t_env *fdf)
{
	int	x;
	int y;

	y = 0;
	while (y < UX_Y)
	{
		x = WIN_X - UX_X;
		while (x <= WIN_X)
		{
			if (x <= (WIN_X - UX_X) + 3 || y >= (UX_Y))
				mlx_pixel_put(fdf->mlx, fdf->win, x, y, GLITTER);
			else
				mlx_pixel_put(fdf->mlx, fdf->win, x, y, CHARLESTON_GREEN);
			x++;
		}
		y++;
	}
}

void	ui(t_env *fdf)
{
	int	start;

	start = (WIN_X - UX_X) + 17;
	color_background(fdf);
	mlx_string_put(fdf->mlx, fdf->win, start, 100, GHOST_WHITE, "GUIDE");
	mlx_string_put(fdf->mlx, fdf->win, start,
	150, GHOST_WHITE, "More depth : +");
	mlx_string_put(fdf->mlx, fdf->win, start,
	185, GHOST_WHITE, "Less depth : -");
	mlx_string_put(fdf->mlx, fdf->win, start, 220, GHOST_WHITE, "Zoom in : z");
	mlx_string_put(fdf->mlx, fdf->win, start, 255, GHOST_WHITE, "Zoom out : x");
	mlx_string_put(fdf->mlx, fdf->win,
	start, 290, GHOST_WHITE, "Move : ^ v < >");
	mlx_string_put(fdf->mlx, fdf->win,
	start, 325, GHOST_WHITE, "Isometric : I");
	mlx_string_put(fdf->mlx, fdf->win, start, 360, GHOST_WHITE, "Parallel : P");
	mlx_string_put(fdf->mlx, fdf->win,
	start, 395, GHOST_WHITE, "Color Themes : 1, 2 or 3");
	mlx_string_put(fdf->mlx, fdf->win, start, 430, GHOST_WHITE, "Exit : Esc");
}
