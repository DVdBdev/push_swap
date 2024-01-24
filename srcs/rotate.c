/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 07:26:10 by dvan-den          #+#    #+#             */
/*   Updated: 2024/01/24 12:22:33 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Performs a rotation on the given stack.
 *
 * This function moves the top node of the stack to the end
 * effectively performing a rotation on the stack.
 *
 * @param stack A pointer to the head of the stack.
 */
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

/**
 * @brief Performs a rotation on stack A.
 *
 * This function moves the top node of stack A to the end
 * effectively performing a rotation on stack A.
 *
 * @param a A pointer to the head of stack A.
 */
void	ra(t_stack_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

/**
 * @brief Performs a rotation on stack B.
 *
 * This function moves the top node of stack B to the end
 * effectively performing a rotation on stack B.
 *
 * @param b A pointer to the head of stack B.
 */
void	rb(t_stack_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

/**
 * @brief Performs a rotation on both stack A and stack B.
 *
 * This function moves the top node of both stack A and stack B to the end,
 * effectively performing a rotation on both stacks.
 *
 * @param a A pointer to the head of stack A.
 * @param b A pointer to the head of stack B.
 */
void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
