/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarach- <gbarach-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 10:56:30 by gbarach-          #+#    #+#             */
/*   Updated: 2019/08/06 16:57:10 by gbarach-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "stdlib.h"

int	handle_error(int i)
{
	if (i == 1)
		ft_putendl_fd("Usage: ./fdf <file name.fdf>", 2);
	if (i == 2)
		ft_putendl_fd("Cannot open file", 2);
	if (i == 3)
		ft_putendl_fd("Not a map", 2);
	if (i == 4)
		ft_putendl_fd("Cannot close file", 2);
	if (i == 5)
		ft_putendl_fd("Wrong format", 2);
	if (i == 6)
		ft_putendl_fd("Coordinates are too high", 2);
	exit(EXIT_FAILURE);
}
