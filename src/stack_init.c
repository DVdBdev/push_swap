/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:01:42 by dvan-den          #+#    #+#             */
/*   Updated: 2024/04/10 15:53:41 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Converts a string to a long integer.
 * 
 * This function converts the initial portion of the string 's' to a long
 * integer representation.
 * 
 * @param s The string to be converted.
 * 
 * @return The long integer representation of the string.
 */
static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

/**
 * @brief Appends a new node with a given number to the end of a stack.
 * 
 * This function creates a new node with the given number 'n' and appends
 * it to the end of the stack.
 * 
 * @param stack A pointer to the pointer to the head of the stack.
 * @param n The number to be added to the stack.
 */
static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

/**
 * @brief Initializes stack 'a' with numbers from command-line arguments.
 * 
 * This function initializes stack 'a' with numbers parsed from the
 * command-line arguments.
 * 
 * @param a A pointer to the pointer to the head of stack 'a'.
 * @param argv An array of strings containing the command-line arguments.
 */
void	init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (error_duplicate(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}

/**
 * @brief Finds the first node marked as 'cheapest' in a stack.
 * 
 * This function searches for the first node in the stack marked as
 * 'cheapest'.
 * 
 * @param stack A pointer to the head of the stack.
 * 
 * @return A pointer to the first node marked as 'cheapest', or NULL if no
 * such node exists.
 */
t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

/**
 * @brief Prepares a stack for pushing a node to the top.
 * 
 * This function rotates the stack until the given 'top_node' is at the
 * top position for pushing.
 * 
 * @param stack A pointer to the pointer to the head of the stack.
 * @param top_node A pointer to the node that needs to be at the top.
 * @param stack_name The name of the stack ('a' or 'b').
 */
void	prep_for_push(t_stack_node **stack,
						t_stack_node *top_node,
						char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
