/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquah <mquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:57:23 by mquah             #+#    #+#             */
/*   Updated: 2024/08/28 17:07:18 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	destlen;
	unsigned int	srclen;
	unsigned int	i;

	destlen = 0;
	srclen = 0;
	i = 0;
	while (dest[destlen] != '\0')
		destlen++;
	while (src[srclen] != '\0')
		srclen++;
	if (size <= destlen)
		return (size + srclen);
	while (i < size - destlen - 1 && src[i] != '\0')
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}

#include <stdio.h>

int	main(void)
{
	char	arr1[7] = "abcd";
	char	arr2[] = "efgh";

	int intend_len = ft_strlcat(arr1, arr2, 7);
	printf("%s\n", arr1);
	printf("%d", intend_len);
	return (0);
}
