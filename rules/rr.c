/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:31:18 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/13 13:51:53 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_lst	*ft_rotate_a(t_lst *a)
{
	t_lst	*aux;

	aux = a;
	a = a->next;
	aux->next = NULL;
	lstadd_back(&a, aux);
	ft_printf("ra\n");
	return (a);
}

t_lst	*ft_rotate_b(t_lst *b)
{
	t_lst	*aux;

	aux = b;
	b = b->next;
	aux->next = NULL;
	lstadd_back(&b, aux);
	ft_printf("rb\n");
	return (b);
}

void	ft_rotate_r(t_lst *a, t_lst *b)
{
	t_lst	*aux;
	t_lst	*aux1;

	aux = ft_rotate_a(a);
	aux1 = ft_rotate_b(b);
	a = aux;
	b = aux1;
	ft_printf("rr\n");
}
