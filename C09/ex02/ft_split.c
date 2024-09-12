/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:41:53 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/12 12:56:13 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && check_separator(str[i], charset))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !check_separator(str[i], charset))
			i++;
	}
	return (count);
}

char	*ft_word(char *str, char *charset)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = 0;
	while (str[len] && !check_separator(str[len], charset))
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;

	i = 0;
	result = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (result == NULL)
		return (NULL);
	while (*str != '\0')
	{
		while (*str != '\0' && check_separator(*str, charset))
			str++;
		if (*str && !check_separator(*str, charset))
		{
			result[i] = ft_word(str, charset);
			if (!result[i++])
				return (NULL);
			while (*str && !check_separator(*str, charset))
				str++;
		}
	}
	result[i] = NULL;
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	char	**split;
	int		i;

	// Test case 1: Basic test with separators
	split = ft_split("Hello,World,42KL,is,nice,", ",");
	printf("Test Case 1:\n");
	i = 0;
	while (split && split[i])
	{
		printf("%s\n", split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	printf("\n");

	// Test case 2: Multiple consecutive separators
	split = ft_split("One,,Two,,,Three,Four,,,,Five", ",");
	printf("Test Case 2:\n");
	i = 0;
	while (split && split[i])
	{
		printf("%s\n", split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	printf("\n");

	// Test case 3: No separators
	split = ft_split("NoSeparators", ",");
	printf("Test Case 3:\n");
	i = 0;
	while (split && split[i])
	{
		printf("%s\n", split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	printf("\n");

	// Test case 4: Empty string
	split = ft_split("", ",");
	printf("Test Case 4:\n");
	i = 0;
	while (split && split[i])
	{
		printf("%s\n", split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	printf("\n");

	// Test case 5: All separators
	split = ft_split(",  , ?,!,,?,!", ", !?");
	printf("Test Case 5:\n");
	i = 0;
	while (split && split[i])
	{
		printf("%s\n", split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	printf("\n");
	return (0);
}
*/
