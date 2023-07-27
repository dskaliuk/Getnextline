/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:42:08 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/07/18 17:37:25 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_readstr(int fd, t_buffer *buf, t_line *s);

char	*get_next_line(int fd)
{
	t_line			s;
	static t_buffer	buf[OPEN_FILES_MAX];

	s.line = 0;
	s.flag = 0;
	s.length = 0;
	if (fd < 0 || fd > OPEN_FILES_MAX)
		return (NULL);
	ft_readstr (fd, &buf[fd], &s);
	return (s.line);
}
