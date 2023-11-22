#include "get_next_line_bonus.h"
#include "get_next_line_bonus.c"
#include "get_next_line_utils_bonus.c"
#include <fcntl.h>

// int	main(void)
// {
// 	int fd;

// 	char *all = NULL;
// 	char *front = NULL;
// 	char *buffer = NULL;


// 	fd = open("./prueba.txt", O_RDONLY);

// 	while((buffer = get_next_line(fd)))
// 	{
// 		printf("%s\n", buffer);
// 		free_all(&buffer);
// 	}


// 	close(fd);

// 	// printf("Str buffer: %s\n", front);
// 	// printf("number buffer: %d\n\n", BUFFER_SIZE);
// 	// printf("number nb_char: %d\n", nb_char);
// 	// printf("number nb_bytes: %d", nb_bytes);
// 	printf("STR: %s\n", buffer);
// 	printf("ALL: %s\n", all);
// 	printf("FRONT: %s", front);

// 	free_all(&all);
// 	free_all(&front);
// 	free_all(&buffer);
// 	return (0);
// }

// #include <stdio.h>
// int main()
// {
//     char    *line;
//     int     fd;

// 	//fd = 0;
//     fd = open("prueba.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		close(fd);
// 		return (0);
// 	}
// 	line = "";
//     while (line != NULL)
//     {
//         line = get_next_line(fd);
// 		if (!line)
// 		{
// 			free (line);
// 			break;
// 		}
//         printf("%s", line);
// 		free(line);
//     }
// 	printf("%s", line);
// 	free(line);
// 	close(fd);
// 	//system("leaks -q a.out");
//     return (0);
// }

// #include <stdio.h>
// #include <time.h>
// int	main(void)
// {
//  	int fd;

//  	fd = open("prueba.txt", O_RDONLY);
//  	char *s;
// 	clock_t start = clock();
//  	while ((s = get_next_line(fd)))
//  	{
// 		//printf("===================================\n");
// 		//printf("RETURN ----> %s", s);
// 		//printf("===================================\n");
//  		free(s);
//  	}
// 	//printf("RETURN ----> %s", s);
// 	//printf("===================================\n");
// 	float seconds = (float)(clock() - start) / CLOCKS_PER_SEC;
// 	printf ("%.2f ds\n", seconds);
// 	// system("leaks a.out");
//  	return (0);
// }

// int main() {
//     int fd;
//     char *main_str = NULL;
//     char *print = NULL;

//     // Abre el archivo (reemplaza "file.txt" con tu nombre de archivo)
//     if ((fd = open("prueba.txt", O_RDONLY)) == -1) {
//         perror("Error al abrir el archivo");
//         return 1;
//     }

//     main_str = read_till_find(fd, main_str);
//     if (!main_str) {
//         printf("Error al leer el archivo\n");
//         close(fd);
//         return 1;
//     }

//     while (*main_str) {
//         relocate_line(&main_str, &print);
//         if (print) {
//             printf("%s\n", print); // Imprime la línea
//             free(print);
//         }
//     }

//     close(fd);
//     free_all(&main_str);

//     return 0;
// }

// int main(void)
// {
//     int     fd;
//     char    *str;
//     int     i;

//     i = 0;
//     fd = open("prueba.txt", O_RDONLY);
//     while ((i <= 6))
//     {
//         str = get_next_line(fd);
//         printf("line %i=>%s\n", i + 1, str);
//         free(str);
//         i++;
//     }
//     printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
//     return (0);
// }

// int main(void)
// {
//     int     fd;
//     char    *str;
//     int     i;

//     i = 0;
//     fd = open("lotr.txt", O_RDONLY);
//     //fd = 0;
//     str = get_next_line(fd);
//     while (str)
//     {
//         printf("line %i=>%s\n", i + 1, str);
//         free(str);
//         i++;
//         str = get_next_line(fd);
//     }
//     printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
//     system("leaks -q a.out");
//     return (0);
// }

#include <stdio.h>
int main()
{
    char    *line1;
	char	*line2;
    int     fd1;
	int		fd2;

    fd1 = open("prueba2.txt", O_RDONLY);
    fd2 = open("prueba2.txt", O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
	{
		close(fd1);
		close(fd2);
		return (0);
	}
	line1 = "";
	line2 = "";
    while (line1 != NULL || line2 != NULL)
    {
        line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		if (!line1 || !line2)
		{
			free (line1);
			free (line2);
			break;
		}
        printf("%s", line1);
        printf("%s", line2);
		free(line1);
		free(line2);
    }
	free(line1);
	free(line2);
	close(fd1);
	close(fd2);
	//system("leaks a.out");
    return (0);
}