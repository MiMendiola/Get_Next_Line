/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:59:38 by mmendiol          #+#    #+#             */
/*   Updated: 2023/10/26 19:26:10 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Introducir tdas las funcoines aqui
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

char *get_next_line(int fd);

#endif