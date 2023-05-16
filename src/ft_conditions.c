/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conditions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:59:01 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/16 17:09:14 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_conditions(t_lst **a, t_lst **b, int ac)
{
	if (ac == 4)
		*a = ft_exception_3(a, b);
	else if (ac == 6)
		*a = ft_exception(a, b);
	else if (ac > 2 && ac <= 41)
		*a = ft_swap(a, b);
	else
		*a = ft_radix(a, b);
}
