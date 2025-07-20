/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:04:27 by trupham           #+#    #+#             */
/*   Updated: 2025/07/20 20:58:48 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void prep_stack_b(t_stack *stack_a, i_list **list, t_stack *stack_b)
{
	int max_b;
	int min_b;
	int top_a;
	int closest;

	closest = stack_b->top;
	top_a = stack_a->top;
	min_b = find_min(stack_b);
	max_b = find_max(stack_b);
	if (is_stack_empty(stack_b) || stack_b->len < 2)
		return;
	if (stack_a->arr[top_a] > stack_b->arr[max_b] ||
		stack_a->arr[top_a] < stack_b->arr[min_b])
	{
		if (max_b <= (stack_b->size + stack_b->top) / 2)
			do_rotate(stack_b, list, rb, max_b - stack_b->top);
		else
			do_rotate(stack_b, list, rrb, stack_b->size - max_b);
	}
	else
	{
		closest = find_closest_smaller(stack_a, stack_b);
		if (closest <= (stack_b->size + stack_b->top) / 2)
			do_rotate(stack_b, list, rb, closest - stack_b->top);
		else
			do_rotate(stack_b, list, rrb, stack_b->size - closest);
	}
}
