/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:45:48 by dvan-den          #+#    #+#             */
/*   Updated: 2024/01/24 12:09:46 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Moves the cheapest node from stack A to stack B.
 *
 * This function performs rotations and preparations to move the cheapest
 * node from stack A to stack B. It takes into account the positions of
 * the cheapest node and its target in both stacks.
 *
 * @param a A pointer to the head of stack A.
 * @param b A pointer to the head of stack B.
 */
static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		r_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		rr_both(a, b, cheapest_node);
	prep_a(a, cheapest_node);
	prep_b(b, cheapest_node->target);
	pb(b, a);
}

/**
 * @brief Moves the node from stack B to stack A.
 *
 * This function prepares and moves the node from stack B to stack A.
 *
 * @param a A pointer to the head of stack A.
 * @param b A pointer to the head of stack B.
 */
static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_a(a, (*b)->target);
	pa(a, b);
}

/**
 * @brief Sorts a small set of elements in stack A.
 *
 * This function sorts a small set of elements in stack A using rotation
 * operations.
 *
 * @param a A pointer to the head of stack A.
 */
void	sort_small(t_stack_node **a)
{
	t_stack_node	*max;

	max = find_max(*a);
	if (max == *a)
		ra(a);
	else if ((*a)->next == max)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

/**
 * @brief Moves the node with the minimum value to the top of stack A.
 *
 * This function rotates stack A until the node with the minimum value
 * is at the top.
 *
 * @param a A pointer to the head of stack A.
 */
static void	min_on_top(t_stack_node **a)
{
	t_stack_node	*min;

	min = find_min(*a);
	while ((*a)->value != min->value)
	{
		if (min->above_median)
			ra(a);
		else
			rra(a);
	}
}

/**
 * @brief Sorts the stacks using a custom algorithm.
 *
 * This function sorts the stacks using a combination of push, rotate,
 * and preparation operations. It handles the main logic of the sorting
 * algorithm, moving elements between stacks until the sorting is complete.
 *
 * @param a A pointer to the head of stack A.
 * @param b A pointer to the head of stack B.
 */
void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	a_len;
	int	count;

	a_len = stack_len(*a);
	count = 0;
	while (a_len > 3 && !stack_sorted(*a))
	{
		if (count < 2)
			pb(b, a);
		else
		{
			prep_stack_a(*a, *b);
			move_a_to_b(a, b);
		}
		a_len--;
		count++;
	}
	sort_small(a);
	while (*b)
	{
		prep_stack_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
