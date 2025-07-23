/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:03:44 by trupham           #+#    #+#             */
/*   Updated: 2025/07/17 18:38:48 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int num)
{
	int	i;

	i = 0;
	while (i * i <= num)
	{
		if (i * i > num)
			break ;
		i++;
	}
	return (i - 1);
}

int	ft_min(int num1, int num2)
{
	if (num1 > num2)
		return (num2);
	else if (num2 >= num1)
		return (num1);
	else
		return (INT_MIN);
}

int	ft_max(int num1, int num2)
{
	if (num1 >= num2)
		return (num1);
	else if (num2 > num1)
		return (num2);
	else
		return (INT_MAX);
}
