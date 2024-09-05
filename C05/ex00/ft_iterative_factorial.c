/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:36:34 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/04 12:54:48 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0)
	{
		return (0);
	}
	if (nb == 0)
	{
		return (result);
	}
	while (nb > 0)
	{
		result *= nb;
		nb--;
	}
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	int n;

	n = 3;
	printf("Factorial of %d: %d\n", n, ft_iterative_factorial(n));
	n = 10;
	printf("Factorial of %d: %d\n", n, ft_iterative_factorial(n));
	n = 0;
	printf("Factorial of %d: %d\n", n, ft_iterative_factorial(n));
	n = -5;
	printf("Factorial of %d: %d\n", n, ft_iterative_factorial(n));
	return (0);
}
*/
