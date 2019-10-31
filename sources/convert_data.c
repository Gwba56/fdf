/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarach- <gbarach-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 03:21:15 by gbarach-          #+#    #+#             */
/*   Updated: 2019/08/06 17:03:20 by gbarach-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>

t_pt	*convert_line(char *line, int len, int y)
{
	char	**split;
	int		i;
	t_pt	*tab;

	if (!(split = ft_strsplit(line, ' ')))
		return (NULL);
	if (!(tab = (t_pt *)ft_memalloc(sizeof(t_pt) * len - 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		tab[i].x = i;
		tab[i].y = y;
		if (split[i][0] == '0')
			tab[i].z = 0;
		else if (!(tab[i].z = ft_atoi(split[i])))
			handle_error(5);
		if (tab[i].z >= IMG_Y || tab[i].z <= -IMG_Y)
			handle_error(6);
		free(split[i]);
		i++;
	}
	free(split);
	return (tab);
}

t_pt	**fill_matrix(t_data *file)
{
	t_list	*tmp;
	t_pt	**matrix;
	int		i;

	if (!(matrix = (t_pt **)ft_calloc(file->height, sizeof(t_pt *))))
		return (NULL);
	i = 0;
	tmp = file->data;
	while (tmp)
	{
		matrix[i] = convert_line(tmp->content, file->width, i);
		tmp = tmp->next;
		i++;
	}
	return (matrix);
}

t_map	*convert_data(t_data *fdf)
{
	t_map	*map;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		return (NULL);
	map->cols = fdf->width;
	map->rows = fdf->height;
	map->matrix = fill_matrix(fdf);
	return (map);
}
