/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:12:45 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/13 18:45:29 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void ft_check_rotation(t_lst *a, t_lst *b, t_lst *aux, t_lst *aux1)
{
	t_lst *aux2;
	t_lst *aux3;
	int flag;

	flag = 0;
	aux3 = NULL;
	aux = lstlast(a);
	if (a->next)
		aux2 = a->next;
	if (b)
		aux1 = lstlast(b);
	/* if (b->next)
		aux3 = b->next; */
	if ((a->n > aux->n) && (a->n > aux2->n) && (b->n > aux1->n) && (b->n > aux3->n))
		flag = 3;
	else if ((a->n > aux->n) && (a->n > aux2->n))
		flag = 1;
	else if (aux1 && aux3 && (b->n > aux1->n) && (b->n > aux3->n))
		flag = 2;
	if (flag == 1)
		a = ft_rotate_a(a);
	if (flag == 2)
		b = ft_rotate_b(b);
	if (flag == 3)
		ft_rotate_r(a, b);
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
	if (flag == 0)
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
		ft_check_rotation(a, b, a->next, aux3);
		aux = a;
		if (aux->next)
			aux1 = aux->next;
		if (b)
		{
			aux2 = b;
			if (b->next)
				aux3 = b->next;
		}
		if ((aux->n > aux1->n) && aux3 && (aux2->n < aux3->n) && ft_count(a) > 1 && ft_count(b) > 1 && flag == 1)
		{
			ft_swap_s(a, b);
			flag = 1;
			ft_printf("ss\n");
		}
		else if ((aux->n > aux1->n) && ft_count(a) > 1 && flag == 1)
		{
			ft_swap_a(aux, aux1);
			flag = 1;
			ft_printf("sa\n");
		}
		else if (aux3 && (aux2->n < aux3->n) && ft_count(b) > 1 && flag == 1)
		{
			ft_swap_b(aux2, aux3);
			flag = 1;
			ft_printf("sb\n");
		}
		else
			flag = 0;
		aux = a;
		while (aux)
		{
			if (aux->next)
				aux1 = aux->next;
			if (aux->n > aux1->n)
			{
				flag = 2;
				break;
			}
			aux = aux->next;
		}
		flag = ft_check_push(&a, &b, aux, flag);
	}
	aux = a;
	while (aux)
	{
		ft_printf("%d\n", aux->n);
		aux = aux->next;
	}
}
