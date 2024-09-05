/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:42:18 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/03 12:35:08 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		i = 0;
		j = 0;
		while (str[i] == to_find[j] && to_find[j] != '\0')
		{
			i++;
			j++;
		}
		if (to_find[j] == '\0')
		{
			return (str);
		}
		str++;
	}
	return ((void *)0);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str1[] = "Hello! Welcome to 42KL!";
	char	str2[] = "Welcome";
	char	*result;

	result = ft_strstr(str1, str2);
	if (result != ((void *)0))
		printf("Found: %s\n", result);
	else
		printf("Not found: %s\n", str2);
	return (0);
}
*/
