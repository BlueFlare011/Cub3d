/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:05:19 by socana-b          #+#    #+#             */
/*   Updated: 2023/08/20 17:28:11 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# define MAX_FD 65535

char	*get_next_line(int fd);
char	*ft_strjoin2(char const *s1, char const *s2, int apt);
int		contains(char *str, char c, int flag);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
void	*ft_memmove(void *dst, const void *src, size_t len);

#endif
