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

/*@brief: find the closest but smaller in stack b than the number on top of stack A
 */
int find_closest_smaller(t_stack *stack_a, t_stack *stack_b)
{
	int num_a;
	int i = 0;
	int res = 0;

	num_a = stack_a->arr[stack_a->top];
	while (i < stack_b->size)
	{
		if (stack_b->arr[i] < num_a)
			res = i;
		else
			break;
		i++;
	}
	return res;
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

void prep_stack_b(t_stack *stack_a, t_stack *stack_b)
{

}
