/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarach- <gbarach-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 18:29:42 by gbarach-          #+#    #+#             */
/*   Updated: 2019/07/11 14:27:46 by gbarach-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(const char *str, char c)
{
	int			count;
	int			i;
	const char	*tmp;

	i = 0;
	count = 0;
	tmp = str;
	while (tmp[i])
	{
		while (tmp[i] == c)
			i++;
		if (tmp[i] != c && tmp[i] != '\0')
			count++;
		while (tmp[i] != c && tmp[i] != '\0')
			i++;
	}
	return (count);
}
