/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:33:16 by rtodaro           #+#    #+#             */
/*   Updated: 2024/12/23 15:36:04 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef FT_FD_MAX
#  define FT_FD_MAX 1024
# endif

# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		check_newline(char *str);
char	*extract_line(char *str);
char	*gnl_fix_buffer(char *str);
char	*gnl_ft_strdup(char *s);
size_t	gnl_ft_strlen(char *str);
size_t	gnl_ft_strncpy(char *dest, char *src, size_t n);
char	*create_buffer(int fd, char *buffer);
char	*get_next_line(int fd);
void	*gnl_ft_calloc(size_t nmemb, size_t size);
void	*null_free(void **ptr, void **ptr2, int flag1, int flag2);

#endif
