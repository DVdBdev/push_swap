/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:20:12 by dvan-den          #+#    #+#             */
/*   Updated: 2024/04/10 16:06:25 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Reverses the order of nodes in a stack.
 * 
 * This function reverses the order of nodes in the given stack.
 * 
 * @param stack A pointer to the pointer to the head of the stack.
 */
static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

/**
 * @brief Reverses the order of nodes in stack 'a'.
 * 
 * This function reverses the order of nodes in stack 'a'.
 * 
 * @param a A pointer to the pointer to the head of stack 'a'.
 */
void	rra(t_stack_node **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

/**
 * @brief Reverses the order of nodes in stack 'b'.
 * 
 * This function reverses the order of nodes in stack 'b'.
 * 
 * @param b A pointer to the pointer to the head of stack 'b'.
 */
void	rrb(t_stack_node **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

/**
 * @brief Reverses the order of nodes in both stack 'a' and stack 'b'.
 * 
 * This function reverses the order of nodes in both stack 'a' and stack 'b'.
 * 
 * @param a A pointer to the pointer to the head of stack 'a'.
 * @param b A pointer to the pointer to the head of stack 'b'.
 */
void	rrr(t_stack_node **a, t_stack_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}
