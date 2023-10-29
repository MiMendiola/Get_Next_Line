/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:59:28 by mmendiol          #+#    #+#             */
/*   Updated: 2023/10/29 22:13:45 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    free_all(char **to_free)
{
    if (*to_free == NULL)
        return ;
    free(*to_free);
    *to_free = NULL;
}

void    relocate_line(char **str_static, char **front)
{
    int     i;
    int     j;
    char    *back;
    
    i = 0;
    j = -1;
    if (!*str_static)
        return ;
    while (*str_static && (*str_static)[i] != '\n')
        i++;
    *front = malloc((i + 2) * sizeof(char));
    if (!*front)
        return ;
    *front = ft_substr(*str_static, 0, (i + 1));
    back = *str_static;
    while ((*str_static)[i] == '\n')
        i++;
    *str_static = ft_substr(*str_static, i, (ft_strlen(*str_static) - i));
    free(back);
}

// Is going to read till we have a \n in our static
char    *read_till_find(int fd, char *str_static)
{
    int     nb_bytes;
    char    *new_read;

    new_read = malloc((BUFFER_SIZE) * sizeof(char));
    if (!new_read)
        return (NULL);
    while (!ft_strchr(str_static, '\n') || nb_bytes < BUFFER_SIZE)
    {
        nb_bytes = read(fd, new_read, BUFFER_SIZE);
        if (nb_bytes < 0)
        {
            free_all(&new_read);
            return (NULL);
        }
        new_read[nb_bytes] = '\0';
        str_static = ft_strjoin(str_static, new_read);
    }
    // chequear mañana
    // free_all(&new_read);
    return (str_static);
}

// This function is going to return you the front part to write it down
char *get_next_line(int fd)
{
    static char     *main_str;
    // char            *print;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        free_all(&main_str);
    
    
    return (NULL);
}
