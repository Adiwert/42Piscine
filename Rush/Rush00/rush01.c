/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iahromi <iahromi@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:07:39 by iahromi           #+#    #+#             */
/*   Updated: 2024/08/26 12:40:59 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_row(char start, char middle, char end, int x)
{
	int	i;

	i = 0;
	if (x >= 1)
	{
		ft_putchar(start);
	}
	while (x > i + 2)
	{
		ft_putchar(middle);
		i++;
	}
	if (x >= 2)
	{
		ft_putchar(end);
	}
	ft_putchar('\n');
}

void	rush01(int x, int y)
{
	int	j;

	j = 0;
	if (x <= 0 || y <= 0)
	{
		write(1, "Haiyaaa, how can the value be zero or negative?", 47);
		ft_putchar('\n');
	}
	if (x >= 1 && y >= 1)
	{
		ft_print_row('/', '*', '\\', x);
	}
	while (x >= 1 && y > j + 2)
	{
		ft_print_row('*', ' ', '*', x);
		j++;
	}
	if (x >= 1 && y >= 2)
	{
		ft_print_row('\\', '*', '/', x);
	}
}
