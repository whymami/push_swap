/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:46:47 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/27 16:01:12 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

size_t	ft_strlens(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoins(char *s1, char *s2);
char	*get_next_line(int fd);
char	*readline(int fd, char	*readone);
char	*putline(char *readone);
char	*nxtline(char *readone);

#endif