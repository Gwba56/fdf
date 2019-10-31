/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarach- <gbarach-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 10:43:55 by gbarach-          #+#    #+#             */
/*   Updated: 2019/08/01 03:22:55 by gbarach-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	t_data	file;
	t_env	fdf;

	if ((file.check = check_file(ac, av[1], &file)) != 0)
		return (handle_error(file.check));
	if (!(fdf.map = convert_data(&file)))
		return (handle_error(3));
	init_env(&fdf);
	draw(&fdf);
	return (0);
}
