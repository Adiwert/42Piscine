/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:25:43 by zlee              #+#    #+#             */
/*   Updated: 2024/08/27 14:43:27 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	char	*temp;
	int		count;

	count = 0;
	temp = str;
	while (str[count] != '\0')
	{
		if ((str[count] >= 'A') && (str[count] <= 'Z'))
		{
			temp[count] += 32;
		}
		count++;
	}
	return (str);
}

#include <stdio.h>
 int main(void)
{
    char test1[] = "TESTTEST";
    ft_strlowcase(test1);
    printf("%s\n", test1);
}
