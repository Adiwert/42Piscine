/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:18:44 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/07 23:39:12 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (src[len])
	{
		len++;
	}
	dest = (char *)malloc(len + 1);
	if (!dest)
	{
		return (NULL);
	}
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	char	*src = "Hello World!";
	char	*dup;

	dup = ft_strdup(src);
	if (dup != '\0')
	{
		printf("Source: %s\n", src);
		printf("Duplicate: %s\n", dup);
		free(dup);
	}
	else
	{
		printf("Memory allocation failed!\n");
	}
	return (0);
}
*/
