/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:10:28 by dvan-den          #+#    #+#             */
/*   Updated: 2024/01/24 12:10:48 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Finds the node marked as the cheapest in the linked list.
 *
 * This function traverses the linked list to find the node marked
 * as the cheapest.
 *
 * @param stack A pointer to the head of the linked list.
 * @return A pointer to the cheapest node, or NULL if no node is
 * marked as cheapest.
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
 * @brief Checks if a linked list is sorted in non-decreasing order.
 *
 * This function checks if a linked list is sorted in non-decreasing
 * order based on the node values.
 *
 * @param stack A pointer to the head of the linked list.
 * @return True if the linked list is sorted, false otherwise.
 */
bool	stack_sorted(t_stack_node *stack)
{
	t_stack_node	*curr;

	if (stack == NULL || stack->next == NULL)
		return (true);
	curr = stack;
	while (curr->next != NULL)
	{
		if (curr->value > curr->next->value)
			return (false);
		curr = curr->next;
	}
	return (true);
}

/**
 * @brief Rotates both stack A and stack B until the specified node
 * is at the top.
 *
 * This function performs rotations on both stack A and stack B until the
 * specified node (marked as the cheapest) is at the top of stack B and
 * its target is at the top of stack A.
 *
 * @param a A pointer to the head of stack A.
 * @param b A pointer to the head of stack B.
 * @param cheapest A pointer to the node marked as the cheapest.
 */
void	r_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

/**
 * @brief Reverses both stack A and stack B until the specified node is
 * at the top.
 *
 * This function performs reverse rotations on both stack A and stack B
 * until the specified node (marked as the cheapest) is at the top of
 * stack B and its target is at the top of stack A.
 *
 * @param a A pointer to the head of stack A.
 * @param b A pointer to the head of stack B.
 * @param cheapest A pointer to the node marked as the cheapest.
 */
void	rr_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}
