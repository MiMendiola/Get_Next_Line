/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:59:38 by mmendiol          #+#    #+#             */
/*   Updated: 2023/11/18 18:14:45 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Introducir tdas las funcoines aqui
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// MAIN FUNCTIONS
void	free_all(char **to_free);
void	relocate_line(char **str_static, char **front);
char	*read_till_find(int fd, char *str_static);
char	*get_next_line(int fd);

// UTILS FUNCTIONS
int		ft_strlen(const char *str);
int		ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *main, char *buffer);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif