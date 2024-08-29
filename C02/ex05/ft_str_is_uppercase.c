/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:57:39 by tstewart          #+#    #+#             */
/*   Updated: 2024/08/29 15:04:22 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 'A' || str[i] > 'Z')
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
	char test1[] = "ABCDEFG";
	char test2[] = "AbCdEfG";
	char test3[] = "I love 42!";
	int putnbr1 = ft_str_is_uppercase(test1);
	int putnbr2 = ft_str_is_uppercase(test2);
	int putnbr3 = ft_str_is_uppercase(test3);

	printf("%d\n", putnbr1);
	printf("%d\n", putnbr2);
	printf("%d\n", putnbr3);
}
*/
