/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahilal <nahilal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 04:34:16 by nahilal           #+#    #+#             */
/*   Updated: 2025/03/25 20:09:26 by nahilal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill(char **str, int x, int y, int len)
{
	if (y < len && str[y][x - 1] == '1' && str[y][x + 1] == '1'
		&& str[y + 1][x] == '1' && str[y - 1][x] == '1' )
	{
		write(2, "Error\n", 6);
		write(2, "in your map ,", 13);
		write(2, &str[y][x], 1);
		write(2, " surrended by the wall", 22);
		exit(1);
	}
}
