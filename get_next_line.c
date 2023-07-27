/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:42:08 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/07/20 11:38:32 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readstr(int fd, t_buffer *buf, t_line *s);

/*****************************************************************************
Function name:	get_next_line
Description:	Returns a line read from a file descriptor
Parameters:		fd:	The file descriptor.
Return value:	The pointer to the line read from a file descriptor.
******************************************************************************/
char	*get_next_line(int fd)
{
	t_line			s;
	static t_buffer	buf;

	s.line = 0;
	s.flag = 0;
	s.length = 0;
	if (fd < 0)
		return (NULL);
	ft_readstr(fd, &buf, &s);
	return (s.line);
}
