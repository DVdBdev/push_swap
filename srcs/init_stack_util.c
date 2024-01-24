/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:08:34 by dvan-den          #+#    #+#             */
/*   Updated: 2024/01/24 12:00:41 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Concatenates the contents of s2 to the end of s1.
 *
 * This function appends the contents of the string s2 to the 
 * end of the string s1.
 *
 * @param s1 The destination string.
 * @param s2 The source string to be appended.
 */
static void	ft_strcat(char *s1, const char *s2)
{
	while (*s1 != '\0')
	{
		s1++;
	}
	while (*s2 != '\0')
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
}

/**
 * @brief Calculates the total length required to store an array of strings.
 *
 * This function calculates the total length required to store an array 
 * of strings, including space for null terminators and separating spaces.
 *
 * @param argv The array of strings.
 * @return The total length required, or 0 if an empty string is found in argv.
 */
static int	calculate_total_length(char **argv)
{
	int		i;
	size_t	curr_len;
	int		total_length;

	i = 0;
	total_length = 0;
	while (argv[i] != NULL)
	{
		curr_len = ft_strlen(argv[i]);
		if (curr_len == 0)
		{
			ft_printf("Error: Empty string in argv\n");
			return (0);
		}
		total_length += curr_len + 1;
		i++;
	}
	return (total_length);
}

/**
 * @brief Converts an array of strings to a single space-separated string.
 *
 * This function concatenates an array of strings into a single 
 * space-separated string.
 *
 * @param argv The array of strings to be converted.
 * @return The resulting string, or NULL if an error occurs.
 */
char	*argv_to_string(char **argv)
{
	char	*result;
	int		total_length;
	int		i;

	result = NULL;
	if (argv != NULL)
	{
		total_length = calculate_total_length(argv);
		if (total_length == 0)
			return (NULL);
		result = (char *)malloc(total_length + 1);
		if (result != NULL)
		{
			result[0] = '\0';
			i = 1;
			while (argv[i] != NULL)
			{
				ft_strcat(result, argv[i]);
				if (argv[i + 1] != NULL)
					ft_strcat(result, " ");
				i++;
			}
		}
	}
	return (result);
}

/**
 * @brief Converts a string to a long integer.
 *
 * This function converts the given string to a long integer,
 * handling leading whitespace and sign characters.
 *
 * @param s The input string to be converted.
 * @return The resulting long integer.
 */
long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || (*s >= '\t' && *s <= '\r'))
		s++;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	return (result * sign);
}

/**
 * @brief Finds the last node in a linked list.
 *
 * This function returns a pointer to the last node in a linked list.
 *
 * @param stack The linked list.
 * @return A pointer to the last node, or NULL if the list is empty.
 */
t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
