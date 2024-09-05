/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:26:10 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/04 21:55:54 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 3;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 1)
		return (2);
	while (!ft_is_prime(nb))
	{
		nb++;
	}
	return (nb);
}

/*
#include <stdio.h>

int	main(void)
{
	int	n;

	n = 2;
	printf("The next prime number greater than or equal to %d is %d\n"
	, n, ft_find_next_prime(n));
	n = 42;
	printf("The next prime number greater than or equal to %d is %d\n"
	,	n, ft_find_next_prime(n));
	n = 0;
	printf("The next prime number greater than or equal to %d is %d\n"
	, n, ft_find_next_prime(n));
	n = -42;
	printf("The next prime number greater than or equal to %d is %d\n"
	, n, ft_find_next_prime(n));
	n = 123456;
	printf("The next prime number greater than or equal to %d is %d\n"
	,	n, ft_find_next_prime(n));
	return (0);
}
*/
