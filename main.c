#include "get_next_line.h"
#include "get_next_line.c"
#include "get_next_line_utils.c"

int	main(void)
{
	int fd;

	char *all = NULL;
	char *front = NULL;
	char buffer[BUFFER_SIZE];


	fd = open("./prueba.txt", O_RDONLY);
	if (fd == -1)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}

	all = read_till_find(fd, buffer);
    write(fd, all, ft_strlen(all - 1));
    printf("Print 1 all:  %s\n", all);
    relocate_line(&all, &front);
    printf("Print 2 all: %s\n", all);
    printf("Main front: %s\n", front);

	close(fd);

	// printf("Str buffer: %s\n", front);
	// printf("number buffer: %d\n\n", BUFFER_SIZE);
	// printf("number nb_char: %d\n", nb_char);
	// printf("number nb_bytes: %d", nb_bytes);

	free_all(&all);
	free_all(&front);
	return (0);
}