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
# include "../Libft/libft.h"

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

// init_stack_errors.c
int				is_valid_integer(const char *str);
int				has_duplicate(t_stack_node *stack, int n);
void			free_stack(t_stack_node **stack);
void			handle_error_and_exit(t_stack_node **stack, const char *m);

// init_stack_util.c
char			*argv_to_string(char **argv);
long			ft_atol(const char *s);
t_stack_node	*find_last(t_stack_node *stack);

// init_stack.c
void			init_stack_from_str(t_stack_node **stack, char **splitted_str);

// prep_stack_a.c
void			current_index(t_stack_node *stack);
void			prep_stack_a(t_stack_node *a, t_stack_node *b);

// prep_stack_b.c
void			prep_stack_b(t_stack_node *a, t_stack_node *b);

// prep_util.c
t_stack_node	*find_max(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);

// push.c
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);

// swap.c
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

// rotate.c
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

// reverse_rotate.c
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

// sort_stacks_util.c
t_stack_node	*get_cheapest(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
void			rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest);
void			rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest);

// sort_stacks_util2.c
void			prep_a(t_stack_node **a, t_stack_node *top);
void			prep_b(t_stack_node **b, t_stack_node *top);

// sort_stacks.c
void			sort_small(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);

// main.c
void			free_string_array(char **str_array);

#endif