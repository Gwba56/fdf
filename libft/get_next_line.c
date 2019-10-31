/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarach- <gbarach-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 00:37:41 by tefourge          #+#    #+#             */
/*   Updated: 2019/07/31 22:53:30 by gbarach-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	get_read(char **str, int ret, int fd)
{
	char *tmp;
	char buf[BUFF_SIZE + 1];

	tmp = NULL;
	while ((!**str || !ft_strchr(*str, '\n')) \
			&& (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin(*str, buf)))
		{
			ft_strdel(str);
			return (-1);
		}
		if (*str)
			ft_strdel(str);
		*str = tmp;
	}
	return (ret);
}

int	search_char(char **str, char **line, int i)
{
	char *tmp;

	tmp = NULL;
	if ((*str)[i] == '\n')
	{
		if (!(*line = ft_strsub(*str, 0, i)))
			return (-1);
		if (!(tmp = ft_strdup(&((*str)[i + 1]))))
			return (-1);
		ft_strdel(str);
		*str = tmp;
		if (**str == '\0')
			ft_strdel(str);
	}
	else if ((*str)[i] == '\0')
	{
		if (!(*line = ft_strdup(*str)))
			return (-1);
		ft_strdel(str);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char		*str = NULL;
	int				i;
	int				ret;

	i = 0;
	ret = -42;
	if ((fd < 0 || line == NULL || BUFF_SIZE < 1) \
			|| (!str && !(str = ft_strnew(0))))
		return (-1);
	*line = NULL;
	ret = get_read(&str, ret, fd);
	if ((ret == 0 && (str == NULL || *str == '\0')) || ret == -1)
	{
		if (str && *str == '\0')
			ft_strdel(&str);
		return (ret);
	}
	if (str[i])
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		return (search_char(&str, line, i));
	}
	return (1);
}
