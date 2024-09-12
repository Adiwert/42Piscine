/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:20:08 by zlee              #+#    #+#             */
/*   Updated: 2024/08/29 15:58:48 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strupcase(char *str)
{
	int		count;
	char	*temp;

	count = 0;
	temp = str;
	while (str[count] != '\0')
	{
		if ((str[count] >= 'a') && (str[count] <= 'z'))
		{
			temp[count] -= 32;
		}
		count++;
	}
	return (str);
}

#include <stdio.h>
int main(void)
{
    char test1[] = "sfgfdhsfdh";
    ft_strupcase(test1);
    printf("%s\n", test1);
}
