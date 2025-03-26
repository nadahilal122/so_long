/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahilal <nahilal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:43:52 by nahilal           #+#    #+#             */
/*   Updated: 2025/03/26 20:32:50 by nahilal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	valide_name(char *str)
{
	char	*s1 ;

	s1 = ft_strrchr(str, '.');
	if (!s1 || ft_strlen(s1) != ft_strlen(".ber"))
		return (0);
	if (ft_strcmp(s1, ".ber") != 0)
		return (0);
	return (1);
}

void	check_len(char **str, int total_line)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(str[0]);
	while (i < total_line)
	{
		if (len == ft_strlen(str[i]))
			i++;
		else
			map_len_err(str, total_line);
	}
}

void	check_right(char **str, int total_line)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(str[0]) - 2;
	while (i <= total_line)
	{
		if (str[i][j] == '1')
			i++;
		else
			map_err(str, total_line);
	}
}

void	check_first_last_map(char **str, int len)
{
	int	i;
	int	line_len;

	line_len = ft_strlen(str[len]) - 1;
	i = 0;
	while (i <= line_len)
	{
		if (str[len][i] == '1')
			i++;
		else if (str[len][i] == '\n')
			break ;
		else
			map_err(str, len);
	}
}

void	check_left(char **str, int total_line)
{
	int	i;

	i = 0;
	while (i <= total_line)
	{
		if (str[i][0] == '1')
			i++;
		else
			map_err(str, total_line);
	}
}
