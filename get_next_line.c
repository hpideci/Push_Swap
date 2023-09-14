/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpideci <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:36:04 by hpideci           #+#    #+#             */
/*   Updated: 2023/08/29 11:59:15 by hpideci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sstrchr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static inline char	*ft_sstrjoin(char *s1, char *s2, int i, int j)
{
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	i = -1;
	j = 0;
	if (!str)
		return (NULL);
	while (++i, s1[i])
		str[i] = s1[i];
	while (s2[j++] != '\0')
		str[i - 1 + j] = s2[j - 1];
	str[i + j - 1] = '\0';
	free(s1);
	return (str);
}

static inline char	*ft_new_create_buffer(char *buffer, int i, int j)
{
	char	*res;
	int		len;

	len = 0;
	while (buffer[len])
		len++;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	res = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!res)
		return (NULL);
	i++;
	while (buffer[i])
		res[j++] = buffer[i++];
	res[j] = '\0';
	free(buffer);
	return (res);
}

static inline char	
	*ft_create_buffer(char *buffer, int buff_size, int fd, int *i)
{
	char	*temp;

	*i = 0;
	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	while ((buff_size != 0 && !ft_sstrchr(buffer)))
	{
		buff_size = read(fd, temp, BUFFER_SIZE);
		if (buff_size == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[buff_size] = '\0';
		buffer = ft_sstrjoin(buffer, temp, 0, 0);
	}
	free(temp);
	if (buffer[0] == 0)
	{
		free (buffer);
		return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_create_buffer(buffer, 1, fd, &i);
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = -1;
	while (buffer[++i] && buffer[i] != '\n')
		line[i] = buffer[i];
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	buffer = ft_new_create_buffer(buffer, 0, 0);
	return (line);
}
