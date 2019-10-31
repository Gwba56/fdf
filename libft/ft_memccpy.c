/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarach- <gbarach-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:23:50 by gbarach-          #+#    #+#             */
/*   Updated: 2018/12/02 14:38:44 by gbarach-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	to_find;

	i = 0;
	to_find = (unsigned char)c;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
		if (((unsigned char *)dest)[i - 1] == to_find)
			return (&((unsigned char *)dest)[i]);
	}
	return (NULL);
}
