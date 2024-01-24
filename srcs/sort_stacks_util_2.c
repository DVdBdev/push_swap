/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_util_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:20:20 by dvan-den          #+#    #+#             */
/*   Updated: 2024/01/24 11:20:20 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Prepares stack A to move a specific node to the top.
 *
 * This function rotates stack A until the specified node
 * (marked as the top) is at the top of the stack. The direction
 * of rotation depends on whether the node is above or below the median.
 *
 * @param a A pointer to the head of stack A.
 * @param top A pointer to the node that needs to be moved to the top.
 */
void	prep_a(t_stack_node **a, t_stack_node *top)
{
	while (*a != top)
	{
		if (top->above_median)
			ra(a);
		else
			rra(a);
	}
}

/**
 * @brief Prepares stack B to move a specific node to the top.
 *
 * This function rotates stack B until the specified node
 * (marked as the top) is at the top of the stack. The direction of
 * rotation depends on whether the node is above or below the median.
 *
 * @param b A pointer to the head of stack B.
 * @param top A pointer to the node that needs to be moved to the top.
 */
void	prep_b(t_stack_node **b, t_stack_node *top)
{
	while (*b != top)
	{
		if (top->above_median)
			rb(b);
		else
			rrb(b);
	}
}
