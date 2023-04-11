/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:57:16 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/11 16:56:02 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* int puta(t_lst *a, t_lst **b)
{
	t_lst *aux;

	while (a)
	{
		if (a->next)
			aux = a->next;
		else
			return (0);
		if (a->n > aux->n)
		{
			aux = a;
			while (aux)
			{
				ft_printf("a -> %d\n", aux->n);
				aux = aux->next;
			}
			return (1);
		}
		ft_push_b(a, b);
		a = aux;
		aux = aux->next;
	}
	return (0);
} */

void ft_swap(t_lst *a, t_lst *b)
{
	t_lst *aux;
	t_lst *aux1;
	t_lst *aux2;
	t_lst *x;
	t_lst *y;
	int flag;

	aux = a;
	aux1 = 0;
	aux2 = NULL;
	flag = 1;
	while (flag == 1)
	{
		while (aux)
		{
			x = lstlast(a);
			if (b)
				y = lstlast(b);
			/* EL SEGMENTATION FAULT DA AQUI SI LO COMENTO TODO BIEN */
			/* if ((x->n < a->n) && (y->n < b->n))
			{
				ft_rotate_r(a, b);
				ft_printf("rr\n");
			} */
			else if (x->n < a->n)
			{
				ft_rotate_a(a);
				ft_printf("ra\n");
			}
			else if (b)
			{
				if (y->n < b->n)
				{
					ft_rotate_b(b);
					ft_printf("rb\n");
				}
			}
			if (aux->next)
				aux1 = aux->next;
			ft_printf("caca\n");
			if (aux1->next)
			{
				ft_printf("hola\n");
				aux2 = aux1->next;
			}
			if (aux->n > aux2->n && aux1->n > aux2->n && ft_count(a) > 1)
			{
				ft_swap_s(a, b);
				flag = 1;
				ft_printf("ss\n");
			}
			else if (aux->n > aux1->n && ft_count(a) > 1)
			{
				ft_swap_a(aux, aux1);
				flag = 1;
				ft_printf("sa\n");
			}
			else if (aux1->n > aux2->n && aux1->n > aux->n && ft_count(a) > 0)
			{
				// flag = puta(a, &b);
				aux = a;
				while (a)
				{
					if (a->next)
						aux = a->next;
					else
					{
						flag = 0;
						break;
					}
					if (a->n > aux->n)
					{
						flag = 1;
						break;
					}
					ft_push_b(a, &b);
					a = aux;
					aux = aux->next;
				}
				aux = a;
				break;
			}
			else
				flag = 0;
			aux = aux->next;
		}
		aux = b;
		while (aux)
		{
			if (aux->next)
				aux1 = aux->next;
			if (aux1->next)
				aux2 = aux1->next;
			if (aux->n < aux1->n && aux1->n > aux2->n && ft_count(a) > 1)
			{
				ft_swap_b(aux, b);
				flag = 1;
				ft_printf("sb\n");
			}
			aux = aux->next;
		}
		if (flag == 1)
			aux = a;
		else
		{
			while (b)
			{
				aux = b->next;
				ft_push_a(a, b);
				b = aux;
			}
			break;
		}
	}
}
