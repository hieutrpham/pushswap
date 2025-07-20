/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:03:10 by trupham           #+#    #+#             */
/*   Updated: 2025/07/20 21:03:30 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void print_stack(t_stack *stack, int c)
{
	if (is_stack_empty(stack))
		return;
	if (c == 'a')
		ft_printf("===stack a===\n");
	else
		ft_printf("===stack b===\n");
	for (int i = stack->top; i < stack->size; i++)
		ft_printf("index %d: %d\n", i, stack->arr[i]);
	ft_printf("\n");
}

void print_list(i_list *list)
{
	while (list)
	{
		if (list->num == sa)
			ft_printf("sa\n");
		if (list->num == sb)
			ft_printf("sb\n");
		if (list->num == pa)
			ft_printf("pa\n");
		if (list->num == pb)
			ft_printf("pb\n");
		if (list->num == ra)
			ft_printf("ra\n");
		if (list->num == rra)
			ft_printf("rra\n");
		if (list->num == rb)
			ft_printf("rb\n");
		if (list->num == rrb)
			ft_printf("rrb\n");
		list = list->next;
	}
}

