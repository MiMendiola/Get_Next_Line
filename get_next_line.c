/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:59:28 by mmendiol          #+#    #+#             */
/*   Updated: 2023/10/27 17:29:23 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *free_all(char **to_free)
{
    free(*to_free);
    *to_free = NULL;
    return (NULL);
}

void    relocate_info()
{
    
}

// This function is going to tell you if in our static have an \n or not
char *read_till_find()
{
    
    
}

// This function is going to return you the front part to write it down



char *get_next_line(int fd)
{
    static  char    *main_str;
    int             i;
    int             nb_bytes;
	int             nb_char;
    char            *front;
    char            buffer[BUFFER_SIZE];

    i = 0;
    nb_char = 0;
    nb_bytes = 0;
    if (fd == -1 || BUFFER_SIZE <= 0)
        return (NULL);
    while (nb_bytes != 0 || nb_char < BUFFER_SIZE)
    {
        nb_char += nb_bytes;
        nb_bytes = read(fd, buffer, BUFFER_SIZE);
    }
    
}
