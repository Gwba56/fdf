/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarach- <gbarach-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 11:39:25 by gbarach-          #+#    #+#             */
/*   Updated: 2019/07/13 11:52:50 by gbarach-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ishexa(int c)
{
	if (ft_isdigit(c) == 1 || (c >= 'A' && c <= 'F')
	|| (c >= 'a' && c <= 'f'))
		return (1);
	return (0);
}
