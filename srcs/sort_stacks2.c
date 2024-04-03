/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:09:54 by dvan-den          #+#    #+#             */
/*   Updated: 2024/02/05 16:09:54 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	r_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapNode)
{
	while (*b != cheapNode->target_node && *a != cheapNode)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

void	rr_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapNode)
{
	while (*b != cheapNode->target_node && *a != cheapNode)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}
