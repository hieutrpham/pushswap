/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 07:45:38 by trupham           #+#    #+#             */
/*   Updated: 2025/07/10 21:20:29 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdbool.h>
#include "../libft/libft.h"
#include <limits.h>

/* @brief: stack to manage the int array
 * @param: arr is the actual int array
 * @param: initial size of the array. this is read in from argc
 * @param: len is variable to keep track of how many elements currently in array
*/
typedef struct s_stack {
	int size;
	int len;
	int top;
	int *arr;
} t_stack;

typedef struct i_list {
	int num;
	struct i_list *next;
} i_list;

enum {
	sa,
	sb,
	pa,
	pb,
	ra,
	rb,
	rra,
	rrb,
};

/**********************stack_op.c**********************
* stack operation
******************************************************/
void swap(t_stack *stack, i_list **list, int op);
void push(t_stack *from_stack, t_stack *to_stack, i_list **list,  int op);
void rotate(t_stack *stack, i_list **list, int op);
void reverse_rotate(t_stack *stack, i_list **list, int op);
/************************parser.c**********************
* helper functions to handle parsing
******************************************************/
t_stack *build_stack(int ac, char **av);
t_stack *build_empty_stack(unsigned int size);
void destroy_stack(t_stack *stack);

/************************errors.c**********************
* helper functions to handle errors
******************************************************/
void check_input(int ac, char **av);
void check_dup(t_stack *stack);

/************************utils.c**********************
* others helper functions i don't know where to put
******************************************************/
void exit_error();
bool is_stack_empty(t_stack *stack);
bool is_stack_full(t_stack *stack);
void store_op(i_list **list, int op);
#endif
