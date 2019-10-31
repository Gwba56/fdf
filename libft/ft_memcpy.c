/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarach- <gbarach-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:36:41 by gbarach-          #+#    #+#             */
/*   Updated: 2018/12/12 14:58:40 by gbarach-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *zdest;
	char *zsrc;

	zdest = (char*)dest;
	zsrc = (char*)src;
	while (n--)
		*zdest++ = *zsrc++;
	return (dest);
}
