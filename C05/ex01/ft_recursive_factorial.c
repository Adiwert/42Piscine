/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:55:30 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/04 13:21:56 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
	{
		return (0);
	}
	else if (nb == 0)
	{
		return (1);
	}
	else
		return (nb * ft_recursive_factorial(nb - 1));
}

/*
#include <stdio.h>

int	main(void)
{
	int n;

	n = 3;
	printf("Factorial of %d: %d\n", n, ft_recursive_factorial(n));
	n = 10;
	printf("Factorial of %d: %d\n", n, ft_recursive_factorial(n));
	n = 0;
	printf("Factorial of %d: %d\n", n, ft_recursive_factorial(n));
	n = -5;
	printf("Factorial of %d: %d\n", n, ft_recursive_factorial(n));
	return (0);
}
*/
