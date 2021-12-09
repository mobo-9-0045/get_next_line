/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:11:25 by aomman            #+#    #+#             */
/*   Updated: 2021/12/09 19:09:37 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<unistd.h>
# include<stdlib.h>
# include<fcntl.h>
# include<string.h>

char	*get_next_line(int fd);
char	*ft_strdup(const char *str);
int		ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);

#endif
