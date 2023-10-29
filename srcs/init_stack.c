/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:03:12 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/29 19:03:12 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!stack)
		return (0);
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (0);
	new_node->next = NULL;
	new_node->value = n;
	if (!(*stack))
	{
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
	return (1);
}

//TODO: ERROR HANDLING IF APPEND NODE FAILS
void	init_stack_from_str(t_stack_node **stack, char **splitted_str)
{
	long	n;
	int		i;

	i = 0;
	while (splitted_str[i])
	{
		if (!is_valid_integer(splitted_str[i]))
			handle_error_and_exit(stack, "Input contains an invalid syntax");
		n = ft_atol(splitted_str[i]);
		if (n > INT_MAX || n < INT_MIN)
			handle_error_and_exit(stack, "Input contains integer overflow");
		if (has_duplicate(*stack, (int)n))
			handle_error_and_exit(stack, "Input contains duplicate");
		append_node(stack, (int)n);
		i++;
	}
	free_string_array(splitted_str);
}
