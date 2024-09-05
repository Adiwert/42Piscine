/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:11:44 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/03 22:56:31 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 == *s2) && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*str1;
	char	*str2;
	int		result;

	str1 = "Hello";
	str2 = "Hella";
	result = ft_strcmp(str1, str2);
	printf("Comparison result: %d\n", result);
	return(0);
}
*/
