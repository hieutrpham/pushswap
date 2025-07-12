/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:14:17 by trupham           #+#    #+#             */
/*   Updated: 2025/07/06 15:14:41 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void exit_error()
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

bool is_stack_empty(t_stack *stack)
{
	return stack->top < 0;
}

void store_op(i_list **list, int op)
{
	i_list *new_node;
	i_list *last;

	new_node = malloc(sizeof(i_list));
	if (!new_node)
		return;
	new_node->num = op;
	new_node->next = NULL;
	if (!*list)
	{
		*list = new_node;
		return;
	}
	last = *list;
	while (last->next)
		last = last->next;
	last->next = new_node;
}
