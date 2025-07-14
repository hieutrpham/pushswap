/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 07:40:05 by trupham           #+#    #+#             */
/*   Updated: 2025/07/14 12:23:07 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void print_stack(t_stack *stack)
{
	for (int i = stack->top; i < stack->size; i++)
	{
		ft_printf("%d\n", stack->arr[i]);
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

void bad_algo(t_stack *stack_a, t_stack *stack_b, i_list **list)
{
	int min_index;

	min_index = find_min(stack_a);
	while (!is_stack_empty(stack_a))
	{
		while (min_index != stack_a->top)
		{
			rotate(stack_a, list, ra);
			min_index = find_min(stack_a);
		}
		push(stack_a, stack_b, list, pb);
	}
	while (!is_stack_empty(stack_b))
	{
		push(stack_b, stack_a, list, pa);
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
	
	bad_algo(stack_a, stack_b, &node);
	// print_stack(stack_a);
	print_list(node);
	destroy_stack(stack_a);
	destroy_stack(stack_b);
	return EXIT_SUCCESS;
}
