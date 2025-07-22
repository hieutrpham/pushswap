/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuning.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:19:51 by trupham           #+#    #+#             */
/*   Updated: 2025/07/22 11:54:37 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	tune_ra_rb(t_node **list)
{
	int	count_ra;
	int	count_rb;

	count_ra = 0;
	count_rb = 0;
	while (*list && (*list)->next)
	{
		if ((*list)->num == ra && ((*list)->next->num == ra ||
			(*list)->next->num == rb))
		{
			count_ra++;
			(*list) = (*list)->next;
		}
		else if ((*list)->num == rb && ((*list)->next->num == rb ||
			(*list)->next->num != rb))
		{
			count_rb++;
			(*list) = (*list)->next;
			if ((*list)->next->num != rb)
				break;
		}
		else
			break;
	}
	return (print_count(count_ra, count_rb, rr), count_ra);
}

int	tune_rra_rrb(t_node **list)
{
	int	count_rra;
	int	count_rrb;

	count_rra = 0;
	count_rrb = 0;
	while (*list && (*list)->next)
	{
		if ((*list)->num == rra && ((*list)->next->num == rra ||
			(*list)->next->num == rrb))
		{
			count_rra++;
			(*list) = (*list)->next;
		}
		else if ((*list)->num == rrb && ((*list)->next->num == rrb ||
			(*list)->next->num != rrb))
		{
			count_rrb++;
			(*list) = (*list)->next;
			if ((*list)->next->num !=rrb)
				break;
		}
		else
			break;
	}
	return (print_count(count_rra, count_rrb, rrr), count_rra);
}
