/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 07:09:54 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/31 07:09:54 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// update stack->index and stack->above_median for each position
void    current_index(t_stack_node *stack)
{
    int i;
    int median;

    i = 0;
    if (!stack)
        return ;
    median = stack_len(stack) / 2;
    while (stack)
    {
        stack->index = i;
    }
}

// Find 'a' node's target in stack 'b' for each position
void    set_target_a(t_stack_node *a, t_stack_node *b)
{

}

// Define a function that analyses the cost of the `a` node 
// along with it's target `b` node, which is the sum of the 
// number of instructions for both 
// the nodes to rotate to the top of their stacks
void    cost_analysis_a(t_stack_node *a, t_stack_node *b)
{

}

// Define a function that sets a node's `cheapest` attribute as `true` or `false`
void    set_cheapest(t_stack_node *stack)
{

}

void    prep_stack_a(t_stack_node *a, t_stack_node *b)
{
    current_index(a);
    current_index(b);
    set_target_a(a, b);
    cost_analysis_a(a, b);
    set_cheapest(a);
}