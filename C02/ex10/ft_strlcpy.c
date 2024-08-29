/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:15:44 by tstewart          #+#    #+#             */
/*   Updated: 2024/08/29 21:43:18 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	srclength;

	i = 0;
	srclength = 0;
	while (src[srclength] != '\0')
	{
		srclength++;
	}
	if (size == 0)
	{
		return (srclength);
	}
	while (i < (size - 1) && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (srclength);
}

/*
#include <stdio.h>

int	main(void)
{
	char	src[] = "Hello World!";
	char	dest[10];
	int		length;

	length = ft_strlcpy(dest, src, 10);
	printf("Source: %s\n", src);
	printf("Destination: %s\n", dest);
	printf("Length of the source: %d\n", length);
}
*/
