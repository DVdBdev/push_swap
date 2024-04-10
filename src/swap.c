/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:20:25 by dvan-den          #+#    #+#             */
/*   Updated: 2024/04/10 16:18:34 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Swaps the positions of the top two nodes in a stack.
 * 
 * This function swaps the positions of the top two nodes in the given
 * stack.
 * 
 * @param head A pointer to the pointer to the head of the stack.
 */
static void	swap(t_stack_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

/**
 * @brief Swaps the positions of the top two nodes in stack 'a'.
 * 
 * This function swaps the positions of the top two nodes in stack 'a'.
 * 
 * @param a A pointer to the pointer to the head of stack 'a'.
 */
void	sa(t_stack_node **a)
{
	swap(a);
	ft_printf("sa\n");
}

/**
 * @brief Swaps the positions of the top two nodes in stack 'b'.
 * 
 * This function swaps the positions of the top two nodes in stack 'b'.
 * 
 * @param b A pointer to the pointer to the head of stack 'b'.
 */
void	sb(t_stack_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

/**
 * @brief Swaps the positions of the top two nodes in both stack 'a' and
 * stack 'b'.
 * 
 * This function swaps the positions of the top two nodes in both stack 'a'
 * and stack 'b'.
 * 
 * @param a A pointer to the pointer to the head of stack 'a'.
 * @param b A pointer to the pointer to the head of stack 'b'.
 */
void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
