/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:51:32 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/04 14:19:30 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

/*
#include <stdio.h>

int	main(void)
{
	int	i;

	i = 6;
	printf("Fibonacci(%d) = %d\n", i, ft_fibonacci(i));
	i = 1;
	printf("Fibonacci(%d) = %d\n", i, ft_fibonacci(i));
	i = 0;
	printf("Fibonacci(%d) = %d\n", i, ft_fibonacci(i));
	i = -2;
	printf("Fibonacci(%d) = %d\n", i, ft_fibonacci(i));
	return (0);
}
*/
