/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 06:54:38 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/30 07:12:33 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	swap_top_two(t_stack_node **stack)
{
	t_stack_node	*top_node;
	t_stack_node	*second_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	top_node = *stack;
	second_node = top_node->next;
	top_node->next = second_node->next;
	second_node->next = top_node;
	top_node->prev = second_node;
	second_node->prev = NULL;
	*stack = second_node;
}

void	sa(t_stack_node **a)
{
	swap_top_two(a);
	printf("sa\n");
}

void	sb(t_stack_node **b)
{
	swap_top_two(b);
	printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap_top_two(a);
	swap_top_two(b);
	printf("ss\n");
}
