/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:23:13 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/17 12:36:35 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	give_line(int fd, char **line, char **stack, int ret)
{
	int		len;
	char	*tmp;

	if (ret == 0 && stack[fd] == NULL)
		return (0);
	len = 0;
	while (stack[fd][len] != '\n' && stack[fd][len] != '\0')
		len++;
	if (stack[fd][len] == '\n')
	{
		*line = ft_strsub(stack[fd], 0, len);
		tmp = stack[fd];
		stack[fd] = ft_strdup(&stack[fd][len + 1]);
		free(tmp);
		if (stack[fd][0] == '\0')
			ft_strdel(&stack[fd]);
	}
	else
	{
		*line = ft_strdup(stack[fd]);
		ft_strdel(&stack[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char *stack[MAX_FD + 1];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	ssize_t		ret;

	if (fd < 0 || fd > MAX_FD || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (stack[fd] == NULL)
			stack[fd] = ft_strdup(buf);
		else
		{
			tmp = stack[fd];
			stack[fd] = ft_strjoin(stack[fd], buf);
			ft_strdel(&tmp);
		}
		if (ft_strchr(stack[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else
		return (give_line(fd, line, stack, ret));
}
