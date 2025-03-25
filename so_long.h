/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahilal <nahilal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:35:31 by nahilal           #+#    #+#             */
/*   Updated: 2025/03/25 20:17:21 by nahilal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
#define SO_LONG_H 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"

size_t	ft_strlen(const char *s);
int	ft_strcmp(const char *s1, const char *s2);
char	*ft_strrchr(const char *s, int c);
void map_err(char **str,int len);
void flood_fill(char **str,int x, int y,int len);
#endif