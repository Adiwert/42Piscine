/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:27:50 by tstewart          #+#    #+#             */
/*   Updated: 2024/08/22 22:21:40 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	ft_

void	ft_print_comb2(void)
{
	int a = 0;
	int b = 1;

	while (a <= 98)
	{
		while (b <= 99)
		{
			char	a_tens = '0' + (a / 10);
			char	a_units = '0' + (a % 10);
			write (1, &a_tens, 1);
			write (1, &a_units, 1);
			write (1, " ", 1);
			char	b_tens = '0' + (b / 10);
			char	b_units = '0' + (b % 10);
			write (1, &b_tens, 1);
			write (1, &b_units, 1);

			if (!(a == 98 && b == 99))
			{
				write (1, ", ", 2);
			}
			b++;
		}
		a++;
		b = a + 1;
	}
}

int	main(void)
{
	ft_print_comb2();
	write (1, "\n", 1);
	return (0);
}
