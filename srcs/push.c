/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:46:28 by dvan-den          #+#    #+#             */
/*   Updated: 2024/01/24 12:06:29 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Pushes the top node from one stack to another.
 *
 * This function moves the top node from the source stack to the
 * top of the destination stack.
 *
 * @param dst A pointer to the head of the destination stack.
 * @param src A pointer to the head of the source stack.
 */
static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*pushed_node;

	if (*src == NULL)
	{
		return ;
	}
	pushed_node = *src;
	*src = pushed_node->next;
	if (*src)
		(*src)->prev = NULL;
	pushed_node->prev = NULL;
	pushed_node->next = NULL;
	if (*dst)
	{
		(*dst)->prev = pushed_node;
		pushed_node->next = *dst;
		*dst = pushed_node;
	}
	else
		*dst = pushed_node;
}

/**
 * @brief Pushes the top node from stack B to stack A.
 *
 * This function moves the top node from stack B to the top of stack A.
 *
 * @param a A pointer to the head of stack A.
 * @param b A pointer to the head of stack B.
 */
void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	ft_printf("pa\n");
}

/**
 * @brief Pushes the top node from stack A to stack B.
 *
 * This function moves the top node from stack A to the top of stack B.
 *
 * @param b A pointer to the head of stack B.
 * @param a A pointer to the head of stack A.
 */
void	pb(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	ft_printf("pb\n");
}
