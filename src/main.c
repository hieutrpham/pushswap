/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 07:40:05 by trupham           #+#    #+#             */
/*   Updated: 2025/07/22 15:37:18 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

static void	init_sort(t_stack *stack_a, t_stack *stack_b, t_node **list)
{
	if (stack_a->size == 3)
		sort_three(stack_a, list);
	else if (stack_a->size == 2)
		sort_two(stack_a, list);
	else if (stack_a->size == 5 || stack_a->size == 4)
		sort_five(stack_a, stack_b, list);
	else if (stack_a->size == 100)
	{
		insert_sort(stack_a, stack_b, list, 18);
		post_insert_prep(stack_a, stack_b, list);
		sort_b_and_pa(stack_a, stack_b, list);
	}
	else
	{
		insert_sort(stack_a, stack_b, list, -1);
		post_insert_prep(stack_a, stack_b, list);
		sort_b_and_pa(stack_a, stack_b, list);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_node	*node;

	check_input(ac, av);
	stack_a = build_stack(ac, av);
	if (!stack_a)
		return (EXIT_FAILURE);
	if (is_sorted(stack_a->arr, stack_a->size))
		return (destroy_stack(stack_a), EXIT_SUCCESS);
	check_dup(stack_a);
	stack_b = build_empty_stack(stack_a->size);
	if (!stack_b)
		return (destroy_stack(stack_a), EXIT_FAILURE);
	node = NULL;
	init_sort(stack_a, stack_b, &node);
	print_list(node);
	free_data(stack_a, stack_b, node);
	return (EXIT_SUCCESS);
}
