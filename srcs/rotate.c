/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 07:26:10 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/30 07:36:08 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*top_node;
	t_stack_node	*last_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	top_node = *stack;
	last_node = find_last(*stack);
	*stack = top_node->next;
	(*stack)->prev = NULL;
	last_node->next = top_node;
	top_node->prev = last_node;
	top_node->next = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	printf("ra\n");
}

void	rb(t_stack_node **b)
{
	rotate(b);
	printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	printf("rr\n");
}
