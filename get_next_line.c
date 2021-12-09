/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:43:15 by aomman            #+#    #+#             */
/*   Updated: 2021/12/09 21:13:47 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"

int	ft_newline(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
		if (str[i] == '\n')
			break ;
	}
	if (str[i] == '\0')
		return (-1);
	return (i);
}

static char	*ft_free(char **buff, char **saved)
{
	free(*buff);
	*buff = NULL;
	if (saved && *saved)
	{
		free(*saved);
		*saved = NULL;
	}
	return (NULL);
}

static void	ft_store_save(char **saved, char **line, char **buff)
{
	int		new_line;
	char	*tmp;

	ft_free(buff, NULL);
	new_line = ft_newline(*saved);
	if (new_line < 0)
	{
		*line = ft_strdup(*saved);
		ft_free(saved, NULL);
	}
	else
	{
		tmp = *saved;
		*line = ft_substr(*saved, 0, new_line + 1);
		*saved = ft_substr(*saved, new_line + 1, ft_strlen(*saved));
		free(tmp);
		tmp = NULL;
	}
}

char	*get_next_line(int fd)
{
	int			ret;
	char		*line;
	static char	*saved;
	char		*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if ((fd < 0) && (BUFFER_SIZE <= 0))
		return (NULL);
	if (!saved)
		saved = ft_strdup("\0");
	ret = 1;
	while (ret > 0 && ft_newline(saved) < 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret < 0)
			return (ft_free(&buff, &saved));
		buff[ret] = '\0';
		saved = ft_strjoin(saved, buff);
	}
	ft_store_save(&saved, &line, &buff);
	if (ft_strlen(line) == 0)
		return (ft_free(&line, NULL));
	return (line);
}
