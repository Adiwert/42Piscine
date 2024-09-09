/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:32:11 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/08 20:44:46 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_total_length(int size, char **strs, char *sep)
{
	int	total_length;
	int	sep_length;
	int	i;

	total_length = 0;
	sep_length = ft_strlen(sep);
	i = 0;
	while (i < size)
	{
		total_length += ft_strlen(strs[i]);
		i++;
	}
	total_length += sep_length * (size - 1) + 1;
	return (total_length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*result;

	i = 0;
	if (size == 0)
	{
		result = (char *)malloc(1);
		if (result == NULL)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	result = (char *)malloc(ft_total_length(size, strs, sep));
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*strs[] = {"Hello", "42KL!", "How", "to", "code?"};
	char	*sep = " ";
	char	*result;
	int		size = 5;

	result = ft_strjoin(size, strs, sep);
	if (result != NULL)
	{
		printf("Joined string: %s\n", result);
		free(result);
	}
	else
	{
		printf("Error: Memory allocation failed.\n");
	}
	return (0);
}
*/
