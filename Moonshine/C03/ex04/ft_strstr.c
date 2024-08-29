/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquah <mquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:52:06 by mquah             #+#    #+#             */
/*   Updated: 2024/08/28 17:05:33 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *tc_find)
{
	int	i;
	int	j;

	if (*tc_find == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == tc_find[j] && tc_find[j] != 0)
			j++;
		if (tc_find[j] == '\0')
			return (str + i);
		i++;
	}
	return ((char *)0);
}

#include <stdio.h>
int	main(void)
{
	char	*returnstr = ft_strstr("bapple", "app");
	printf("%s", returnstr);
	return (0);
}
