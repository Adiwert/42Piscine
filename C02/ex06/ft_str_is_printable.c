/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:17:26 by tstewart          #+#    #+#             */
/*   Updated: 2024/08/29 15:24:53 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 33 || str[i] > 126)
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
	char test1[] = "ABCD1234!?&%";
	char test2[] = "";
	char test3[] = "\n";
	int putnbr1 = ft_str_is_printable(test1);
	int putnbr2 = ft_str_is_printable(test2);
	int putnbr3 = ft_str_is_printable(test3);

	printf("%d\n", putnbr1);
	printf("%d\n", putnbr2);
	printf("%d\n", putnbr3);
}
*/
