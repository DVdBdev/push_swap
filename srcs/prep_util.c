/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:42:45 by dvan-den          #+#    #+#             */
/*   Updated: 2023/11/02 09:42:45 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack_node	*find_max(t_stack_node *stack)
{
    int				max;
    t_stack_node	*max_node;
	if (!stack)
		return (NULL);
	max = INT_MIN;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack_node	*find_min(t_stack_node *stack)
{
    int				min;
    t_stack_node	*min_node;
	if (!stack)
		return (NULL);
	min = INT_MAX;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

int	stack_len(t_stack_node *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}