/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:11:41 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/30 20:19:46 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last_node = find_last(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	(*stack)->prev = last_node;
	*stack = last_node;
}

void	rra(t_stack_node **a)
{
	reverse_rotate(a);
	printf("rra\n");
}

void	rrb(t_stack_node **b)
{
	reverse_rotate(b);
	printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	printf("rrr\n");
}
