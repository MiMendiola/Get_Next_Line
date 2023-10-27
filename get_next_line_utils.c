/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:59:34 by mmendiol          #+#    #+#             */
/*   Updated: 2023/10/27 17:10:10 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
	unsigned char	character;

	i = 0;
	character = (unsigned char)c;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i++] == character)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
 	size_t	lens1;
 	size_t	lens2;
 	size_t	i;
 	size_t	j;

 	i = 0;
 	j = 0;
 	lens1 = ft_strlen(s1);
 	lens2 = ft_strlen(s2);
 	if (!s1)
 		return (ft_strdup(s2));
 	dst = malloc((lens1 + lens2) * sizeof(char));
 	if (!dst)
 		return (NULL);
 	while (s1 && s1[i++])
 		dst[i] = s1[i];
 	while (s2 && s2[j++])
 		dst[i] = s2[j];
 	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
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

int	main(void)
{
	int fd;
	char *str = "./prueba.txt";
	int nb_bytes = 0;
	int nb_char = 0;
	char *tmp_all = NULL;
	char *all = NULL;
	char *front = NULL;
	char buffer[BUFFER_SIZE];
	int	i = 0;
	//int	j = 0;
	size_t len;


	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	printf("number buffer: %lu\n", sizeof(buffer));
	while (nb_bytes != 0 || nb_char < BUFFER_SIZE)
	{
		nb_char += nb_bytes;
		nb_bytes = read(fd, buffer, BUFFER_SIZE);
		tmp_all = all;
		all = ft_strjoin(all, buffer);
		all[BUFFER_SIZE] = '\0';

		// comprobar aqui si en all tengo el \n y ver 
		while (all && ft_strchr(all, '\n'))
		{
			if (all[i] == '\n')
			{
				len = ft_strlen(all) - i + 1;
				front = ft_substr(all, 0, i + 1);
				all = ft_substr(all, i + 1 , len);
				// return(0);
			}
			else
			{
				printf("%c\n", all[i]);
				i++;
			}
		}
		
	}
	close(fd);

	printf("Str buffer: %s\n", front);
	printf("number buffer: %d\n\n", BUFFER_SIZE);
	printf("number nb_char: %d\n", nb_char);
	printf("number nb_bytes: %d", nb_bytes);

	free(buffer);
	return (nb_char);
	return (0);
}