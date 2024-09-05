/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:30:40 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/03 13:36:26 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str1[] = "Hello World!";
	int		result;

	result = ft_strlen(str1);
	printf("Total length of the string is: %d\n", result);
	return (0);
}
*/
