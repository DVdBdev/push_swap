/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:57:10 by dvan-den          #+#    #+#             */
/*   Updated: 2024/04/10 15:58:10 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Checks for syntax errors in a string representing a number.
 * 
 * This function checks if the given string 'str_n' represents a valid
 * number.
 * 
 * @param str_n The string to be checked.
 * 
 * @return 1 if syntax error is found, 0 otherwise.
 */
int	error_syntax(char *str_n)
{
	if (!(*str_n == '+'
			|| *str_n == '-'
			|| (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+'
			|| *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

/**
 * @brief Checks for duplicate numbers in a stack.
 * 
 * This function checks if the given number 'n' already exists in the
 * stack 'a'.
 * 
 * @param a A pointer to the head of the stack.
 * @param n The number to be checked for duplication.
 * 
 * @return 1 if the number is found to be a duplicate, 0 otherwise.
 */
int	error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

/**
 * @brief Frees memory allocated for a stack.
 * 
 * This function frees the memory allocated for all nodes in the stack.
 * 
 * @param stack A pointer to the pointer to the head of the stack.
 */
void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

/**
 * @brief Frees memory allocated for a stack and exits with an error
 * message.
 * 
 * This function frees the memory allocated for all nodes in the stack 'a'
 * and then exits the program with an error message.
 * 
 * @param a A pointer to the pointer to the head of the stack.
 */
void	free_errors(t_stack_node **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}
