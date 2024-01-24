/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:37:21 by dvan-den          #+#    #+#             */
/*   Updated: 2024/01/24 12:19:38 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Frees the memory allocated for a dynamically allocated
 * string array.
 *
 * This function iterates through the elements of the string array and
 * frees the memory for each element.
 *
 * @param str_array A pointer to the dynamically allocated string array.
 */
/**
 * @brief Frees the memory allocated for a dynamically allocated
 * string array.
 *
 * This function iterates through the elements of the string array and
 * frees the memory for each element.
 *
 * @param str_array A pointer to the dynamically allocated string array.
 */
void	free_string_array(char **str_array)
{
	int	i;

	if (str_array == NULL)
		return ;
	i = 0;
	while (str_array[i] != NULL)
	{
		free(str_array[i]);
		i++;
	}
	free(str_array);
}

/**
 * @brief Prints an error message and returns 0.
 *
 * This function is responsible for reporting errors in the program.
 *
 * @param msg A pointer to a character array representing the error message.
 * @return Returns 0 after printing the error message.
 */
static int	error(char *msg)
{
	ft_printf("%s\n", msg);
	return (0);
}

/**
 * @brief Cleans up allocated resources.
 *
 * This function is responsible for cleaning up resources, 
 * specifically freeing the memory
 * associated with the stack in the provided 'data' structure.
 *
 * @param data The 't_data' structure containing program data.
 * @return Returns 0 after cleanup.
 */
static int	cleanup(t_data data)
{
	free_stack(&data.a);
	return (0);
}

/**
 * @brief Main function for the sorting algorithm using stacks.
 *
 * This function initializes stacks A and B, processes the input,
 * and performs the sorting algorithm based on the stack size.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of strings containing the command-line arguments.
 * @return 0 on successful execution.
 */
int	main(int argc, char **argv)
{
	t_data	data;

	data.a = NULL;
	data.b = NULL;
	if (argc <= 1)
		return (error("Error"));
	else if (argc >= 2)
	{
		data.input_str = argv_to_string(argv);
		if (!data.input_str)
			return (error("Error"));
		data.splitted_str = ft_split(data.input_str, ' ');
		free(data.input_str);
		init_stack_from_str(&data.a, data.splitted_str);
		if (!stack_sorted(data.a))
		{
			if (stack_len(data.a) == 2)
				sa(&data.a);
			else if (stack_len(data.a) == 3)
				sort_small(&data.a);
			else
				sort_stacks(&data.a, &data.b);
		}
	}
	return (cleanup(data));
}
