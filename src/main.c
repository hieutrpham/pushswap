/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 07:40:05 by trupham           #+#    #+#             */
/*   Updated: 2025/07/10 22:49:08 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"
#include <stdlib.h>

void print_stack(t_stack *stack)
{
	for (int i = 0; i < stack->size; i++)
	  ft_printf("%d\n", stack->arr[i]);
}

void print_list(t_list *list)
{
	while (list)
	{
		ft_printf("%s\n", list->content);
		list = list->next;
	}
}

int main(int ac, char **av) 
{
	check_input(ac, av);
	t_stack *stack_a;
	t_stack *stack_b;
	t_list *node;

	stack_a = build_stack(ac, av);
	if (!stack_a)
		return EXIT_FAILURE;
	stack_b = build_empty_stack(stack_a->size);
	if (!stack_b)
		return (destroy_stack(stack_a), EXIT_FAILURE);
	node = NULL;
	print_stack(stack_a);
	swap(stack_a, &node, 'a');
	print_stack(stack_a);
	ft_printf("top: %d\n", stack_a->top);
	print_list(node);
	destroy_stack(stack_a);
	destroy_stack(stack_b);
	return EXIT_SUCCESS;
}
