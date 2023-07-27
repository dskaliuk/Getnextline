/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:40:54 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/07/20 11:41:29 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE_DEFAULT 42

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFFER_SIZE_DEFAULT
# endif
# if (BUFFER_SIZE <= 0)
#  undef BUFFER_SIZE
#  define BUFFER_SIZE BUFFER_SIZE_DEFAULT
# endif

/*****************************************************************************
Type name:		t_line
Description:	The structure contains the working data of the returned
				string, such as the address of the string, its length,
				and a flag that signals that the string is terminated.
Parameters:		line:	The returned string addres.
				length:	The length of the string.
				flag:	It's a flag: 0 - the string is not terminated;
									 1 - signals that the string is terminated
									(when an end-of-line character is found
									or end-of-file is reached)
******************************************************************************/
typedef struct s_line
{
	char	*line;
	long	length;
	int		flag;
}	t_line;

/*****************************************************************************
Type name:		t_buffer
Description:	The structure contains the data of the buffer string,
				such as the address of the buffer string, its length,
				and the pointer of the buffer string that has not yet
				been processed.
Parameters:		line:		The buffer string addres.
				pointer:	The pointer of the buffer string that has not yet
							been processed.
				length:		The length of the buffer string.
******************************************************************************/
typedef struct s_buffer
{
	char	line[BUFFER_SIZE];
	long	pointer;
	long	length;
}	t_buffer;

char	*get_next_line(int fd);

#endif