/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarach- <gbarach-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:37:45 by gbarach-          #+#    #+#             */
/*   Updated: 2019/05/11 13:39:29 by gbarach-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_matrix_create(int rows, int cols)
{
	int		i;
	int		**matrix;

	i = 0;
	if (!(matrix = (int **)ft_calloc(sizeof(int *) * rows, 0)))
		return (0);
	while (i < rows)
	{
		if (!(matrix[i] = (int *)ft_calloc(sizeof(int) * cols, 0)))
			return (0);
		i += 1;
	}
	return (matrix);
}
