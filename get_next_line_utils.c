/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:59:34 by mmendiol          #+#    #+#             */
/*   Updated: 2023/10/29 22:13:54 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

// Este strchr modificado nos comprueba que la string que nos pasan primero exista y que no halla errores y despues te devolvera o null o si encuentra el caracter \n/ \0 nos mandara la longuitud hasta dicho caracter.
int	ft_strchr(const char *s, int c)
{
	int				i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i++] == (char)c)
			return (1);
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *main, char *buffer)
{
 	int		i;
 	int		j;
	int		k;
	char	*dst;

 	i = 0;
 	j = 0;
	k = 0;
	if (!main || !buffer)
		return (NULL);
 	dst = malloc((ft_strlen(main) + ft_strlen(buffer) + 1) * sizeof(char));
 	if (!dst)
 		return (NULL);
 	while (main[j])
 		dst[i++] = main[j++];
 	while (buffer[k])
 		dst[i++] = buffer[k++];
	dst[i] = '\0';
	// Checar mañana
	// free(buffer);
 	return (dst);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	maxlen;
	char	*dst;

	i = 0;
	maxlen = ft_strlen(s);
	if (start >= maxlen)
		return (ft_strdup(""));
	if (len > maxlen - start)
		len = maxlen - start;
	dst = malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (len > i && start < maxlen)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}