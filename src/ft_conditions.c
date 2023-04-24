/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conditions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:39:52 by rodro             #+#    #+#             */
/*   Updated: 2023/04/23 16:27:04 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_two(t_lst **a)
{
	t_lst	*aux;

	aux = (*a)->next;
	if ((*a)->p == 1 && aux->p == 0)
	{
		ft_swap_a(*a, (*a)->next);
		ft_printf("sa\n");
	}
}

void	ft_conditions(t_lst **a, t_lst **b, int ac)
{
	if (ac == 3)
		ft_two(a);
	else if (ac == 4)
		*a = ft_exception_3(a, b);
	else if (ac == 6)
		*a = ft_exception(a, b);
	else if (ac > 2 && ac <= 41)
		*a = ft_swap(a, b);
	else
		*a = ft_radix(a, b);
}
