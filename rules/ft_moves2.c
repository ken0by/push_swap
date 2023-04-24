/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:28:21 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/24 18:20:07 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_sa(int flag, t_lst *aux, t_lst *aux1)
{
	ft_swap_a(aux, aux1);
	flag = 1;
	ft_printf("sa\n");
	return (flag);
}

static int	ft_sb(int flag, t_lst **b)
{
	t_lst	*aux2;
	t_lst	*aux3;

	if (*b)
	{
		aux2 = *b;
		if ((*b)->next)
			aux3 = (*b)->next;
	}
	if ((flag == 1) && aux3 && (aux2->n < aux3->n) && ft_count(*b) > 1)
	{
		ft_swap_b(aux2, aux3);
		flag = 1;
		ft_printf("sb\n");
	}
	else
		flag = 0;
	return (flag);
}

int	ft_ss(int flag, t_lst *aux, t_lst **a, t_lst **b)
{
	t_lst	*aux1;
	t_lst	*aux2;
	t_lst	*aux3;

	aux1 = aux->next;
	if (*b)
	{
		aux2 = *b;
		if ((*b)->next)
			aux3 = (*b)->next;
	}
	if ((flag == 1) && (aux->n > aux1->n) && aux3 && aux2
		&& (aux2->n < aux3->n) && ft_count(a[0]) > 1 && ft_count(*b) > 1)
	{
		ft_swap_s(*a, *b);
		flag = 1;
		ft_printf("ss\n");
	}
	else if ((flag == 1) && (aux->n > aux1->n) && ft_count(*a) > 1)
		flag = ft_sa(flag, aux, aux1);
	else if (*b)
		flag = ft_sb(flag, b);
	return (flag);
}

t_lst	*ft_exception4(t_lst **a)
{
	t_lst	*aux;
	t_lst	*aux1;
	t_lst	*aux2;

	aux = a[0];
	aux1 = aux->next;
	aux2 = aux1->next;
	if (aux->n > aux1->n && aux->n > aux2->n && aux1->n < aux2->n)
		return (ft_rotate_a(a[0], 0));
	if (aux2->n < aux->n && aux2->n < aux1->n && aux->n < aux1->n)
		return (ft_rrotate_a(a[0], 0));
	return (*a);
}

void	ft_check_moves(t_lst **a, t_lst **b, t_lst *aux, int flag)
{
	if (flag == 1)
		flag = ft_check_revrot(a, b, (*a)->next, (*b)->next);
	if (flag == 1)
		flag = ft_check_rotation(a, b, (*a)->next, (*b)->next);
	if (flag == 2 || flag == 0)
	{
		flag = ft_check_push(a, b, aux, flag);
		if (flag == 2)
			flag = 1;
	}
}
