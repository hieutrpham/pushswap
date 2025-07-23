/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:03:10 by trupham           #+#    #+#             */
/*   Updated: 2025/07/22 11:54:35 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	print_multiple(int op, int times)
{
	int	i;

	i = 0;
	while (i++ < times)
	{
		if (op == rr)
			ft_printf("rr\n");
		else if (op == rrr)
			ft_printf("rrr\n");
		else if (op == ra)
			ft_printf("ra\n");
		else if (op == rb)
			ft_printf("rb\n");
		else if (op == rra)
			ft_printf("rra\n");
		else if (op == rrb)
			ft_printf("rrb\n");
	}
}

static void	print_count(int count_ra, int count_rb, int op)
{
	if (op == rr)
	{
		if (count_ra != 0 && count_rb != 0)
			print_multiple(rr, ft_min(count_ra, count_rb));
		if (count_ra > count_rb)
			print_multiple(ra, count_ra - count_rb);
		if (count_ra < count_rb)
			print_multiple(rb, count_rb - count_ra);
		if (count_ra == 0)
			print_multiple(ra, 1);
	}
	else if (op == rrr)
	{
		if (count_ra != 0 && count_rb != 0)
			print_multiple(rrr, ft_min(count_ra, count_rb));
		if (count_ra > count_rb)
			print_multiple(rra, count_ra - count_rb);
		if (count_ra < count_rb)
			print_multiple(rrb, count_rb - count_ra);
		if (count_ra == 0)
			print_multiple(rra, 1);
	}
}

static int	tune_ra_rb(t_node **list)
{
	int	count_ra;
	int	count_rb;

	count_ra = 0;
	count_rb = 0;
	while (*list && (*list)->next)
	{
		if ((*list)->num == ra && ((*list)->next->num == ra
				|| (*list)->next->num == rb))
		{
			count_ra++;
			(*list) = (*list)->next;
		}
		else if ((*list)->num == rb && ((*list)->next->num == rb
				|| (*list)->next->num != rb))
		{
			count_rb++;
			(*list) = (*list)->next;
			if ((*list)->next->num != rb)
				break ;
		}
		else
			break ;
	}
	return (print_count(count_ra, count_rb, rr), count_ra);
}

static int	tune_rra_rrb(t_node **list)
{
	int	count_rra;
	int	count_rrb;

	count_rra = 0;
	count_rrb = 0;
	while (*list && (*list)->next)
	{
		if ((*list)->num == rra && ((*list)->next->num == rra
				|| (*list)->next->num == rrb))
		{
			count_rra++;
			(*list) = (*list)->next;
		}
		else if ((*list)->num == rrb && ((*list)->next->num == rrb
				|| (*list)->next->num != rrb))
		{
			count_rrb++;
			(*list) = (*list)->next;
			if ((*list)->next->num != rrb)
				break ;
		}
		else
			break ;
	}
	return (print_count(count_rra, count_rrb, rrr), count_rra);
}

void	print_list(t_node *list)
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
		if (list->num == ra && tune_ra_rb(&list))
			continue ;
		if (list->num == rra && tune_rra_rrb(&list))
			continue ;
		if (list->num == rb)
			ft_printf("rb\n");
		if (list->num == rrb)
			ft_printf("rrb\n");
		list = list->next;
	}
}

