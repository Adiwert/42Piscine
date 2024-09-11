/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:22:24 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/04 19:43:28 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb < 0 || nb > 2147395600)
		return (0);
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	int	n;

	n = 1764;
	printf("The square root of %d is %d\n", n, ft_sqrt(n));
	n = 42;
	printf("The square root of %d is %d\n", n, ft_sqrt(n));
	n = 0;
	printf("The square root of %d is %d\n", n, ft_sqrt(n));
	n = 2147395600;
	printf("The square root of %d is %d\n", n, ft_sqrt(n));
	n = -42;
	printf("The square root of %d is %d\n", n, ft_sqrt(n));
	return (0);
}
*/
