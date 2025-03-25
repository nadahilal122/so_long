/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahilal <nahilal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:35:09 by nahilal           #+#    #+#             */
/*   Updated: 2025/03/25 20:19:00 by nahilal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_str(char **str,int i)
{
	int j;

	j = 0;
	while(j <= i)
		free(str[j]);
	free(str);
    exit(1);
}
void printf_err(char **str,int len)
{
	write(2, "Error\n", 6);
	write(2, "you display less/more than 2 argument !!\n", 41);
	free_str(str,len);
	exit(1);
}

void map_err(char **str,int len)
{
	write(2, "Error\n", 6);
	write(2, "your map does not correct !!\n", 29);
	free_str(str,len);
	exit(1);
}

void map_len_err(char **str,int len)
{
	write(2, "Error\n", 6);
	write(2, "your map lines does not correct !!\n", 35);
	free_str(str,len);
	exit(1);
}
int valide_name(char *str)
{
	char *s1 ;
	
	s1 = ft_strrchr(str,'.');
	if(!s1 || ft_strlen(s1) != ft_strlen(".ber"))
		return(0);
	if(ft_strcmp(s1,".ber") != 0)
		return(0);
	return(1);
}

int check_path(char *str)
{
	int fd;

	if(valide_name(str) == 0)
	{
		write(2, "Error\n : incorrect map name\n", 27);
		exit(1);
	}
	fd = open(str,O_RDONLY);
	if(fd == -1)
	{
		write(2, "Error\n : invalid map\n", 21);
		exit(1);
	}
	return(fd);
}

void check_first_last_map(char **str,int len)
{
	int i;
	int line_len;

	line_len = ft_strlen(str[len]) - 1;
	i = 0;
	while(i <= line_len)
	{
		if(str[len][i] == '1')
			i++;
		else if(str[len][i] == '\n')
			break;
		else
			map_err(str,len);
	}
}
void check_left(char **str, int total_line)
{
	int i;

	i = 0;
	while(i <= total_line)
	{
		if(str[i][0] == '1')
			i++;
		else
			map_err(str,total_line);
	}
}
void check_right(char **str, int total_line)
{
	int i;
	int j;

	i = 0;
	j =ft_strlen(str[0]) - 2;
	while(i <= total_line)
	{
		if(str[i][j] == '1')
			i++;
		else
			map_err(str,total_line);
	}

}
void check_len(char **str, int total_line)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str[0]);
	while(i < total_line)
	{
		if(len == ft_strlen(str[i]))
			i++;
		else
			map_len_err(str,total_line);
	}
}
void check_player_Exit(char **str, int total_line)
{
	int i;
	int j;
	int count_P;
	int count_C;
	int count_0;
	int count_E;
	int x;
	int y;

	count_P = 0;
	count_C = 0;
	count_0 =0;
	count_E=0;
	i = 0;
	j = 0;
	while(j <= total_line)
	{
		i = 0;
		while(str[j][i])
		{
			if(str[j][i] == '0' || str[j][i] == '1' || str[j][i] == '\n')
				count_0++;
			else if(str[j][i] == 'P')
			{
				count_P++;
				flood_fill(str, i, j,total_line);
			}
			else if(str[j][i] == 'E')
			{	count_E++;
				flood_fill(str, i, j,total_line);}
			else if(str[j][i] == 'C')
			{	count_C++;
				flood_fill(str, i, j,total_line);}
			else
				map_err(str,total_line);
			i++;
		}
		j++;
	}
	if(count_P != 1 || count_E != 1 || count_C < 1 || count_0 == 0)
		map_err(str,total_line);
	printf("ok");
}
void check_map(char **str, int total_line)
{
	check_len(str,total_line);
	check_first_last_map(str,0);
	check_first_last_map(str,total_line);
	check_left(str,total_line);
	check_right(str,total_line);
	check_player_Exit(str,total_line);	
}



int main(int ac, char **av)
{
	int i;
	int fd;
	char **str;
	
	i = 0;
	if(ac == 2)
	{
		str = (char **)malloc(sizeof(char *) * (1024 + 1));
        if (!str)
            exit(1);
		fd = check_path(av[1]);
		while((str[i] = get_next_line(fd)) != NULL)
		{
			if(i >= 1024)
			{
				free_str(str,i);
				map_err(str,i);
			}
			i++;	
		}	
		check_map(str,(i - 1));
	}
	else
		printf_err(str,i);
	free_str(str,i);
	return(0);
}