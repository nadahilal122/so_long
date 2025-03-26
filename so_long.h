/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahilal <nahilal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:35:31 by nahilal           #+#    #+#             */
/*   Updated: 2025/03/25 23:18:20 by nahilal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H 

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"

typedef struct s_check
{
	int	i;
	int	j;
	int	count_p;
	int	count_c;
	int	count_0;
	int	count_e;
}	t_check;

size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strrchr(const char *s, int c);
void	map_err(char **str, int len);
void	fill(char **str, int x, int y, int len);
void	free_str(char **str, int i);
void	printf_err(char **str, int len);
void	map_err(char **str, int len);
void	map_len_err(char **str, int len);
void	check_map(char **str, int total_line);
void	check_len(char **str, int total_line);
void	check_right(char **str, int total_line);
void	check_first_last_map(char **str, int len);
void	check_left(char **str, int total_line);
void	check_player_exit(char **str, int total_line);
void	check_max_fd(int fd, char **str, int i);
#endif