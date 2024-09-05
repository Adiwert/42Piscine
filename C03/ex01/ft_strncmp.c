/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 22:39:35 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/03 23:03:10 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && *s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
		i++;
	}
	if (i == n)
		return (0);
	return (*s1 - *s2);
}

/*
#include <stdio.h>

int	main(void)
{
	char			*str1;
	char			*str2;
	unsigned int	n;
	int				result;

	n = 10;
	str1 = "HelloWorld";
	str2 = "HelloThere";
	result = ft_strncmp(str1, str2, n);
	printf("Comparison result: %d\n", result);
	return(0);
}
*/
