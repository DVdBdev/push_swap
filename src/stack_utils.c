/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:02:40 by dvan-den          #+#    #+#             */
/*   Updated: 2024/04/10 15:55:45 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Calculates the length of a stack.
 * 
 * This function counts the number of nodes in the given stack.
 * 
 * @param stack A pointer to the head of the stack.
 * 
 * @return The number of nodes in the stack.
 */
int	stack_len(t_stack_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

/**
 * @brief Finds the last node in a stack.
 * 
 * This function traverses the stack and returns a pointer to the last node.
 * 
 * @param stack A pointer to the head of the stack.
 * 
 * @return A pointer to the last node in the stack.
 */
t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/**
 * @brief Checks if a stack is sorted in ascending order.
 * 
 * This function checks if the given stack is sorted in ascending order.
 * 
 * @param stack A pointer to the head of the stack.
 * 
 * @return true if the stack is sorted, false otherwise.
 */
bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

/**
 * @brief Finds the node with the minimum value in a stack.
 * 
 * This function traverses the stack to find the node with the minimum value.
 * 
 * @param stack A pointer to the head of the stack.
 * 
 * @return A pointer to the node with the minimum value.
 */
t_stack_node	*find_min(t_stack_node *stack)
{
	long			min;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

/**
 * @brief Finds the node with the maximum value in a stack.
 * 
 * This function traverses the stack to find the node with the maximum value.
 * 
 * @param stack A pointer to the head of the stack.
 * 
 * @return A pointer to the node with the maximum value.
 */
t_stack_node	*find_max(t_stack_node *stack)
{
	long			max;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
