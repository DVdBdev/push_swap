/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:46:28 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/30 07:19:16 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	printf("pb\n");
}
