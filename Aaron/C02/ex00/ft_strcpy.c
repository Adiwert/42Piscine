/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:29:31 by zlee              #+#    #+#             */
/*   Updated: 2024/08/28 21:25:48 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	count;

	count = 0;
	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

int main(void)
{
    int num = 0;
    char test[] = "Hello";
    char test2[] = "testt";
    ft_strcpy(test, test2);

    while (test[num] != '\0')
    {
        write(1, &test[num], 1);
        num++;
    }
}
