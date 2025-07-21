/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 07:40:05 by trupham           #+#    #+#             */
/*   Updated: 2025/07/20 22:01:57 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	i_list	*node;

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
	insert_sort(stack_a, stack_b, &node);
	post_insert_prep(stack_a, stack_b, &node);
	sort_b_and_pa(stack_a, stack_b, &node);
	print_list(node);
	free_data(stack_a, stack_b, node);
	return (EXIT_SUCCESS);
}
