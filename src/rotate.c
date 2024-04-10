/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:20:16 by dvan-den          #+#    #+#             */
/*   Updated: 2024/04/10 16:19:04 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Rotates the nodes in a stack.
 * 
 * This function rotates the nodes in the given stack by moving the top
 * node to the bottom.
 * 
 * @param stack A pointer to the pointer to the head of the stack.
 */
static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

/**
 * @brief Rotates the nodes in stack 'a'.
 * 
 * This function rotates the nodes in stack 'a' by moving the top node to
 * the bottom.
 * 
 * @param a A pointer to the pointer to the head of stack 'a'.
 */
void	ra(t_stack_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

/**
 * @brief Rotates the nodes in stack 'b'.
 * 
 * This function rotates the nodes in stack 'b' by moving the top node to
 * the bottom.
 * 
 * @param b A pointer to the pointer to the head of stack 'b'.
 */
void	rb(t_stack_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

/**
 * @brief Rotates the nodes in both stack 'a' and stack 'b'.
 * 
 * This function rotates the nodes in both stack 'a' and stack 'b' by
 * moving the top node to the bottom.
 * 
 * @param a A pointer to the pointer to the head of stack 'a'.
 * @param b A pointer to the pointer to the head of stack 'b'.
 */
void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
