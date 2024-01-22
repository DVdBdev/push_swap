/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:04:09 by dvan-den          #+#    #+#             */
/*   Updated: 2024/01/22 11:46:05 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Validates if a given string represents a valid integer.
 *
 * This function checks if the input string is a valid integer. It considers
 * optional leading '+' or '-' characters, followed by digits.
 *
 * @param str The input string to be validated.
 * @return 1 if the string is a valid integer, 0 otherwise.
 */
int	is_valid_integer(const char *str)
{
	int	valid_int;
	int	plus_and_minus;

	plus_and_minus = *str != '+' && *str != '-';
	valid_int = plus_and_minus && !ft_isdigit((unsigned char)*str);
	if (str == NULL || *str == '\0' || valid_int)
		return (0);
	if (*str == '+' || *str == '-')
	{
		str++;
		if (!ft_isdigit((unsigned char)*str))
			return (0);
	}
	while (*str)
	{
		if (!ft_isdigit((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * @brief Checks if a given value already exists in the stack.
 *
 * This function iterates through the provided stack to check if the given
 * integer value already exists in the stack.
 *
 * @param stack The stack to be checked.
 * @param n The value to be checked for duplicates.
 * @return 1 if the value exists in the stack, 0 otherwise.
 */
int	has_duplicate(t_stack_node *stack, int n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->value == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

/**
 * @brief Frees the memory occupied by a stack.
 *
 * This function deallocates the memory occupied by each node in the stack
 * and sets the stack pointer to NULL.
 *
 * @param stack A pointer to the stack to be freed.
 */
void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*curr;

	if (!stack)
		return ;
	curr = *stack;
	while (curr)
	{
		temp = curr->next;
		curr->value = 0;
		free(curr);
		curr = temp;
	}
	*stack = NULL;
}

/**
 * @brief Handles errors, frees memory, and exits the program.
 *
 * This function is called in case of an error. It prints an error message,
 * frees the memory occupied by the stack, and exits the program with 
 * an error code.
 *
 * @param stack A pointer to the stack to be freed.
 * @param message The error message to be displayed.
 */
void	handle_error_and_exit(t_stack_node **stack, const char *message)
{
	free_stack(stack);
	ft_printf("Error\n", message);
	exit(1);
}
