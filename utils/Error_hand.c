/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error_hand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahilal <nahilal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:41:38 by nahilal           #+#    #+#             */
/*   Updated: 2025/03/26 20:26:57 by nahilal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_str(char **str, int i)
{
	int	j;

	j = 0;
	while (j <= i)
		free(str[j++]);
	free(str);
	exit(1);
}

void	check_max_fd(int fd, char **str, int i)
{
	if (i >= 1024)
	{
		close(fd);
		free_str(str, i);
		map_err(str, i);
	}
}

void	printf_err(void)
{
	write(2, "Error\n", 6);
	write(2, "you display less/more than 2 argument !!\n", 41);
	exit(1);
}

void	map_err(char **str, int len)
{
	write(2, "Error\n", 6);
	write(2, "your map does not correct !!\n", 29);
	free_str(str, len);
	exit(1);
}

void	map_len_err(char **str, int len)
{
	write(2, "Error\n", 6);
	write(2, "your map lines does not correct !!\n", 35);
	free_str(str, len);
	exit(1);
}
