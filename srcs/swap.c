/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 06:54:38 by dvan-den          #+#    #+#             */
/*   Updated: 2024/01/22 12:30:55 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Swaps the top two elements of the given stack.
 *
 * This function swaps the positions of the top two elements in the
 * linked list, effectively performing a swap operation.
 *
 * @param stack A pointer to the head of the stack.
 */
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

/**
 * @brief Swaps the top two elements of stack A.
 *
 * This function swaps the positions of the top two elements in stack A.
 *
 * @param a A pointer to the head of stack A.
 */
void	sa(t_stack_node **a)
{
	swap_top_two(a);
	ft_printf("sa\n");
}

/**
 * @brief Swaps the top two elements of stack B.
 *
 * This function swaps the positions of the top two elements in stack B.
 *
 * @param b A pointer to the head of stack B.
 */
void	sb(t_stack_node **b)
{
	swap_top_two(b);
	ft_printf("sb\n");
}

/**
 * @brief Swaps the top two elements of both stack A and stack B.
 *
 * This function swaps the positions of the top two elements in both stack
 * A and stack B.
 *
 * @param a A pointer to the head of stack A.
 * @param b A pointer to the head of stack B.
 */
void	ss(t_stack_node **a, t_stack_node **b)
{
	swap_top_two(a);
	swap_top_two(b);
	ft_printf("ss\n");
}
