/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarach- <gbarach-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:18:27 by gbarach-          #+#    #+#             */
/*   Updated: 2019/08/01 02:23:56 by gbarach-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		line_is_valid(const char *str)
{
	const char	*tmp;

	tmp = str;
	while (*tmp)
	{
		if (*tmp != 'x' && !ft_iswhitespace(*tmp) && *tmp != '-'
			&& !ft_ishexa(*tmp) && *tmp != ',')
			return (0);
		tmp++;
	}
	return (1);
}

void	check_lines(t_list *data)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = data;
	while (tmp)
	{
		if ((ft_countwords(tmp->content, ' ')) <= 0
		|| line_is_valid(tmp->content) == 0)
			handle_error(5);
		tmp = tmp->next;
	}
}

int		check_data(t_data *fdf)
{
	t_list	*data;

	data = fdf->data;
	if (!fdf || !data)
		return (4);
	check_lines(fdf->data);
	fdf->height = ft_lstsize(fdf->data);
	fdf->width = ft_countwords(fdf->data->content, ' ');
	if (fdf->height == 0 || fdf->width == 0)
		return (handle_error(4));
	return (0);
}
