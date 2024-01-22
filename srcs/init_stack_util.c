/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:08:34 by dvan-den          #+#    #+#             */
/*   Updated: 2024/01/22 10:41:52 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_strcat(char *s1, const char *s2)
{
	while (*s1 != '\0')
	{
		s1++;
	}
	while (*s2 != '\0')
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
}

static int	calculate_total_length(char **argv)
{
	int		i;
	size_t	curr_len;
	int		total_length;

	i = 0;
	total_length = 0;
	while (argv[i] != NULL)
	{
		curr_len = ft_strlen(argv[i]);
		if (curr_len == 0)
		{
			ft_printf("Error: Empty string in argv\n");
			return (0);
		}
		total_length += curr_len + 1;
		i++;
	}
	return (total_length);
}

char	*argv_to_string(char **argv)
{
	char	*result;
	int		total_length;
	int		i;

	result = NULL;
	if (argv != NULL)
	{
		total_length = calculate_total_length(argv);
		if (total_length == 0)
			return (NULL);
		result = (char *)malloc(total_length + 1);
		if (result != NULL)
		{
			result[0] = '\0';
			i = 1;
			while (argv[i] != NULL)
			{
				ft_strcat(result, argv[i]);
				if (argv[i + 1] != NULL)
					ft_strcat(result, " ");
				i++;
			}
		}
	}
	return (result);
}

long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || (*s >= '\t' && *s <= '\r'))
		s++;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	return (result * sign);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
