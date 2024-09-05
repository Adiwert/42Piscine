/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:16:11 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/04 13:28:44 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	int n;
	int power;

	n = 3;
	power = 3;
	printf("%d^%d = %d\n", n, power, ft_iterative_power(n, power));
	n = 0;
	power = 0;
	printf("%d^%d = %d\n", n, power, ft_iterative_power(n, power));
	n = -3;
	power = 3;
	printf("%d^%d = %d\n", n, power, ft_iterative_power(n, power));
	n = 3;
	power = -3;
	printf("%d^%d = %d\n", n, power, ft_iterative_power(n, power));
	return (0);
}
*/
