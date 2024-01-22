/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_util2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:43:43 by dvan-den          #+#    #+#             */
/*   Updated: 2024/01/20 16:43:43 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
