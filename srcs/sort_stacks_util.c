/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:10:28 by dvan-den          #+#    #+#             */
/*   Updated: 2023/11/02 11:21:02 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

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
