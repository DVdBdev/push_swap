/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:06:41 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/29 22:06:41 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <limits.h>
# include <stdio.h>
# include "../Libft/libft.h"

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

void			ft_strcat(char *s1, const char *s2);
char			*argv_to_string(char **argv);
long			ft_atol(const char *s);
t_stack_node	*find_last(t_stack_node *stack);
int				is_valid_integer(const char *str);
int				has_duplicate(t_stack_node *stack, int n);
void			free_stack(t_stack_node **stack);
void			handle_error_and_exit(t_stack_node **stack, const char *m);
int				append_node(t_stack_node **stack, int n);
void			init_stack_from_str(t_stack_node **stack, char **splitted_str);
void			free_string_array(char **str_array);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

#endif