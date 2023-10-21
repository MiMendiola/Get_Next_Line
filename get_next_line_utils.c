#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


// Este strchr modificado nos comprueba que la string que nos pasan primero exista y que no halla errores y despues te devolvera o null o si encuentra el caracter \n / \0 nos mandara la longuitud hasta dicho caracter.
int ft_strchr(const char *s, int c)
{
	int			i;
	unsigned char	character;

	i = 0;
	character = (unsigned char)c;
    if (!s)
        return (0);
	while (s[i])
	{
		if (s[i++] == character)
			return (i);
	}
	return (0);
}


// int main() {
//     const char *str = "Hello, world!";
//     char character_to_find = 'o';

//     int length = ft_strlen(str);
//     int result = ft_strchr(str, character_to_find);

//     printf("La longitud de la cadena es: %d\n", length);
//     printf("El carácter '%c' se encontró en la posición: %d\n", character_to_find, result);
//     return 0;
// }


// 
// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*dst;
// 	size_t	lens1;
// 	size_t	lens2;
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	lens1 = ft_strlen(s1);
// 	lens2 = ft_strlen(s2);
// 	if (!s1 && !s2)
// 		return (NULL);
// 	dst = malloc((lens1 + lens2 + 1) * sizeof(char));
// 	if (!dst)
// 		return (NULL);
// 	while (s1[i++])
// 		ft_memcpy(dst, s1, lens1);
// 	while (s2[j++])
// 		ft_memcpy(lens1 + dst, s2, lens2);
// 	return (dst);
// }


// Puedo copiar la parte final a la string destino que sera nuestra string statica
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
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
	return (len);
}

int main() {
	int		fd;
	char	*str = "./prueba.txt";
	int		nb_bytes;
	int		nb_char = 0;
	char	*buffer;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	buffer = (char *)malloc(sizeof(char) * 10);
	nb_bytes = read(fd, buffer, sizeof(buffer));
	while (nb_char < 10)
	{
		nb_char += nb_bytes;
		nb_bytes = read(fd, buffer, sizeof(nb_char));
	}
	close(fd);

	printf("%s\n", buffer);
	printf("%d\n", nb_char);
	printf("%d", nb_bytes);


	free(buffer);
	return (nb_char);
    return 0;
}