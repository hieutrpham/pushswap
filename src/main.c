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

void print_stack(t_stack *stack)
{
	for (int i = stack->top; i < stack->size; i++)
	  ft_printf("%d\n", stack->arr[i]);
}

void print_list(i_list *list)
{
	int i = 0;

	while (list)
	{
		ft_printf("node %d: %d\n", i++, list->num);
		list = list->next;
	}
}

int main(int ac, char **av) 
{
	check_input(ac, av);
	t_stack *stack_a;
	t_stack *stack_b;
	i_list *node;

	stack_a = build_stack(ac, av);
	if (!stack_a)
		return EXIT_FAILURE;
	check_dup(stack_a);
	stack_b = build_empty_stack(stack_a->size);
	if (!stack_b)
		return (destroy_stack(stack_a), EXIT_FAILURE);
	node = NULL;

	ft_putendl_fd("original stack a", 1);
	print_stack(stack_a);

	reverse_rotate(stack_a, &node, ra);
	reverse_rotate(stack_a, &node, ra);
	reverse_rotate(stack_a, &node, ra);
	reverse_rotate(stack_a, &node, ra);
	ft_printf("stack a after rotate\n");
	print_stack(stack_a);
	// print_list(node);

	destroy_stack(stack_a);
	destroy_stack(stack_b);
	return EXIT_SUCCESS;
}
