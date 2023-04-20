/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:28:21 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/20 13:37:35 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_sa(int flag, t_lst *aux, t_lst **a, t_lst *aux1)
{
	ft_swap_a(aux, aux1);
	flag = 1;
	ft_printf("sa\n");
	return (flag);
}

int	ft_ss(int flag, t_lst *aux, t_lst **a, t_lst *b)
{
	t_lst	*aux1;
	t_lst	*aux2;
	t_lst	*aux3;

	aux1 = aux->next;
	if ((flag == 1) && (aux->n > aux1->n) && aux3 && aux2
			&& (aux2->n < aux3->n) && ft_count(a[0]) > 1 && ft_count(b) > 1)
		{
			ft_swap_s(a[0], b);
			flag = 1;
			ft_printf("ss\n");
		}
		else if ((flag == 1) && (aux->n > aux1->n) && ft_count(a[0]) > 1)
			flag = ft_sa(flag, aux, a, aux1);
		else if ((flag == 1) && aux3 && (aux2->n < aux3->n) && ft_count(b) > 1)
		{
			ft_swap_b(aux2, aux3);
			flag = 1;
			ft_printf("sb\n");
		}
		else
			flag = 0;
	return (flag);
}

int ft_do_moves(t_lst **a, t_lst *b, int flag)
{
	t_lst	*aux;
	t_lst	*aux1;
	t_lst	*aux2;
	t_lst	*aux3;

	if (b && b->next)
		aux3 = b->next;
	else
		aux3 = NULL;
	aux = a[0];
	if (aux->next)
		aux1 = aux->next;
	if (b)
	{
		aux2 = b;
		if (b->next)
			aux3 = b->next;
	}
	flag = ft_ss(flag, aux, a, b);
	return (flag);
}
