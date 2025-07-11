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

void swap(t_stack *stack, t_list **list, char c)
{
	int tmp;
	int *int_arr;
	t_list *new_node;

	new_node = NULL;
	int_arr = stack->arr;
	if (stack->size >= 2)
	{
		tmp = int_arr[stack->top];
		int_arr[stack->top] = int_arr[stack->top+1];
		int_arr[stack->top + 1] = tmp;
	}
	if (c == 'a')
	{
		new_node = ft_lstnew("sa");
		ft_lstadd_back(list, new_node);
	}
	else if (c == 'b')
	{
		new_node = ft_lstnew("sb");
		ft_lstadd_back(list, new_node);
	}
}
