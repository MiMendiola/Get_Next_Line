/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:59:34 by mmendiol          #+#    #+#             */
/*   Updated: 2023/10/26 19:24:02 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
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

void	*ft_calloc(size_t count, size_t size)
{
	void			*str;
	unsigned char	*ptr;
	size_t			total_size;
	size_t			i;

	i = 0;
	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	str = malloc(count * size);
	if (!str)
		return (NULL);

	ptr = (unsigned char *)str;
	total_size = count * size;
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return (str);
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

// int main() {
//     const char *str = "Hello, world!";
//     char character_to_find = 'o';

//     int length = ft_strlen(str);
//     int result = ft_strchr(str, character_to_find);

//     printf("La longitud de la cadena es: %d\n", length);
//     printf("El carácter '%c' se encontró en la posición: %d\n",
//	   character_to_find, result);
//     return (0);
// }

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (src && len > i)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if ((d > s) && (s + len > d))
	{
		while (len--)
			d[len] = s[len];
	}
	else
		ft_memcpy(d, s, len);
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*dst;
	int		i;

	i = 0;
	dst = ft_calloc(ft_strlen(s) + 1, sizeof(char));
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
 	dst = ft_calloc((lens1 + lens2 + 1), sizeof(char));
 	if (!dst)
 		return (NULL);
 	while (s1 && s1[i++])
 		ft_memmove(dst, s1, lens1);
 	while (s2 && s2[j++])
 		ft_memmove(lens1 + dst, s2, lens2);
 	return (dst);
}

// Puedo copiar la parte final a la string destino que sera nuestra string statica
void	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
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
	dst = ft_calloc((len + 1), sizeof(char));
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
	char *back = NULL;
	char buffer[BUFFER_SIZE];
	int	i = 0;
	int	j = 0;
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

		// comprobar a qui si en all tengo el \n y ver 
		while (all || ft_strchr(all, '\n'))
		{
			if (all[i] == '\n')
			{
				len = ft_strlen(all) - i + 1;
				if (!front && ft_strchr(all, '\n'))
				{
					front = ft_substr(all, 0, i + 1);
					// devolver lo que tengo en front
					j = i;
				}
				else
				{
					front = ft_substr(back, 0, i - j);
					j = i;
				}
				back = ft_substr(all, i + 1 , len);

				i++;
			}
			else
			{
				printf("%c\n", all[i]);
				i++;
			}
		}
		
	}
	close(fd);

	printf("Str buffer: %s\n", buffer);
	printf("number buffer: %lu\n\n", sizeof(buffer));
	printf("number nb_char: %d\n", nb_char);
	printf("number nb_bytes: %d", nb_bytes);

	free(buffer);
	return (nb_char);
	return (0);
}