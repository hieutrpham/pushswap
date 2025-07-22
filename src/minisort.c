/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:23:42 by trupham           #+#    #+#             */
/*   Updated: 2025/07/22 15:35:00 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sort_two(t_stack *stack, t_node **list)
{
	if (!is_sorted(stack->arr, stack->size))
		swap(stack, list, sa);
}

void sort_three(t_stack *stack, t_node **list)
{
	int max;
	int min;

	min = find_min(stack);
	max = find_max(stack);
	if (is_sorted(stack->arr, stack->size))
		return;
	if (max == stack->size - 1)
		swap(stack, list, sa);
	else if (max == stack->top && min == stack->size - 1)
	{
		swap(stack, list, sa);
		rotate(stack, list, rra);
	}
	else if (max == stack->top && min != stack->size - 1)
		rotate(stack, list, ra);
	else if (min == stack->top)
	{
		swap(stack, list, sa);
		rotate(stack, list, ra);
	}
	else if (min == stack->size - 1 && max != stack->top)
		rotate(stack, list, rra);
}

void sort_five(t_stack *stack_a, t_stack *stack_b, t_node **list)
{
	int min;
	int num_ra;
	int num_rra;

	min = find_min(stack_a);
	while (stack_a->len > 3)
	{
		num_ra = min - stack_a->top;
		num_rra = stack_a->size - min;
		if (num_ra <= num_rra)
			do_rotate(stack_a, list, ra, num_ra);
		else
			do_rotate(stack_a, list, rra, num_rra);
		push(stack_a, stack_b, list, pb);
		min = find_min(stack_a);
	}
	sort_three(stack_a, list);
	while (!is_stack_empty(stack_b))
		push(stack_b, stack_a, list, pa);
	return;
}
