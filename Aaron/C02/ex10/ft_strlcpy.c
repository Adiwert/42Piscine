/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 08:41:42 by zlee              #+#    #+#             */
/*   Updated: 2024/08/27 14:46:23 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	count;

	count = 0;
	while (count < size - 1 && src[count] != '\n')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (count);
}

#include <stdio.h>
int main(void)
{
    char test1[] = "character";
    char test2[] = "abcdef";
    unsigned int num = ft_strlcpy(test2, test1, 5);
    printf("%d\n", num);
}
