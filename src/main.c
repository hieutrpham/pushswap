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

void	print_stack(t_stack *stack, char c)
{
	int	i;

	i = stack->top;
	if (c == 'a')
		ft_printf("=========stack a=========\n");
	else if (c == 'b')
		ft_printf("=========stack b=========\n");
	while (i < stack->size)
	{
		ft_printf("index: %d, value: %d\n", i, stack->arr[i]);
		i++;
	}
}

/*@brief: to build stack b
 */
static t_stack	*build_empty_stack(unsigned int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->arr = ft_calloc(size, sizeof(int));
	if (!stack->arr)
		return (free(stack), NULL);
	stack->size = size;
	stack->top = -1;
	stack->len = 0;
	stack->chunk_size = 0;
	stack->sorted_arr = NULL;
	return (stack);
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
	check_dup(stack_a);
	if (is_sorted(stack_a->arr, stack_a->size))
		return (destroy_stack(stack_a), EXIT_SUCCESS);
	stack_b = build_empty_stack(stack_a->size);
	if (!stack_b)
		return (destroy_stack(stack_a), EXIT_FAILURE);
	node = NULL;
	init_sort(stack_a, stack_b, &node);
	print_list(node);
	free_data(stack_a, stack_b, node);
	return (EXIT_SUCCESS);
}
