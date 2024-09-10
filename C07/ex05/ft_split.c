/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:35:00 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/10 20:42:47 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_separator(char c, char *charset) // Checks if a character is in the set of separator characters.
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
		{
			return (1); // If a match is found, return 1 (indicating that c is a separator).
		}
		i++; // Move to the next character in charset.
	}
	return (0); // If no match is found after the loop, return 0 (indicating that c is not a separator).
}

int	count_words(char *str, char *charset) // Counts the number of words in str separated by characters in charset.
{
	int	i; // Variable index.
	int	count; // Variable to keep track of the number of words.

	i = 0;
	count = 0;
	while (str[i] != '\0') // Loop through the string str.
	{
		while (str[i] != '\0' && check_separator(str[i], charset)) // Skip over separator characters.
			i++;
		if (str[i] != '\0') // If we are at a non-separator character, it indicates the start of a new word.
			count++; // Increment the word count.
		while (str[i] != '\0' && !check_separator(str[i], charset)) // Skip over non-separator characters to reach the next separator.
			i++;
	}
	return (count); // Return the number of words found.
}

char	*ft_word(char *str, char *charset) // Allocates memory and returns strings that represent words from str.
{
	int		i; // Variable index.
	int		len; // Variable to store the length of the word.
	char	*word; // Pointer to the newly allocated string for the word.

	i = 0;
	len = 0;
	while (str[len] && !check_separator(str[len], charset))
		len++; // Calculate the length of the word by counting characters until a separator is found.
	word = (char *)malloc(sizeof(char) * (len + 1)); // Allocate memory for the words and null terminator.
	if (word == NULL) // Check if memory allocation failed.
		return (NULL);
	while (i < len) // Copy the word into the allocated memory while the index still less than length.
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0'; // Add null terminator to the end of the string.
	return (word); // Return the newly allocated words.
}

char	**ft_split(char *str, char *charset) // Splits str into an array of strings.
{
	char	**result; // Pointer to an array of strings (the result).
	int		i; // Index for the result array.

	i = 0;
	result = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1)); // Allocate memory for the array of strings and null terminator.
	if (result == NULL) // Check if memory allocation failed.
		return (NULL);
	while (*str != '\0')
	{
		while (*str != '\0' && check_separator(*str, charset)) // Skip over separator characters.
			str++;
		if (*str && !check_separator(*str, charset)) // If we are at the start of a new word:
		{
			result[i] = ft_word(str, charset); // Allocate memory and copy the words into the result array.
			if (!result[i++]) // Check if ft_word failed to allocate memory and it loop through every word.
				return (NULL);
			while (*str && !check_separator(*str, charset)) // Skip over characters of the current word.
				str++;
		}
	}
	result[i] = NULL; // Null-terminate the array of strings.
	return (result); // Return the array of strings.
}

/*
#include <stdio.h>

int	main(void)
{
	char	**split; // This will be used to hold the result of the ft_split function, which is an array of strings.
	int		i; // Index for iterating through the split array.

	// Test case 1: Basic test with separators
	split = ft_split("Hello,World,42KL,is,nice,", ",");
	printf("Test Case 1:\n");
	i = 0;
	while (split && split[i]) // Loops through the split array as long as split is not NULL and split[i] is not NULL.
	{
		printf("%s\n", split[i]); // Prints the current string (split[i]).
		free(split[i]); // Frees the memory allocated for the current string (split[i]).
		i++; // Move to the next element in the array.
	}
	free(split); // Frees the memory allocated for the split array itself.
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
	split = ft_split(",!?  ?, ?!,", ", ?!");
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
