/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:04:27 by trupham           #+#    #+#             */
/*   Updated: 2025/07/22 16:08:48 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void print_stack(t_stack *stack, char c)
{
	if (c == 'a')
		ft_printf("=========stack a=========\n");
	else if (c == 'b')
		ft_printf("=========stack b=========\n");
	for (int i = stack->top; i < stack->size; i++)
		ft_printf("index: %d, value: %d\n", i, stack->arr[i]);
}
/*@brief: prepare stack a so that the element with the least moves are
 * moved first
 */
static void	prep_stack_a(t_stack *stack_a, t_node **list, int index_top,
		int index_bot)
{
	int	num_ra;
	int	num_rra;

	num_ra = -1;
	num_rra = -1;
	if (index_top != -1)
		num_ra = index_top - stack_a->top;
	if (index_bot != -1)
		num_rra = stack_a->size - index_bot;
	if ((num_ra <= num_rra && num_ra > 0 && num_rra > 0) || (num_ra > 0
			&& num_rra < 0))
		do_rotate(stack_a, list, ra, num_ra);
	else if ((num_ra > num_rra && num_ra > 0 && num_rra > 0) || (num_ra < 0
			&& num_rra > 0))
		do_rotate(stack_a, list, rra, num_rra);
}

/*@brief: prepare stack b to push the top element in stack a in the correct slot
 */
static void	prep_stack_b(t_stack *stack_a, t_node **list, t_stack *stack_b)
{
	int	max_b;
	int	min_b;
	int	closest;

	closest = stack_b->top;
	min_b = find_min(stack_b);
	max_b = find_max(stack_b);
	if (is_stack_empty(stack_b) || stack_b->len < 2)
		return ;
	if (stack_a->arr[stack_a->top] > stack_b->arr[max_b]
		|| stack_a->arr[stack_a->top] < stack_b->arr[min_b])
	{
		if (max_b <= (stack_b->size + stack_b->top) / 2)
			do_rotate(stack_b, list, rb, max_b - stack_b->top);
		else
			do_rotate(stack_b, list, rrb, stack_b->size - max_b);
	}
	else
	{
		closest = find_closest_smaller(stack_a, stack_b);
		// print_stack(stack_a, 'a');
		// ft_printf("closest smaller: %d\n", stack_b->arr[closest]);
		if (closest <= (stack_b->size + stack_b->top) / 2)
			do_rotate(stack_b, list, rb, closest - stack_b->top);
		else
		{
			// print_stack(stack_b, 'b');
			do_rotate(stack_b, list, rrb, stack_b->size - closest);
			// print_stack(stack_b, 'b');
		}
	}
}

/*@brief: core algorithm that insert elements from stack a to stack b
 * based on a presorted array
 */
void	insert_sort(t_stack *stack_a, t_stack *stack_b, t_node **list,
		int chunk_size)
{
	int	index_top;
	int	index_bot;
	int	i;
	int	size;

	if (chunk_size > 0)
		size = chunk_size;
	else
		size = stack_a->chunk_size;
	i = -1;
	while (++i < size)
	{
		index_top = scan_top(stack_a, i * size, (i + 1) * size - 1);
		index_bot = scan_bottom(stack_a, i * size, (i + 1) * size - 1);
		while ((index_top != -1 || index_bot != -1) && !is_stack_empty(stack_a))
		{
			prep_stack_a(stack_a, list, index_top, index_bot);
			prep_stack_b(stack_a, list, stack_b);
			push(stack_a, stack_b, list, pb);
			index_top = scan_top(stack_a, i * size, (i + 1) * size - 1);
			index_bot = scan_bottom(stack_a, i * size, (i + 1) * size - 1);
		}
	}
}

/*@brief: push the rest of stack a to stack b
 */
void	post_insert_prep(t_stack *stack_a, t_stack *stack_b, t_node **list)
{
	// while (stack_a->len > 3)
	while (!is_stack_empty(stack_a))
	{
		prep_stack_b(stack_a, list, stack_b);
		push(stack_a, stack_b, list, pb);
	}
	// sort_three(stack_a, list);
}

/*@brief: sort stack b after insertion and push back all elements to stack a
 */
void	sort_b_and_pa(t_stack *stack_a, t_stack *stack_b, t_node **list)
{
	int	max_b;
	int	num_rb;
	int	num_rrb;

	max_b = find_max(stack_b);
	num_rb = max_b - stack_b->top;
	num_rrb = stack_b->size - max_b;
	if (num_rb <= num_rrb)
		do_rotate(stack_b, list, rb, num_rb);
	else
		do_rotate(stack_b, list, rrb, num_rrb);
	while (!is_stack_empty(stack_b))
		push(stack_b, stack_a, list, pa);
}
