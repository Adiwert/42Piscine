/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:39:03 by jthiew            #+#    #+#             */
/*   Updated: 2024/09/01 15:40:17 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int			*g_top_clues;
int			*g_bottom_clues;
int			*g_left_clues;
int			*g_right_clues;
int			ft_top_clues(char *str, int counter);
int			ft_bottom_clues(char *str, int counter);
int			ft_left_clues(char *str, int counter);
int			ft_right_clues(char *str, int counter);
int			ft_len(char *str);
extern int	g_set;

void	ft_ini_global_array(char *argv)
{
	int	counter;

	counter = 0;
	g_top_clues = (int *)malloc((g_set + 1) * sizeof(int));
	counter = ft_top_clues(argv, counter);
	g_bottom_clues = (int *)malloc((g_set + 1) * sizeof(int));
	counter = ft_bottom_clues(argv, counter);
	g_left_clues = (int *)malloc((g_set + 1) * sizeof(int));
	counter = ft_left_clues(argv, counter);
	g_right_clues = (int *)malloc((g_set + 1) * sizeof(int));
	counter = ft_right_clues(argv, counter);
}

int	ft_top_clues(char *str, int counter)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < g_set)
	{
		if (str[counter] >= '0' && str[counter] <= '9')
		{
			g_top_clues[j] = str[counter] - '0';
			j++;
		}
		counter++;
	}
	return (counter);
}

int	ft_bottom_clues(char *str, int counter)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < g_set)
	{
		if (str[counter] >= '0' && str[counter] <= '9')
		{
			g_bottom_clues[j] = str[counter] - '0';
			j++;
		}
		counter++;
	}
	return (counter);
}

int	ft_left_clues(char *str, int counter)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < g_set)
	{
		if (str[counter] >= '0' && str[counter] <= '9')
		{
			g_left_clues[j] = str[counter] - '0';
			j++;
		}
		counter++;
	}
	return (counter);
}

int	ft_right_clues(char *str, int counter)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < g_set)
	{
		if (str[counter] >= '0' && str[counter] <= '9')
		{
			g_right_clues[j] = str[counter] - '0';
			j++;
		}
		counter++;
	}
	return (counter);
}
