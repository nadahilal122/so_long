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

void	flood_fill(char **str, int x, int y)
{
	if(str[y][x] == '1' || str[y][x] == '+')
		return;
	str[y][x] = '+';
	flood_fill(str,x - 1,y);
	flood_fill(str,x + 1,y);
	flood_fill(str,x,y - 1);
	flood_fill(str,x,y + 1);
}
