/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:11:41 by dvan-den          #+#    #+#             */
/*   Updated: 2024/01/24 12:07:22 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Performs a reverse rotation on the given stack.
 *
 * This function moves the last node of the stack to the front,
 * effectively performing a reverse rotation on the stack.
 *
 * @param stack A pointer to the head of the stack.
 */
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

/**
 * @brief Performs a reverse rotation on stack A.
 *
 * This function moves the last node of stack A to the front,
 * effectively performing a reverse rotation on stack A.
 *
 * @param a A pointer to the head of stack A.
 */
void	rra(t_stack_node **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

/**
 * @brief Performs a reverse rotation on stack B.
 *
 * This function moves the last node of stack B to the front
 * effectively performing a reverse rotation on stack B.
 *
 * @param b A pointer to the head of stack B.
 */
void	rrb(t_stack_node **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

/**
 * @brief Performs a reverse rotation on both stack A and stack B.
 *
 * This function moves the last node of both stack A and stack B to the front,
 * effectively performing a reverse rotation on both stacks.
 *
 * @param a A pointer to the head of stack A.
 * @param b A pointer to the head of stack B.
 */
void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
