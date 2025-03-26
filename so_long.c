/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahilal <nahilal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:35:09 by nahilal           #+#    #+#             */
/*   Updated: 2025/03/25 23:15:30 by nahilal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
int	parsing(char **str,char **av)
{
	int	i;
	int	fd;

	i = 0;
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
	close(fd);
	return (i);
}
int	main(int ac, char **av)
{
	int		i;
	char	**str;

	if (ac == 2)
	{
		i = parsing(str,av);
	}
	else
		printf_err(str, (i - 1));
	printf("i======>%d\n\n",i);
	free_str(str,i);
	return (0);
}
