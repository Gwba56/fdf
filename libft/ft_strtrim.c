/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarach- <gbarach-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:52:32 by gbarach-          #+#    #+#             */
/*   Updated: 2018/12/12 14:59:44 by gbarach-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	end;

	start = 0;
	if (!s)
		return (NULL);
	if (!*s)
		return ((char*)s);
	end = (int)ft_strlen(s) - 1;
	while (ft_iswhitespace(s[start]) == 1)
		start++;
	if (end <= start)
		end = start;
	while (ft_iswhitespace(s[end]))
	{
		if (end <= start)
			return (NULL);
		end--;
	}
	return (ft_strsub(s, start, (end - start + 1)));
}
