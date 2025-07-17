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

/*@brief: find the index of the smallest int in the array
 */
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

/* @brief: scan stack a from the top to find the first number belongs to a chunk
 * @return: the index of the number
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
