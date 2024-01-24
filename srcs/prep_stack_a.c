/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 07:09:54 by dvan-den          #+#    #+#             */
/*   Updated: 2024/01/24 12:22:11 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Assigns indices and flags for elements in the stack related
 * to their position.
 *
 * This function assigns indices and flags to each element in the stack
 * based on its position, such as whether it is above or below the median.
 *
 * @param stack A pointer to the head of the stack.
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
		i++;
	}
}

/**
 * @brief Sets the target element in stack B for each element in stack A.
 *
 * This function determines the target element in stack B for each element 
 * in stack A.
 *
 * @param a A pointer to the head of stack A.
 * @param b A pointer to the head of stack B.
 */
static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	int				closest_smaller;
	t_stack_node	*curr_b;
	t_stack_node	*target;

	while (a)
	{
		closest_smaller = INT_MIN;
		curr_b = b;
		while (curr_b)
		{
			if (curr_b->value > closest_smaller && curr_b->value < a->value)
			{
				closest_smaller = curr_b->value;
				target = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (closest_smaller == INT_MIN)
			a->target = find_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

/**
 * @brief Performs cost analysis for each element in stack A based on its 
 * position and target.
 *
 * This function calculates the push cost for each element in stack A based
 * on its index, whether it is above or below the median, and the index of
 * its target in stack B.
 *
 * @param a A pointer to the head of stack A.
 * @param b A pointer to the head of stack B.
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
			a->push_cost = len_a - a->index;
		if (a->target->above_median)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - a->target->index;
		a = a->next;
	}
}

/**
 * @brief Sets the cheapest flag for the element with the lowest push cost in
 * the stack.
 *
 * This function sets the "cheapest" flag for the element with the lowest push
 * cost in the stack.
 *
 * @param stack A pointer to the head of the stack.
 */
static void	set_cheapest(t_stack_node *stack)
{
	int				cheapest;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest = INT_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest)
		{
			cheapest = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

/**
 * @brief Prepares stack A for further processing in the algorithm.
 *
 * This function prepares stack A by assigning indices, determining targets
 * in stack B, performing cost analysis, and setting the cheapest flag for
 * the optimal element to push.
 *
 * @param a A pointer to the head of stack A.
 * @param b A pointer to the head of stack B.
 */
void	prep_stack_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
