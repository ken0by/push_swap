/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:31:18 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/20 13:57:04 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_lst	*ft_rotate_a(t_lst *a, int i)
{
	t_lst	*aux;

	aux = a;
	a = a->next;
	aux->next = NULL;
	lstadd_back(&a, aux);
	if (i == 0)
		ft_printf("ra\n");
	return (a);
}

t_lst	*ft_rotate_b(t_lst *b, int i)
{
	t_lst	*aux;

	aux = b;
	b = b->next;
	aux->next = NULL;
	lstadd_back(&b, aux);
	if (i == 0)
		ft_printf("rb\n");
	return (b);
}

void	ft_rotate_r(t_lst **a, t_lst **b)
{
	t_lst	*aux;
	t_lst	*aux1;

	aux = ft_rotate_a(a[0], 1);
	aux1 = ft_rotate_b(b[0], 1);
	a[0] = aux;
	b[0] = aux1;
	ft_printf("rr\n");
}

t_lst	*ft_ra(t_lst **a, int i)
{
	t_lst	*aux;

	aux = *a;
	*a = (*a)->next;
	aux->next = NULL;
	lstadd_back(a, aux);
	if (i == 0)
		ft_printf("ra\n");
	return (*a);
}
