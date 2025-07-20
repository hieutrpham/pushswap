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
	int i = 0;
	// looping through each chunk
	while (i < stack_a->chunk_size)
	{
		int start_index = i * stack_a->chunk_size;
		int end_index = (i + 1) * stack_a->chunk_size - 1;
		int index_top = scan_top(stack_a, start_index, end_index);
		int index_bot = scan_bottom(stack_a, start_index, end_index);
		// scan from the top and bottom and search for the matching number in current chunk
		while ((index_top != -1 || index_bot != -1) && !is_stack_empty(stack_a))
		{
			// move target index to the top and push to b (also have to prep b)
			int num_ra = index_top - stack_a->top;
			int num_rra = stack_a->size - index_bot;
			if (num_ra <= num_rra)
				do_rotate(stack_a, &node, ra, num_ra);
			else
				do_rotate(stack_a, &node, rra, num_rra);
			prep_stack_b(stack_a, &node, stack_b);
			push(stack_a, stack_b, &node, pb);
			// scan again until done with the chunk
			index_top = scan_top(stack_a, start_index, end_index);
			index_bot = scan_bottom(stack_a, start_index, end_index);
		}
		i++;
	}
	// handle leftover in stack a
	i = stack_a->top;
	while (!is_stack_empty(stack_a))
	{
		prep_stack_b(stack_a, &node, stack_b);
		push(stack_a, stack_b, &node, pb);
		i++;
	}
	// sort b in descending order
	int max_b = find_max(stack_b);
	int num_rb = max_b - stack_b->top;
	int num_rrb = stack_b->size - max_b;
	if (num_rb <= num_rrb)
		do_rotate(stack_b, &node, rb, num_rb);
	else
		do_rotate(stack_b, &node, rrb, num_rrb);

	// push everything from stack b to stack a
	while (!is_stack_empty(stack_b))
		push(stack_b, stack_a, &node, pa);

	// print operations
	print_list(node);
	// free the linked list
	while (node)
	{
		i_list *next = node->next;
		free(node);
		node = next;
	}
	destroy_stack(stack_a);
	destroy_stack(stack_b);
	
	return EXIT_SUCCESS;
}
