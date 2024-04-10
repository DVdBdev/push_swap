/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:20:19 by dvan-den          #+#    #+#             */
/*   Updated: 2024/04/10 16:11:56 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Rotates both stack 'a' and stack 'b' until the cheapest node is
 * positioned correctly.
 * 
 * This function rotates both stack 'a' and stack 'b' until the cheapest
 * node is positioned correctly to be pushed from stack 'b' to stack 'a'.
 * 
 * @param a A pointer to the pointer to the head of stack 'a'.
 * @param b A pointer to the pointer to the head of stack 'b'.
 * @param cheapest_node A pointer to the cheapest node in stack 'a'.
 */
void	rot_both(t_stack_node **a,
					t_stack_node **b,
					t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

/**
 * @brief Reverse rotates both stack 'a' and stack 'b' until the cheapest
 * node is positioned correctly.
 * 
 * This function reverse rotates both stack 'a' and stack 'b' until the
 * cheapest node is positioned correctly to be pushed from stack 'b' to
 * stack 'a'.
 * 
 * @param a A pointer to the pointer to the head of stack 'a'.
 * @param b A pointer to the pointer to the head of stack 'b'.
 * @param cheapest_node A pointer to the cheapest node in stack 'a'.
 */
void	rrot_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

/**
 * @brief Moves the top node from stack 'a' to stack 'b'.
 * 
 * This function moves the top node from stack 'a' to stack 'b'.
 * 
 * @param a A pointer to the pointer to the head of stack 'a'.
 * @param b A pointer to the pointer to the head of stack 'b'.
 */
void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rot_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rrot_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

/**
 * @brief Moves the top node from stack 'b' to stack 'a'.
 * 
 * This function moves the top node from stack 'b' to stack 'a'.
 * 
 * @param a A pointer to the pointer to the head of stack 'a'.
 * @param b A pointer to the pointer to the head of stack 'b'.
 */
void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

/**
 * @brief Moves the node with the minimum value to the top of stack 'a'.
 * 
 * This function rotates stack 'a' until the node with the minimum value
 * is positioned at the top.
 * 
 * @param a A pointer to the pointer to the head of stack 'a'.
 */
void	min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}
