/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 07:40:05 by trupham           #+#    #+#             */
/*   Updated: 2025/07/17 08:29:56 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void print_stack(t_stack *stack)
{
	for (int i = stack->top; i < stack->size; i++)
	{
		ft_printf("%d\n", stack->sorted_arr[i]);
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
	// node = NULL;
	ft_printf("%d\n", stack_a->chunk_size);
	destroy_stack(stack_a);
	destroy_stack(stack_b);
	return EXIT_SUCCESS;
}
