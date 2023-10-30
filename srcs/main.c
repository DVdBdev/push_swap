/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:37:21 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/30 07:39:31 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>
#include <string.h>

void	display_string_array(char **str_array)
{
	int	i;

	if (str_array == NULL)
	{
		printf("Input array is NULL\n");
		return ;
	}
	printf("[");
	i = 0;
	while (str_array[i] != NULL)
	{
		printf("\"%s\", ", str_array[i]);
		i++;
	}
	printf("]\n");
}

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

void	display_stack(const t_stack_node *stack)
{
	printf("Stack contents: ");
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

void	display_stacks(const t_stack_node *a, const t_stack_node *b)
{
	printf("a: ");
	while (a)
	{
		printf("%d ", a->value);
		a = a->next;
	}
	printf("\n");
	printf("b: ");
	while (b)
	{
		printf("%d ", b->value);
		b = b->next;
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
	{
		printf("Error: no input data\n");
		return (0);
	}
	else if (argc >= 2)
	{
		input_str = argv_to_string(argv);
		if (!input_str)
		{
			printf("Error: argv_to_string failed\n");
			return (0);
		}
		splitted_str = ft_split(input_str, ' ');
		free(input_str);
		init_stack_from_str(&a, splitted_str);
		display_stacks(a, b);
		rr(&a, &b);
		display_stacks(a, b);
		rr(&a, &b);
		display_stacks(a, b);
		rr(&a, &b);
		display_stacks(a, b);
		rr(&a, &b);
		display_stacks(a, b);
		free_stack(&a);
	}
}
