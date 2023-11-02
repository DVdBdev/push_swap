/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:45:48 by dvan-den          #+#    #+#             */
/*   Updated: 2023/11/02 11:20:36 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_a(a, cheapest_node);
	prep_b(b, cheapest_node->target);
	pb(b, a);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_a(a, (*b)->target);
	pa(a, b);
}

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
