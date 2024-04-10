/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:36:26 by dvan-den          #+#    #+#             */
/*   Updated: 2024/04/10 15:49:51 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Counts the number of words in a string delimited by a
 * specified character.
 * 
 * This function counts the number of words in the string 's'
 * delimited by the character 'c'.
 * 
 * @param s The string to be split into words.
 * @param c The delimiter character.
 * 
 * @return The number of words found in the string.
 */
static int	count_words(char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

/**
 * @brief Retrieves the next word from a string delimited by a specified
 * character.
 * 
 * This function retrieves the next word from the string 's' starting at
 * the current cursor position, delimited by the character 'c'.
 * 
 * @param s The string to extract the word from.
 * @param c The delimiter character.
 * 
 * @return A dynamically allocated string containing the next word, or
 * NULL if memory allocation fails.
 */
static char	*get_next_word(char *s, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == c)
		++cursor;
	while ((s[cursor + len] != c) && s[cursor + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

/**
 * @brief Splits a string into an array of words delimited by a specified
 * character.
 * 
 * This function splits the string 's' into an array of words delimited by
 * the character 'c'.
 * 
 * @param s The string to be split.
 * @param c The delimiter character.
 * 
 * @return An array of strings, where each element is a word from the
 * original string, or NULL if memory allocation fails.
 */
char	**split(char *s, char c)
{
	int		words_count;
	char	**result_array;
	int		i;

	i = 0;
	words_count = count_words(s, c);
	if (!words_count)
		exit(1);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2));
	if (!result_array)
		return (NULL);
	while (words_count-- >= 0)
	{
		if (i == 0)
		{
			result_array[i] = malloc(sizeof(char));
			if (!result_array[i])
				return (NULL);
			result_array[i++][0] = '\0';
			continue ;
		}
		result_array[i++] = get_next_word(s, c);
	}
	result_array[i] = NULL;
	return (result_array);
}
