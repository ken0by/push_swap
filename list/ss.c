/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:36:42 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/27 17:20:05 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_swap_a(lst *a, lst *aux)
{
	lst	*aux2;

	aux2 = NULL;
	aux2->n = aux->n;
	aux->n = a->n;
	a->n = aux2->n;
	ft_printf("sa\n");
}

void	ft_swap_b(lst *a, lst *b)
{
	lst	*aux;
	lst	*aux1;

	b = lstnew(a->n);
	aux = a;
	aux = aux->next;
	aux1 = lstnew(aux->n);
	lstadd_back(&b, aux1);
	aux = aux->next;
	a = aux;
	ft_printf("sb\n");
}

void	ft_swap_s(lst *a, lst *b)
{
	lst	*aux;

	aux = a->next;
	ft_swap_a(a, aux);
	ft_swap_b(a, b);
	ft_printf("ss\n");
}
