/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:14:17 by trupham           #+#    #+#             */
/*   Updated: 2025/07/22 11:55:20 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exit_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

bool	is_stack_empty(t_stack *stack)
{
	return (stack->top < 0);
}

void	store_op(t_node **list, int op)
{
	t_node	*new_node;
	t_node	*last;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->num = op;
	new_node->next = NULL;
	if (!*list)
	{
		*list = new_node;
		return ;
	}
	last = *list;
	while (last->next)
		last = last->next;
	last->next = new_node;
}

void	destroy_stack(t_stack *stack)
{
	if (stack)
	{
		free(stack->arr);
		free(stack->sorted_arr);
		free(stack);
	}
}

void	free_data(t_stack *stack_a, t_stack *stack_b, t_node *list)
{
	t_node	*next;

	while (list)
	{
		next = list->next;
		free(list);
		list = next;
	}
	destroy_stack(stack_a);
	destroy_stack(stack_b);
}
