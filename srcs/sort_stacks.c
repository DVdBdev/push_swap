/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:45:48 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/31 05:45:48 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    sort_stacks(t_stack_node **a, t_stack_node **b)
{
    int a_len;

    a_len = stack_len(*a);
    if (a_len > 3 && !stack_sorted(*a)) //If stack `a` has more than three nodes and aren't sorted
    {
        pb(b, a);
        a_len--;
    }
    if (a_len > 3 && !stack_sorted(*a)) //If stack `a` still has more than three nodes and aren't sorted
    {
        pb(b, a);
        a_len--;
    }
    while (a_len > 3 && !stack_sorted(*a)) //If stack `a` still has more than three nodes and aren't sorted
    {
        prep_stack_a(*a, *b); //Iniate all nodes from both stacks
        move_a(a, b); //Move the cheapest `a` nodes into a sorted stack `b`, until three nodes are left in stack `a`
        a_len--;
    }
    sort_three(a);
    while (*b) //Until the end of stack `b` is reached
    {
        prep_stack_b(*a, *b);//Initiate all nodes from both stacks
        move_b(a, b);//Move all `b` nodes back to a sorted stack `a`
    }
    current_index(*a);//Refresh the current position of stack `a`
    min_on_top(a);//Ensure smallest number is on top
}