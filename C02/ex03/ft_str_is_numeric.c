/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:42:04 by tstewart          #+#    #+#             */
/*   Updated: 2024/08/29 14:55:07 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*
#include <stdio.h>

int	main(void)
{
	char test1[] = "42";
	char test2[] = "42KL";
	char test3[] = "I love 42!";
	int putnbr1 = ft_str_is_numeric(test1);
	int putnbr2 = ft_str_is_numeric(test2);
	int putnbr3 = ft_str_is_numeric(test3);

	printf("%d\n", putnbr1);
	printf("%d\n", putnbr2);
	printf("%d\n", putnbr3);
}
*/
