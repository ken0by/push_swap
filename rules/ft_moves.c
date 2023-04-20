/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:12:45 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/20 14:28:20 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_check_revrot(t_lst **a, t_lst **b, t_lst *aux, t_lst *aux1)
{
	t_lst	*aux2;
	t_lst	*aux3;

	aux3 = NULL;
	aux = lstlast(a[0]);
	if (a[0]->next)
		aux2 = a[0]->next;
	if (b[0])
	{
		aux1 = lstlast(b[0]);
		if (b[0]->next)
			aux3 = b[0]->next;
	}
	if ((a[0]->n > aux->n) && (aux2->n > aux->n)
		&& b[0] && (b[0]->n > aux1->n) && (aux3->n > aux1->n))
		ft_rrotate_r(a, b);
	else if ((a[0]->n > aux->n) && (aux2->n > aux->n))
		a[0] = ft_rrotate_a(a[0], 0);
	else if (aux1 && aux3 && (b[0]->n < aux1->n) && (aux3->n > aux1->n))
		b[0] = ft_rrotate_b(b[0], 0);
	else
		return (1);
	return (0);
}

static int	ft_check_rotation(t_lst **a, t_lst **b, t_lst *aux, t_lst *aux1)
{
	t_lst	*aux2;
	t_lst	*aux3;

	aux3 = NULL;
	aux = lstlast(a[0]);
	if (a[0]->next)
		aux2 = a[0]->next;
	if (b[0])
	{
		aux1 = lstlast(b[0]);
		if (b[0]->next)
			aux3 = b[0]->next;
	}
	if ((a[0]->n > aux->n) && (a[0]->n > aux2->n)
		&& b[0] && (b[0]->n < aux1->n) && (b[0]->n < aux3->n))
		ft_rotate_r(a, b);
	else if ((a[0]->n > aux->n) && (a[0]->n > aux2->n) && (a[0]->n > b[0]->n))
		a[0] = ft_rotate_a(a[0], 0);
	else if (aux1 && aux3 && (b[0]->n < aux1->n) && (b[0]->n < aux3->n))
		b[0] = ft_rotate_b(b[0], 0);
	else
		return (1);
	return (0);
}

static int	ft_check_push(t_lst **a, t_lst **b, t_lst *aux1, int flag)
{
	t_lst	*aux;

	if (flag == 2)
	{
		while (a[0])
		{
			aux = a[0]->next;
			if (a[0]->n == aux1->n)
				break ;
			ft_push_b(a[0], b);
			a[0] = aux;
		}
		flag = 1;
	}
	if (flag == 0 && b[0])
	{
		while (b[0])
		{
			if (b[0] && ft_check_pa(a) == 1)
				break ;
			aux = b[0];
			b[0] = b[0]->next;
			aux->next = NULL;
			ft_push_a(a, aux);
		}
	}
	return (flag);
}

static int	ft_check_a(t_lst **a)
{
	t_lst	*aux;
	t_lst	*aux1;

	aux = a[0];
	while (aux)
	{
		if (aux->next)
			aux1 = aux->next;
		if (aux->n > aux1->n)
			return (1);
		aux = aux->next;
	}
	return (0);
}

t_lst	*ft_swap(t_lst **a, t_lst *b)
{
	t_lst	*aux;
	t_lst	*aux1;
	t_lst	*aux2;
	t_lst	*aux3;
	int		flag;

	flag = 1;
	aux3 = NULL;
	if (ft_count(a[0]) < 4)
	{
		aux = a[0];
		aux1 = aux->next;
		aux2 = aux1->next;
		if (aux->n > aux1->n && aux->n > aux2->n && aux1->n < aux2->n)
			return (ft_rotate_a(a[0], 0));
		if (aux2->n < aux->n && aux2->n < aux1->n && aux->n < aux1->n)
			return (ft_rrotate_a(a[0], 0));
	}
	while (flag == 1)
	{
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
		if ((flag == 1) && (aux->n > aux1->n) && aux3 && aux2
			&& (aux2->n < aux3->n) && ft_count(a[0]) > 1 && ft_count(b) > 1)
		{
			ft_swap_s(a[0], b);
			flag = 1;
			ft_printf("ss\n");
		}
		else if ((flag == 1) && (aux->n > aux1->n) && ft_count(a[0]) > 1)
		{
			ft_swap_a(aux, aux1);
			flag = 1;
			ft_printf("sa\n");
		}
		else if ((flag == 1) && aux3 && (aux2->n < aux3->n) && ft_count(b) > 1)
		{
			ft_swap_b(aux2, aux3);
			flag = 1;
			ft_printf("sb\n");
		}
		else
			flag = 0;
		while (aux)
		{
			if (aux->next)
				aux1 = aux->next;
			else
				break ;
			if (aux->n > aux1->n)
			{
				flag = 2;
				break ;
			}
			aux = aux->next;
		}
		if (flag == 1)
			flag = ft_check_revrot(a, &b, a[0]->next, aux3);
		if (flag == 1)
			flag = ft_check_rotation(a, &b, a[0]->next, aux3);
		if (flag == 2 || flag == 0)
			flag = ft_check_push(a, &b, aux, flag);
		if (b)
			flag = 1;
		else
			flag = ft_check_a(a);
	}
	return (a[0]);
}
