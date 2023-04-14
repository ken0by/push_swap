/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:12:45 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/14 12:57:16 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int ft_check_rotation(t_lst **a, t_lst **b, t_lst *aux, t_lst *aux1)
{
	t_lst *aux2;
	t_lst *aux3;

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
	if ((a[0]->n > aux->n) && (a[0]->n > aux2->n) && b[0] && (b[0]->n > aux1->n) && (b[0]->n > aux3->n))
		ft_rotate_r(a[0], b[0]);
	else if ((a[0]->n > aux->n) && (a[0]->n > aux2->n))
		a[0] = ft_rotate_a(a[0]);
	else if (aux1 && aux3 && (b[0]->n < aux1->n) && (b[0]->n < aux3->n))
		b[0] = ft_rotate_b(b[0]);
	else
		return (1);
	return (0);
}

static int ft_check_push(t_lst **a, t_lst **b, t_lst *aux1, int flag)
{
	t_lst *aux;

	if (flag == 2)
	{
		while (a[0])
		{
			aux = a[0]->next;
			if (a[0]->n == aux1->n)
				break;
			ft_push_b(a[0], b);
			a[0] = aux;
		}
		flag = 1;
	}
	if (flag == 0 && b[0])
	{
		while (b[0])
		{
			aux = b[0];
			b[0] = b[0]->next;
			aux->next = NULL;
			ft_push_a(a, aux);
		}
	}
	return (flag);
}

static int ft_check_a(t_lst **a)
{
	t_lst *aux;
	t_lst *aux1;

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

void ft_swap(t_lst *a, t_lst *b)
{
	t_lst *aux;
	t_lst *aux1;
	t_lst *aux2;
	t_lst *aux3;
	int flag;

	flag = 1;
	while (flag == 1)
	{
		if (b && b->next)
			aux3 = b->next;
		else
			aux3 = NULL;
		flag = ft_check_rotation(&a, &b, a->next, aux3);
		aux = a;
		if (aux->next)
			aux1 = aux->next;
		if (b)
		{
			aux2 = b;
			if (b->next)
				aux3 = b->next;
		}
		if ((flag == 1) && (aux->n > aux1->n) && aux3 && aux2 && (aux2->n < aux3->n) && ft_count(a) > 1 && ft_count(b) > 1)
		{
			ft_swap_s(a, b);
			flag = 1;
			ft_printf("ss\n");
		}
		else if ((flag == 1) && (aux->n > aux1->n) && ft_count(a) > 1)
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
				if (ft_count(a) < 4)
					flag = 1;
				else
					flag = 2;
				break ;
			}
			aux = aux->next;
		}
		if (flag == 2 || flag == 0)
			flag = ft_check_push(&a, &b, aux, flag);
		if (b)
			flag = 1;
		else
			flag = ft_check_a(&a);
	}
	aux = a;
	while (aux)
	{
		ft_printf("%d\n", aux->n);
		aux = aux->next;
	}
}
