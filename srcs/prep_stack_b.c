/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 07:25:31 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/31 07:25:31 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Define a function that sets for the current `a` node, its target node from stack `a`
// closest bigger
// if no, min
void    set_target_b(t_stack_node *a, t_stack_node *b)
{
    int             closest_bigger;
    t_stack_node    *curr_a;
    t_stack_node    *target;

    while (b)
    {
        closest_bigger = INT_MAX;
        curr_a = a;
        while (curr_a)
        {
            if (curr_a->value < closest_bigger && curr_a->value > b->value)
            {
                closest_bigger = curr_a->value;
                target = curr_a;
            }
            curr_a = curr_a->next;
        }
        if (closest_bigger == INT_MAX)
            b->target = find_min(a);
        else
            b->target = target;
        b = b->next;
    }
}

//Define a function that prepares the nodes for pushing `b` to `a`
void    prep_stack_b(t_stack_node *a, t_stack_node *b)
{
    current_index(a); //from other .c file
    current_index(b);
    set_target_b(a, b);
}