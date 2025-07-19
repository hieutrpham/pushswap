/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:04:27 by trupham           #+#    #+#             */
/*   Updated: 2025/07/17 17:31:43 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*@brief: find the index of the max int in the array
 */
int find_max(t_stack *stack)
{
	int max_index;
	int max_value;
	int i;

	if (is_stack_empty(stack))
		return -1;
	max_index = stack->top;
	max_value = stack->arr[max_index];
	i = max_index + 1;
	while (i < stack->size)
	{
		if (stack->arr[i] > max_value)
		{
			max_index = i;
			max_value = stack->arr[i];
		}
		i++;
	}
	return max_index;
}

int find_min(t_stack *stack)
{
	int min_index;
	int min_value;
	int i;

	if (is_stack_empty(stack))
		return -1;
	min_index = stack->top;
	min_value = stack->arr[min_index];
	i = min_index + 1;
	while (i < stack->size)
	{
		if (stack->arr[i] < min_value)
		{
			min_index = i;
			min_value = stack->arr[i];
		}
		i++;
	}
	return min_index;
}

/* @brief: find the correct index of a number in the sorted array
 * @return: index in sorted array
 */
int find_sorted_index(t_stack *stack, int num)
{
	int i = 0;

	while (i < stack->size)
	{
		if (stack->sorted_arr[i] == num)
			return i;
		i++;
	}
	return i;
}

/*@brief: find the closest but smaller in stack b than the number on top of stack A
 *@return: index of the number found
 */
int find_closest_smaller(t_stack *stack_a, t_stack *stack_b)
{
	int value_a;
	int dist;
	int top_b = stack_b->top;
	int index = -1;

	value_a = stack_a->arr[stack_a->top];
	while (value_a < stack_b->arr[top_b])
		top_b++;
	dist = value_a - stack_b->arr[top_b];
	ft_printf("distance: %d\n", dist);
	while (top_b < stack_b->size)
	{
		ft_printf("value top a: %d\n", value_a);
		ft_printf("value top b: %d\n", stack_b->arr[top_b]);
		if (value_a - stack_b->arr[top_b] <= dist && value_a > stack_b->arr[top_b])
		{
			dist = value_a - stack_b->arr[top_b];
			index = top_b;
		}
		top_b++;
	}
	return index;
}

/* @brief: scan stack a from the top to find the first number belongs to a chunk
 * @return: the index of the number or -1 if not found
*/
int scan_top(t_stack *stack, int start, int end)
{
	int i = stack->top;
	int tmp_start = start;

	while (i < stack->size)
	{
		tmp_start = start;
		while (tmp_start <= end)
		{
			if (stack->arr[i] == stack->sorted_arr[tmp_start])
				return i;
			tmp_start++;
		}
		i++;
	}
	return -1;
}

int scan_bottom(t_stack *stack, int start, int end)
{
	int i = stack->size;
	int tmp_start = start;

	while (i > stack->top)
	{
		tmp_start = start;
		while (tmp_start <= end)
		{
			if (stack->arr[i] == stack->sorted_arr[tmp_start])
				return i;
			tmp_start++;
		}
		i--;
	}
	return -1;
}

void prep_stack_b(t_stack *stack_a, i_list **list, t_stack *stack_b)
{
	int max_b = stack_b->arr[find_max(stack_b)];
	int min_b = stack_b->arr[find_min(stack_b)];
	int top_a = stack_a->arr[stack_a->top];
	int closest = stack_b->top;

	ft_printf("max b: %d, min b: %d, top a: %d\n", max_b, min_b, top_a);
	if (is_stack_empty(stack_b) || stack_b->len < 2)
		return;
	if (top_a > max_b || top_a < min_b)
	{
		if (max_b <= (stack_b->size + stack_b->top) / 2)
			do_rotate(stack_b, list, rb, max_b - stack_b->top);
		else
			do_rotate(stack_b, list, rrb, stack_b->size - max_b);
	}
	else
	{
		closest = find_closest_smaller(stack_a, stack_b);
		ft_printf("DEBUG: closest smaller index and value: %d %d\n", closest, stack_b->arr[closest]);
		if (closest <= (stack_b->size + stack_b->top) / 2)
			do_rotate(stack_b, list, rb, closest - stack_b->top);
		else
			do_rotate(stack_b, list, rrb, stack_b->size - closest);
	}
	print_stack(stack_b, 'b');
}
