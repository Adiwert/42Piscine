/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:35:00 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/09 23:44:42 by tstewart         ###   ########.fr       */
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
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int count;

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

int	ft_seplen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !check_separator(str[i], charset))
	{
		i++;
	}
	return (i);
}

char	*ft_word(char *str, char *charset)
{
	int		word_len;
	int		i;
	char	*word;
	
	i = 0;
	word_len = ft_seplen(str, charset);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (word == NULL)
		return (NULL)
	while (i < word_len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		i;

	i = 0;
	strs = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (strs == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && check_separator(str[i], charset))
			i++;
		if (str[i] != '\0')
		{
			strs[i] = ft_word(str, charset);
			if (strs[i] == NULL)
			{
				while (i > 0)
					free(strs[--i]);
				free(strs);
				return (NULL);
			}
			i++;
		}
		while (str[i] != '\0' && !check_separator(str[i], charset))
			i++;
	}
	strs[i] = 0;
	return (strs);
}


#include <stdio.h>
int main(void)
{
    char **split;
    int i;

    // Test case 1: Basic test with separators
    split = ft_split("Hello,World,Split,Test", ",");
    printf("Test Case 1:\n");
    i = 0;
    while (split && split[i])
    {
        printf("%s\n", split[i]);
        free(split[i]); // Free each allocated string
        i++;
    }
    free(split); // Free the array of strings

    // Test case 2: Multiple consecutive separators
    split = ft_split("One,,Two,,,Three", ",");
    printf("Test Case 2:\n");
    i = 0;
    while (split && split[i])
    {
        printf("%s\n", split[i]);
        free(split[i]); // Free each allocated string
        i++;
    }
    free(split); // Free the array of strings

    // Test case 3: No separators
    split = ft_split("NoSeparators", ",");
    printf("Test Case 3:\n");
    i = 0;
    while (split && split[i])
    {
        printf("%s\n", split[i]);
        free(split[i]); // Free each allocated string
        i++;
    }
    free(split); // Free the array of strings

    // Test case 4: Empty string
    split = ft_split("", ",");
    printf("Test Case 4:\n");
    i = 0;
    while (split && split[i])
    {
        printf("%s\n", split[i]);
        free(split[i]); // Free each allocated string
        i++;
    }
    free(split); // Free the array of strings

    // Test case 5: All separators
    split = ft_split(",,,", ",");
    printf("Test Case 5:\n");
    i = 0;
    while (split && split[i])
    {
        printf("%s\n", split[i]);
        free(split[i]); // Free each allocated string
        i++;
    }
    free(split); // Free the array of strings

    return 0;
}
