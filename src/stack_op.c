/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:29:55 by trupham           #+#    #+#             */
/*   Updated: 2025/07/10 22:49:08 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* @brief: swap the top 2 ints
 * @param stack: the stack to swap
 * @param list: the list to store the operations
 * @param op: to indicate which operation
 */
void swap(t_stack *stack, i_list **list, int op)
{
	int tmp;
	int *int_arr;
	int top;

	top = stack->top;
	int_arr = stack->arr;
	if (stack->len >= 2)
	{
		tmp = int_arr[top];
		int_arr[top] = int_arr[top+1];
		int_arr[top + 1] = tmp;
	}
	store_op(list, op);
}

/* @brief: push top element from_stack to_stack
 * @params op: indicate which operation
 */
void push(t_stack *from_stack, t_stack *to_stack, i_list **list,  int op)
{
	int top_value;

	if (is_stack_empty(from_stack))
		return;
	top_value = from_stack->arr[from_stack->top];
	if (is_stack_empty(to_stack))
	{
		to_stack->arr[to_stack->size - 1] = top_value;
		to_stack->top = to_stack->size - 1;
		to_stack->len++;
	}
	else
	{
		to_stack->arr[to_stack->top-- - 1] = top_value;
		to_stack->len++;
	}
	from_stack->top++;
	if (from_stack->top >= from_stack->size)
		from_stack->top = -1;
	from_stack->len--;
	store_op(list, op);
}

void rotate(t_stack *stack, i_list **list, int op)
{
	int top_value;
	int tmp_top;

	if (is_stack_empty(stack))
		return;
	tmp_top = stack->top;
	top_value = stack->arr[tmp_top];
	while (tmp_top < stack->size - 1)
	{
		stack->arr[tmp_top] = stack->arr[tmp_top + 1];
		tmp_top++;
	}
	stack->arr[stack->size - 1] = top_value;
	store_op(list, op);
}

void reverse_rotate(t_stack *stack, i_list **list, int op)
{
	int bottom_value;
	int tmp_bot;

	if (is_stack_empty(stack))
		return;
	tmp_bot = stack->size - 1;
	bottom_value = stack->arr[tmp_bot];
	while (tmp_bot > stack->top)
	{
		stack->arr[tmp_bot] = stack->arr[tmp_bot - 1];
		tmp_bot--;
	}
	stack->arr[stack->top] = bottom_value;
	store_op(list, op);
}
