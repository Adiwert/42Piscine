/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:30:02 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/04 13:48:05 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

/*
#include <stdio.h>

int	main(void)
{
	int n;
	int power;

	n = 3;
	power = 3;
	printf("%d^%d = %d\n", n, power, ft_recursive_power(n, power));
	n = 0;
	power = 0;
	printf("%d^%d = %d\n", n, power, ft_recursive_power(n, power));
	n = -3;
	power = 3;
	printf("%d^%d = %d\n", n, power, ft_recursive_power(n, power));
	n = 3;
	power = -3;
	printf("%d^%d = %d\n", n, power, ft_recursive_power(n, power));
	return (0);
}
*/
