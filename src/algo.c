/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:04:27 by trupham           #+#    #+#             */
/*   Updated: 2025/07/20 20:58:48 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*@brief: prepare stack a so that the element with the least moves are
 * moved first
 */
static void	prep_stack_a(t_stack *stack_a, i_list **list, int index_top,
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
static void	prep_stack_b(t_stack *stack_a, i_list **list, t_stack *stack_b)
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
		if (closest <= (stack_b->size + stack_b->top) / 2)
			do_rotate(stack_b, list, rb, closest - stack_b->top);
		else
			do_rotate(stack_b, list, rrb, stack_b->size - closest);
	}
}

/*@brief: core algorithm that insert elements from stack a to stack b
 * based on a presorted array
 */
void	insert_sort(t_stack *stack_a, t_stack *stack_b, i_list **list)
{
	int	start_index;
	int	end_index;
	int	index_top;
	int	index_bot;
	int	i;

	i = 0;
	while (i < stack_a->chunk_size)
	{
		start_index = i * stack_a->chunk_size;
		end_index = (i + 1) * stack_a->chunk_size - 1;
		index_top = scan_top(stack_a, start_index, end_index);
		index_bot = scan_bottom(stack_a, start_index, end_index);
		while ((index_top != -1 || index_bot != -1) && !is_stack_empty(stack_a))
		{
			prep_stack_a(stack_a, list, index_top, index_bot);
			prep_stack_b(stack_a, list, stack_b);
			push(stack_a, stack_b, list, pb);
			index_top = scan_top(stack_a, start_index, end_index);
			index_bot = scan_bottom(stack_a, start_index, end_index);
		}
		i++;
	}
}

/*@brief: push the rest of stack a to stack b
 * NOTE: can I optimize for this some more?
 */
void	post_insert_prep(t_stack *stack_a, t_stack *stack_b, i_list **list)
{
	int	i;

	i = stack_a->top;
	while (!is_stack_empty(stack_a))
	{
		prep_stack_b(stack_a, list, stack_b);
		push(stack_a, stack_b, list, pb);
		i++;
	}
}

/*@brief: sort stack b after insertion and push back all elements to stack a
 */
void	sort_b_and_pa(t_stack *stack_a, t_stack *stack_b, i_list **list)
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
