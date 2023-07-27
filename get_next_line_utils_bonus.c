/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:28:04 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/07/20 11:46:47 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_newstr(t_line *s, t_buffer *buf, long new_size, long end)
{
	char	*tmp_line;
	long	i;

	tmp_line = s->line;
	s->line = malloc(new_size);
	if (!s->line)
	{
		free(tmp_line);
		s->flag = 1;
		return ;
	}
	i = -1;
	while (++i < s->length)
		s->line[i] = tmp_line[i];
	free(tmp_line);
	while (buf->pointer < end)
		s->line[s->length++] = buf->line[buf->pointer++];
	s->line[s->length] = 0;
	if (buf->pointer == buf->length)
	{
		if (buf->length < BUFFER_SIZE)
			s->flag = 1;
		buf->pointer = 0;
		buf->length = 0;
	}
}

void	ft_addbuf(t_line *s, t_buffer *buf)
{
	long	end;

	end = buf->pointer;
	while (end < buf->length)
	{
		end++;
		if (buf->line[end - 1] == '\n')
		{
			s->flag = 1;
			break ;
		}
	}
	ft_newstr(s, buf, s->length + end - buf->pointer + 1, end);
}

void	ft_readstr(int fd, t_buffer *buf, t_line *s)
{
	if (buf->length)
	{
		ft_addbuf(s, buf);
		if (!s->line || s->flag)
			return ;
	}
	while (!s->flag)
	{
		buf->length = read(fd, buf, BUFFER_SIZE);
		if (buf->length < 0)
		{
			free(s->line);
			s->line = 0;
			buf->pointer = 0;
			buf->length = 0;
			return ;
		}
		if (!buf->length)
			break ;
		ft_addbuf(s, buf);
	}
}
