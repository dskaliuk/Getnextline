/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 10:13:30 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/07/20 11:44:50 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*****************************************************************************
Function name:	ft_newstr
Description:	Creates a new string, writes data from the original string,
				deallocates a block of memory previously allocated for
				the original string, concatenates data from the buffer
				string, if the string is terminated, in structure t_line
				sets flag value to 1.
Parameters:		s:			The pointer to original string structure.
				buf:		The pointer to buffer string structure.
				new_size:	The number of bytes of memory to allocate for
							the new line, given the the number of characters
							to be copied from the buffer string.
				end:		The end pointer of the data to be copied from
							the buffer string
Return value:	None. The data is changed directly in the structures
				of the original and buffer strings.
******************************************************************************/
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

/*****************************************************************************
Function name:	ft_addbuf
Description:	Adds to the original string characters from the buffer string.
Parameters:		s:		The pointer to original string structure.
				buf:	The pointer to buffer string structure.
Return value:	None. The data is changed directly in the structures
				of the original and buffer strings.
******************************************************************************/
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

/*****************************************************************************
Function name:	ft_readstr
Description:	Reads string from the file.
Parameters:		fd:		The file descriptor.
				s:		The pointer to original string structure.
				buf:	The pointer to buffer string structure.
Return value:	None. The data is changed directly in the structures
				of the original and buffer strings.
******************************************************************************/
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
