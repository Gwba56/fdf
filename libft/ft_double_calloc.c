/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_calloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarach- <gbarach-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:47:56 by gbarach-          #+#    #+#             */
/*   Updated: 2019/07/31 19:19:54 by tefourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_double_calloc(int rows, int cols, size_t size)
{
	int				i;
	unsigned char	**ptr;

	i = 0;
	if (!(ptr = (unsigned char **)ft_calloc(sizeof(size) * rows, 0)))
		return (0);
	while (i < rows)
	{
		if (!(ptr[i] = (unsigned char *)ft_calloc(sizeof(size) * cols, 0)))
			return (0);
		i++;
	}
	return ((void **)ptr);
}
