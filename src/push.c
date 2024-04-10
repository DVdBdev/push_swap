/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:20:09 by dvan-den          #+#    #+#             */
/*   Updated: 2024/04/10 16:04:59 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Pushes the top node from source stack to destination stack.
 * 
 * This function moves the top node from the source stack to the
 * destination stack.
 * 
 * @param dst A pointer to the pointer to the head of the destination stack.
 * @param src A pointer to the pointer to the head of the source stack.
 */
static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

/**
 * @brief Pushes the top node from stack 'b' to stack 'a'.
 * 
 * This function moves the top node from stack 'b' to stack 'a'.
 * 
 * @param a A pointer to the pointer to the head of stack 'a'.
 * @param b A pointer to the pointer to the head of stack 'b'.
 */
void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	ft_printf("pa\n");
}

/**
 * @brief Pushes the top node from stack 'a' to stack 'b'.
 * 
 * This function moves the top node from stack 'a' to stack 'b'.
 * 
 * @param b A pointer to the pointer to the head of stack 'b'.
 * @param a A pointer to the pointer to the head of stack 'a'.
 */
void	pb(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	ft_printf("pb\n");
}
