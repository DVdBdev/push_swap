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
void    set_target_b(t_stack_node *a, t_stack_node *b)
{

}

//Define a function that prepares the nodes for pushing `b` to `a`
void    prep_stack_b(t_stack_node *a, t_stack_node *b)
{
    current_index(a); //from other .c file
    current_index(b);
    set_target_b(a, b);
}