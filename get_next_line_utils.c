/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_otils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:02:59 by aomman            #+#    #+#             */
/*   Updated: 2021/12/08 19:25:11 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"

char	*ft_strdup(const char *str)
{
	char	*s;
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	s = malloc(i + 1);
	if (!s)
		return (NULL);
	s[i] = '\0';
	while (i >= 0)
	{
		s[i] = str[i];
		i--;
	}
	return (s);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*string;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		string = malloc(sizeof(char));
	else if (len > ft_strlen(s))
		string = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		string = malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	while (s[i] && i < len && i + start < ft_strlen(s))
	{
		string[i] = s[start + i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		s1_s;
	int		s2_s;
	int		str_s;

	s1_s = ft_strlen(s1);
	s2_s = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_s + s2_s + 1));
	str_s = 0;
	while (str_s < s1_s)
	{
		str[str_s] = s1[str_s];
		str_s++;
	}
	str_s = 0;
	while (str_s < s2_s)
		str[s1_s++] = s2[str_s++];
	str[s1_s] = '\0';
	free(s1);
	return (str);
}
