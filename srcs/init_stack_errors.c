/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:04:09 by dvan-den          #+#    #+#             */
/*   Updated: 2024/01/22 11:33:34 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_valid_integer(const char *str)
{
	int	valid_int;
	int	plus_and_minus;

	plus_and_minus = *str != '+' && *str != '-';
	valid_int = plus_and_minus && !ft_isdigit((unsigned char)*str);
	if (str == NULL || *str == '\0' || valid_int)
		return (0);
	if (*str == '+' || *str == '-')
	{
		str++;
		if (!ft_isdigit((unsigned char)*str))
			return (0);
	}
	while (*str)
	{
		if (!ft_isdigit((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}

int	has_duplicate(t_stack_node *stack, int n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->value == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*curr;

	if (!stack)
		return ;
	curr = *stack;
	while (curr)
	{
		temp = curr->next;
		curr->value = 0;
		free(curr);
		curr = temp;
	}
	*stack = NULL;
}

void	handle_error_and_exit(t_stack_node **stack, const char *message)
{
	free_stack(stack);
	ft_printf("Error\n", message);
	exit(1);
}
