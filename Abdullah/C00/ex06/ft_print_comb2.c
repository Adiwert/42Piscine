/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mahf <aal-mahf@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:53:17 by aal-mahf          #+#    #+#             */
/*   Updated: 2024/08/27 16:07:11 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	result(char x, char y, char z, char j)
{
	write(1, &x, 1);
	write(1, &y, 1);
	write(1, " ", 1);
	write(1, &z, 1);
	write(1, &j, 1);
	if (!(x == '9' && y == '8' && z == '9' && j == '9'))
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	ft_print_comb2_sub(char x, char y, char z, char j)
{
	x = '0';
	while (x <= '9')
	{
		y = '0';
		while (y <= '8')
		{
			z = '0';
			while (z <= '9')
			{
				j = '1';
				while (j <= '9')
				{	
					result(x, y, z, j);
					j++;
				}
				z++;
			}
			y++;
		}
		x++;
	}
}

void	ft_print_comb2(void)
{
	char	x;
	char	y;
	char	z;
	char	j;

	ft_print_comb2_sub(x, y, z, j);
}

int	main(void)
{
	ft_print_comb2();
	write (1, "\n", 1);
	return (0);
}

