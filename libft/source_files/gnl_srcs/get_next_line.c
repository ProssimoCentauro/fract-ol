/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:47:17 by rtodaro           #+#    #+#             */
/*   Updated: 2024/12/23 15:04:47 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*null_free(void **ptr, void **ptr2, int flag1, int flag2)
{
	if (flag1 == 10 && *ptr2)
		*ptr = gnl_ft_strdup((char *)*ptr2);
	if ((flag1 == 1 || flag1 == 3))
	{
		if (*ptr)
			free(*ptr);
		if (flag1 == 3)
			*ptr = NULL;
	}
	else if (flag1 == 2)
		*ptr = NULL;
	if ((flag2 == 1 || flag2 == 3))
	{
		if (*ptr2)
			free(*ptr2);
		if (flag2 == 3)
			*ptr2 = NULL;
	}
	else if (flag2 == 2)
		*ptr2 = NULL;
	return (NULL);
}

char	*extract_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		line = (char *)malloc(i + 2);
		i += 1;
	}
	else if (str[i] == '\0')
		line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	line[i--] = '\0';
	while (i >= 0)
	{
		line[i] = str[i];
		i--;
	}
	return (line);
}

char	*fix_buffer(char *str)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*new;

	if (!str || !str[0])
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		i++;
	k = i;
	while (str[i])
		i++;
	new = (char *)gnl_ft_calloc(i - k + 1, 1);
	if (!new)
		return (NULL);
	k++;
	while (str[k])
		new[j++] = str[k++];
	new[j] = '\0';
	free(str);
	if (!new[0])
		return (null_free((void *)&new, (void *)&str, 1, 2));
	return (new);
}

char	*create_buffer(int fd, char *buffer)
{
	char	*tmp;
	ssize_t	readed_bytes;

	tmp = NULL;
	while (!check_newline(buffer))
	{
		if (buffer)
		{
			null_free((void *)&tmp, (void *)&buffer, 10, 1);
			if (!tmp)
				return (NULL);
		}
		buffer = (char *)gnl_ft_calloc(gnl_ft_strlen(tmp) + BUFFER_SIZE + 1, 1);
		if (!buffer)
			return (null_free((void *)&tmp, NULL, 1, 0));
		readed_bytes = read(fd, &buffer[gnl_ft_strncpy(buffer, tmp,
					gnl_ft_strlen(tmp))], BUFFER_SIZE);
		if (readed_bytes == 0)
		{
			free(buffer);
			return (tmp);
		}
		free(tmp);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (check_newline(buffer))
	{
		line = extract_line(buffer);
		buffer = fix_buffer(buffer);
		if (!buffer)
			buffer = create_buffer(fd, buffer);
		return (line);
	}
	buffer = create_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = fix_buffer(buffer);
	return (line);
}
