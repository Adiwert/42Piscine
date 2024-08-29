/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:04:47 by tstewart          #+#    #+#             */
/*   Updated: 2024/08/29 14:40:29 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
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
	char test1[] = "Thequickbrownfoxjumpsoverthelazydog";
	char test2[] = "The quick brown fox jumps over the lazy dog.";
	char test3[] = "ABC123";
	int putnbr1 = ft_str_is_alpha(test1);
	int putnbr2 = ft_str_is_alpha(test2);
	int putnbr3 = ft_str_is_alpha(test3);

	printf("%d\n", putnbr1);
	printf("%d\n", putnbr2);
	printf("%d\n", putnbr3);
}
*/
