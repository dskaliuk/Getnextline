/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 10:12:25 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/07/20 11:42:56 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE_DEFAULT 42
# define OPEN_FILES_MAX 256

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFFER_SIZE_DEFAULT
# endif
# if (BUFFER_SIZE <= 0)
#  undef BUFFER_SIZE
#  define BUFFER_SIZE BUFFER_SIZE_DEFAULT
# endif

typedef struct s_line
{
	char	*line;
	long	length;
	int		flag;
}	t_line;

typedef struct s_buffer
{
	char	line[BUFFER_SIZE];
	long	pointer;
	long	length;
}	t_buffer;

char	*get_next_line(int fd);

#endif