/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 07:25:31 by dvan-den          #+#    #+#             */
/*   Updated: 2024/01/24 12:21:57 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Sets the target element in stack A for each element in stack B.
 *
 * This function determines the target element in stack A for each
 * element in stack B.
 *
 * @param a A pointer to the head of stack A.
 * @param b A pointer to the head of stack B.
 */
static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	int				closest_bigger;
	t_stack_node	*curr_a;
	t_stack_node	*target;

	while (b)
	{
		closest_bigger = INT_MAX;
		curr_a = a;
		while (curr_a)
		{
			if (curr_a->value < closest_bigger && curr_a->value > b->value)
			{
				closest_bigger = curr_a->value;
				target = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (closest_bigger == INT_MAX)
			b->target = find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

/**
 * @brief Prepares stack B for further processing in the algorithm.
 *
 * This function prepares stack B by assigning indices and determining
 * targets in stack A.
 *
 * @param a A pointer to the head of stack A.
 * @param b A pointer to the head of stack B.
 */
void	prep_stack_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
