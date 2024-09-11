/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tabs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:52:05 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/11 19:55:09 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(char *src) // Takes a pointer to a string and returns a pointer to a newly allocated string.
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char *)malloc((ft_strlen(src) + 1) * sizeof(char)); // Allocates memory for the new string copy. (Add 1 for null terminator)
	if (copy == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av) // Returns a pointer to an array of t_stock_str structures.
{
	int			i; // For loop indexing.
	t_stock_str	*tab; // To hold the dynamically allocated array of t_stock_str structures.

	i = 0;
	tab = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str)); // Dynamically allocates memory for an array of t_stock_str structures. (Add 1 for marking the end of the array with a NULL pointer)
	if (tab == NULL)
		return (NULL);
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]); // Stores the length of each string.
		tab[i].str = av[i]; // Sets to the original string.
		tab[i].copy = ft_strdup(av[i]); // Allocates and copies the string.
		if (tab[i].copy == NULL)
			return (NULL); // If ft_strdup returns NULL, memory allocation failed, here should return NULL as well.
		i++;
	}
	tab[i].str = NULL; // Indicate the end of the array.
	return (tab); // Returns the pointer to the new array of t_stock_str structures.
}
