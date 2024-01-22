/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:37:21 by dvan-den          #+#    #+#             */
/*   Updated: 2023/11/02 11:50:43 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>
#include <string.h>

void	free_string_array(char **str_array)
{
	int	i;

	if (str_array == NULL)
		return ;
	i = 0;
	while (str_array[i] != NULL)
	{
		free(str_array[i]);
		i++;
	}
	free(str_array);
}

void	display_stack(t_stack_node *stack)
{
	printf("Stack contents: ");
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*input_str;
	char			**splitted_str;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (0);
	else if (argc >= 2)
	{
		input_str = argv_to_string(argv);
		if (!input_str)
		{
			ft_printf("Error: argv_to_string failed\n");
			return (0);
		}
		splitted_str = ft_split(input_str, ' ');
		free(input_str);
		init_stack_from_str(&a, splitted_str);
		if (!stack_sorted(a))
		{
			if (stack_len(a) == 2)
				sa(&a);
			else if (stack_len(a) == 3)
				sort_small(&a);
			else
				sort_stacks(&a, &b);
		}
	}
	//display_stack(a);
	free_stack(&a);
	return (0);
}
