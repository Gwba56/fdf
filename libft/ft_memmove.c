/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarach- <gbarach-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:02:08 by gbarach-          #+#    #+#             */
/*   Updated: 2018/12/03 11:25:24 by gbarach-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*temp_src;
	unsigned char		*temp_dest;

	temp_src = src;
	temp_dest = dest;
	if (temp_dest == temp_src)
		return (dest);
	if (temp_dest > temp_src)
	{
		temp_dest += n - 1;
		temp_src += n - 1;
		while (n--)
			*temp_dest-- = *temp_src--;
	}
	else
		while (n--)
			*temp_dest++ = *temp_src++;
	return (dest);
}
