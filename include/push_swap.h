/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 07:45:38 by trupham           #+#    #+#             */
/*   Updated: 2025/07/22 15:01:02 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

/* @brief: stack to manage the int array
 * @param: arr is the actual int array
 * @param: initial size of the array. this is read in from argc
 * @param: len is variable to keep track of how many elements currently in array
 */
typedef struct s_stack
{
	int				size;
	int				len;
	int				top;
	int				chunk_size;
	int				*arr;
	int				*sorted_arr;
}					t_stack;

typedef struct i_list
{
	int				num;
	struct i_list	*next;
}					t_node;

enum
{
	sa,
	sb,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
};

/**********************stack_op.c**********************
 * stack operation
 ******************************************************/
void				swap(t_stack *stack, t_node **list, int op);
void				push(t_stack *from_stack, t_stack *to_stack, t_node **list,
						int op);
void				rotate(t_stack *stack, t_node **list, int op);
void				reverse_rotate(t_stack *stack, t_node **list, int op);
void				do_rotate(t_stack *stack, t_node **list, int op,
						int num_move);

/************************parser.c**********************
 * helper functions to handle parsing
 ******************************************************/
t_stack				*build_stack(int ac, char **av);
t_stack				*build_empty_stack(unsigned int size);

/************************errors.c**********************
 * helper functions to handle errors
 ******************************************************/
void				check_input(int ac, char **av);
void				check_dup(t_stack *stack);

/************************algo.c************************
 * functions related to algorithm
 ******************************************************/
void				insert_sort(t_stack *stack_a, t_stack *stack_b,
						t_node **list, int chunk_size);
void				sort_b_and_pa(t_stack *stack_a, t_stack *stack_b,
						t_node **list);
void				post_insert_prep(t_stack *stack_a, t_stack *stack_b,
						t_node **list);

/************************algo_helper.c**********************
 * helper functions related to algorithm
 ***********************************************************/
int					find_min(t_stack *stack);
int					find_max(t_stack *stack);
int					scan_top(t_stack *stack, int start, int end);
int					scan_bottom(t_stack *stack, int start, int end);
int					find_closest_smaller(t_stack *stack_a, t_stack *stack_b);

/************************utils.c***********************
 * others helper functions i don't know where to put
 ******************************************************/
void				exit_error(void);
bool				is_stack_empty(t_stack *stack);
void				store_op(t_node **list, int op);
void				free_data(t_stack *stack_a, t_stack *stack_b, t_node *list);
void				destroy_stack(t_stack *stack);

/************************post_algo.c**********************
 * print instructions and optimization to eliminate redundance instruction
 ********************************************************/
void				print_list(t_node *list);
void				print_count(int count_ra, int count_rb, int op);

/************************tuning.c**********************
 * print instructions and optimization to eliminate redundance instruction
 ********************************************************/
int					tune_ra_rb(t_node **list);
int					tune_rra_rrb(t_node **list);

/************************minisort.c**********************
 * print instructions and optimization to eliminate redundance instruction
 ********************************************************/
void				sort_two(t_stack *stack, t_node **list);
void				sort_three(t_stack *stack, t_node **list);
void				sort_five(t_stack *stack_a, t_stack *stack_b,
						t_node **list);
#endif
