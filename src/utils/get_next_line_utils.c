/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:04:48 by socana-b          #+#    #+#             */
/*   Updated: 2021/12/10 18:04:50 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2, int apt)
{
	char	*aux;
	int		i;
	int		j;

	if (!s1 || !s2)
		return ("");
	j = 0;
	i = 0;
	aux = malloc (sizeof(char) * (ft_strlen(s1) + apt + 1));
	if (aux == NULL)
		return (NULL);
	while (s1[i])
	{
		aux[i] = s1[i];
		i++;
	}
	while (j < apt)
	{
		aux[i] = s2[j];
		j++;
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

int	contains(char *str, char c, int flag)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!flag)
	{
		while (str[i] != '\0')
		{
			if (str[i] == c)
				j++;
			i++;
		}
		return (j);
	}
	else
	{
		while ((str[i] != c) && (str[i] != '\0'))
			i++;
		return (i);
	}
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*aux;

	i = 0;
	aux = malloc (sizeof(char) * ((int)(ft_strlen(s1) + 1)));
	if (!aux)
		return (NULL);
	while (s1[i])
	{
		aux[i] = s1[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
