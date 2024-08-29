/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:50:23 by tstewart          #+#    #+#             */
/*   Updated: 2024/08/29 14:54:16 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 'a' || str[i] > 'z')
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
	char test1[] = "abcdefg";
	char test2[] = "AbCdEfG";
	char test3[] = "I love 42!";
	int putnbr1 = ft_str_is_lowercase(test1);
	int putnbr2 = ft_str_is_lowercase(test2);
	int putnbr3 = ft_str_is_lowercase(test3);

	printf("%d\n", putnbr1);
	printf("%d\n", putnbr2);
	printf("%d\n", putnbr3);
}
*/
