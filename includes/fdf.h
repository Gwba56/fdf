/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarach- <gbarach-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 10:40:21 by gbarach-          #+#    #+#             */
/*   Updated: 2019/07/31 19:22:41 by tefourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

/*
 *** Dimensions
*/

# define UX_X 300
# define UX_Y 1000
# define WIN_X 1300
# define WIN_Y 1000
# define IMG_X 1000
# define IMG_Y 1000

/*
 *** Colors & UI
*/

# define GUNMETAL 0x30343F
# define CHARLESTON_GREEN 0x272D2D
# define GHOST_WHITE 0xF8F8F8
# define GLITTER 0xE9EBF8

/*
 *** THEMES
*/

# define TURQUOISE 0x44FFD1
# define IRIS 0x0057FF
# define VIOLET 0xAB3616
# define RUBY 0xC40081
# define YELLOW 0xFFFF00
# define LAPIS_LAZULI 0x247BA0
# define GREEN_SHEEN 0x70C1B3
# define PALE_YELLOW 0xF3FFBD
# define AWESOME 0xFF1654
# define RUSSIAN_VIOLET 0x14287103
# define SAPPHIRE 0x015AAB
# define GREEN_YELLOW 0xAFFC41

typedef struct	s_theme
{
	int		color_1;
	int		color_2;
	int		color_3;
	int		color_4;
	int		color_5;
}				t_theme;

typedef struct	s_pt
{
	int		x;
	int		y;
	int		z;
	int		color;
}				t_pt;

typedef struct	s_seg
{
	t_pt	p0;
	t_pt	p1;
	t_pt	p_cur;
	int		dx;
	int		dy;
	int		er;
	int		xinc;
	int		yinc;
}				t_seg;

typedef struct	s_data
{
	int		fd;
	int		check;
	t_list	*data;
	int		height;
	int		width;
}				t_data;

typedef struct	s_map
{
	t_pt	**matrix;
	int		cols;
	int		rows;
}				t_map;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data_addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		scale;
	int		dpt;
	t_pt	p1;
	t_pt	diff;
	t_pt	ctr;
	int		proj;
	int		theme;
	int		diff_x;
	int		diff_y;
	t_map	*map;
	t_theme th;
}				t_env;

int				handle_error(int i);
int				check_file(int ac, char *av, t_data *fdf);
int				check_data(t_data *fdf);
t_map			*convert_data(t_data *fdf);
t_env			*new_image(t_env *mlx);
void			init_env(t_env *fdf);
void			ui(t_env *fdf);
int				key_event(int key, void *param);
int				close_window(void *param);
void			draw(t_env *fdf);
void			draw_line(t_seg *s, t_env *fdf);
void			draw_image(t_env *fdf);
int				get_color(t_seg *s);
int				define_color(int z, t_env *fdf);

#endif
