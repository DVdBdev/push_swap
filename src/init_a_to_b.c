/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:57:46 by dvan-den          #+#    #+#             */
/*   Updated: 2024/04/10 16:01:22 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Assigns index values and determines if nodes are above the median
 * for stack 'a'.
 * 
 * This function assigns index values to nodes in stack 'a' and determines
 * if each node is above the median index.
 * 
 * @param stack A pointer to the head of stack 'a'.
 */
void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

/**
 * @brief Sets target nodes for each node in stack 'a' based on stack 'b'.
 * 
 * This function sets target nodes for each node in stack 'a' based on the
 * values in stack 'b'.
 * 
 * @param a A pointer to the head of stack 'a'.
 * @param b A pointer to the head of stack 'b'.
 */
static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr
				&& current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

/**
 * @brief Analyzes the cost of pushing each node from stack 'a' to stack
 * 'b'.
 * 
 * This function analyzes the cost of pushing each node from stack 'a' to
 * stack 'b' based on their index, whether they are above the median, and
 * the index of their target node in stack 'b'.
 * 
 * @param a A pointer to the head of stack 'a'.
 * @param b A pointer to the head of stack 'b'.
 */
static void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

/**
 * @brief Sets the cheapest node in stack 'a'.
 * 
 * This function identifies the node with the lowest push cost in stack 'a'
 * and marks it as the cheapest.
 * 
 * @param stack A pointer to the head of stack 'a'.
 */
void	set_cheapest(t_stack_node *stack)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

/**
 * @brief Initializes various attributes of nodes in stack 'a'.
 * 
 * This function initializes the index, target nodes, push costs, and
 * identifies the cheapest node for each node in stack 'a'.
 * 
 * @param a A pointer to the head of stack 'a'.
 * @param b A pointer to the head of stack 'b'.
 */
void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
