/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarach- <gbarach-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:22:58 by gbarach-          #+#    #+#             */
/*   Updated: 2019/08/01 02:04:14 by gbarach-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

t_list	*extract_data(t_data *fdf)
{
	t_list	*data;
	char	*line;
	int		nb_coords;

	line = NULL;
	if (!get_next_line(fdf->fd, &line) || !line)
		return (NULL);
	nb_coords = ft_countwords(line, ' ');
	if (!(data = ft_lstnew(line, (ft_strlen(line) + 1))))
	{
		free(line);
		return (NULL);
	}
	free(line);
	while ((get_next_line(fdf->fd, &line)) > 0)
	{
		if (ft_countwords(line, ' ') != nb_coords)
			return (NULL);
		ft_lstadd(&data, ft_lstnew(line, (ft_strlen(line) + 1)));
		free(line);
	}
	ft_lstrev(&data);
	return (data);
}

int		check_file(int ac, char *av, t_data *fdf)
{
	if (ac != 2 || !ft_strstr(av, ".fdf"))
		return (1);
	if ((fdf->fd = open(av, O_RDONLY)) < 0)
		return (2);
	if (!(fdf->data = extract_data(fdf)))
		return (3);
	if ((fdf->check = check_data(fdf)) > 0)
		return (fdf->check);
	if (close(fdf->fd) == -1)
		return (handle_error(4));
	return (0);
}
