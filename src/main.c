/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 07:40:05 by trupham           #+#    #+#             */
/*   Updated: 2025/07/17 18:29:04 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void print_stack(t_stack *stack)
{
	ft_printf("sorted stack:\n");

	for (int i = stack->top; i < stack->size; i++)
	{
		ft_printf("index %d: %d\n", i, stack->sorted_arr[i]);
	}
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
		if (list->num == rb)
			ft_printf("rb\n");
		list = list->next;
	}
}

int main(int ac, char **av) 
{
	check_input(ac, av);
	t_stack *stack_a;
	t_stack *stack_b;
	// i_list *node;

	stack_a = build_stack(ac, av);
	if (!stack_a)
		return EXIT_FAILURE;
	check_dup(stack_a);
	stack_b = build_empty_stack(stack_a->size);
	if (!stack_b)
		return (destroy_stack(stack_a), EXIT_FAILURE);

	int i = 0;
	// ft_printf("chunk size: %d\n", stack_a->chunk_size);
	print_stack(stack_a);
	while (i < stack_a->chunk_size)
	{
		int start_index = i * stack_a->chunk_size;
		int end_index = (i + 1) * stack_a->chunk_size - 1;
		ft_printf("chunk %d, start: %d, end %d\n", i, start_index, end_index);
		// do things for each chunk
		int index_top = scan_top(stack_a, start_index, end_index);
		ft_printf("index top: %d, number: %d\n", index_top, stack_a->arr[index_top]);
		i++;
	}

	// node = NULL;
	destroy_stack(stack_a);
	destroy_stack(stack_b);
	return EXIT_SUCCESS;
}
