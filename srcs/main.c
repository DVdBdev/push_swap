/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:37:21 by dvan-den          #+#    #+#             */
/*   Updated: 2023/11/02 11:50:43 by dvan-den         ###   ########.fr       */
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
 * @brief Helper function for main that handles the sorting based
 * on the size of stack A.
 *
 * This function performs sorting based on the size of stack A. It
 * either swaps or sorts the stacks accordingly.
 *
 * @param a A pointer to the head of stack A.
 * @param b A pointer to the head of stack B.
 */
void	main_help(t_stack_node *a, t_stack_node *b)
{
	if (stack_len(a) == 2)
		sa(&a);
	else if (stack_len(a) == 3)
		sort_small(&a);
	else
		sort_stacks(&a, &b);
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
	t_stack_node	*a;
	t_stack_node	*b;
	char			*input_str;
	char			**splitted_str;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (0);
	else if (argc >= 2)
	{
		input_str = argv_to_string(argv);
		if (!input_str)
		{
			ft_printf("Error\n");
			return (0);
		}
		splitted_str = ft_split(input_str, ' ');
		free(input_str);
		init_stack_from_str(&a, splitted_str);
		if (!stack_sorted(a))
			main_help(a, b);
	}
	free_stack(&a);
	return (0);
}
