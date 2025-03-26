/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahilal <nahilal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:35:09 by nahilal           #+#    #+#             */
/*   Updated: 2025/03/26 20:32:47 by nahilal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(char **str, int total_line)
{
	check_len(str, total_line);
	check_first_last_map(str, 0);
	check_first_last_map(str, total_line);
	check_left(str, total_line);
	check_right(str, total_line);
	check_player_exit(str, total_line);
}

int	check_path(char *str)
{
	int	fd;

	if (valide_name(str) == 0)
	{
		write(2, "Error\n : incorrect map name\n", 27);
		exit(1);
	}
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\n : invalid map\n", 21);
		exit(1);
	}
	return (fd);
}

void	check_line(t_check *data, char **str, int total_line)
{
	while (str[data->j][data->i])
	{
		if (str[data->j][data->i] == '0' || str[data->j][data->i] == '1'
			|| str[data->j][data->i] == '\n')
			data->count_0++;
		else if (str[data->j][data->i] == 'P')
		{
			data->count_p++;
			fill(str, data->i, data->j, total_line);
		}
		else if (str[data->j][data->i] == 'E')
		{
			data->count_e++;
			fill(str, data->i, data->j, total_line);
		}
		else if (str[data->j][data->i] == 'C')
		{
			data->count_c++;
			fill(str, data->i, data->j, total_line);
		}
		else
			map_err(str, total_line);
		data->i++;
	}
}

void	check_player_exit(char **str, int total_line)
{
	t_check	data;

	data.count_p = 0;
	data.count_c = 0;
	data.count_0 = 0;
	data.count_e = 0;
	data.i = 0;
	data.j = 0;
	while (data.j <= total_line)
	{
		data.i = 0;
		check_line(&data, str, total_line);
		data.j++;
	}
	if (data.count_p != 1 || data.count_e != 1
		|| data.count_c < 1 || data.count_0 == 0)
		map_err(str, total_line);
	printf("ok");
}

int	main(int ac, char **av)
{
	int		i;
	int		fd;
	char	**str;

	i = 0;
	fd = 0;
	str = NULL;
	if (ac == 2)
	{
		fd = check_path(av[1]);
		str = (char **)malloc(sizeof(char *) * (1024 + 1));
		if (!str)
			exit(1);
		str[i] = get_next_line(fd);
		while (str[i] != NULL)
		{
			check_max_fd(fd, str, i);
			i++;
			str[i] = get_next_line(fd);
		}
		check_map(str, (i - 1));
	}
	else
		printf_err();
	close(fd);
	free_str(str, i);
	return (0);
}
