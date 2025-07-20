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

void print_stack(t_stack *stack, int c)
{
	if (is_stack_empty(stack))
		return;
	if (c == 'a')
		ft_printf("===stack a===\n");
	else
		ft_printf("===stack b===\n");
	for (int i = stack->top; i < stack->size; i++)
		ft_printf("index %d: %d\n", i, stack->arr[i]);
	ft_printf("\n");
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
		if (list->num == rra)
			ft_printf("rra\n");
		if (list->num == rb)
			ft_printf("rb\n");
		if (list->num == rrb)
			ft_printf("rrb\n");
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
	int i = 0;
	// ft_printf("chunk size: %d\n", stack_a->chunk_size);
	// print_stack(stack_a, 'a');
	// looping through each chunk
	while (i < stack_a->chunk_size)
	{
		int start_index = i * stack_a->chunk_size;
		int end_index = (i + 1) * stack_a->chunk_size - 1;
		// ft_printf("+++chunk %d, start: %d, end %d\n\n", i, stack_a->sorted_arr[start_index], stack_a->sorted_arr[end_index]);
		int index_top = scan_top(stack_a, start_index, end_index);
		int index_bot = scan_bottom(stack_a, start_index, end_index);
		// ft_printf("===value top: %d, value bot: %d\n", stack_a->arr[index_top], stack_a->arr[index_bot]);
		
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
			// ft_printf("---index top: %d, index bot: %d\n", index_top, index_bot);
			// ft_printf("===value top: %d, value bot: %d\n", stack_a->arr[index_top], stack_a->arr[index_bot]);
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
	// loop to sort b in descending order
	int max_b = find_max(stack_b);
	int num_rb = max_b - stack_b->top;
	int num_rrb = stack_b->size - max_b;
	if (num_rb <= num_rrb)
		do_rotate(stack_b, &node, rb, num_rb);
	else
		do_rotate(stack_b, &node, rrb, num_rrb);

	// print_stack(stack_b, 'b');
	// print_stack(stack_a, 'a');
	while (!is_stack_empty(stack_b))
		push(stack_b, stack_a, &node, pa);
	// print_stack(stack_a, 'a');
	print_list(node);
	destroy_stack(stack_a);
	destroy_stack(stack_b);
	
	return EXIT_SUCCESS;
}
