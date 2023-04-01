/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:57:16 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/01 20:57:35 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int puta(t_lst *a, t_lst *b)
{
	t_lst *aux;

	while (a)
	{
		if (a->next)
			aux = a->next;
		else
			return (0);
		if (a->n > aux->n)
			return (1);
		ft_push_b(a, &b);
		a = aux;
		aux = aux->next;
	}
	return (0);
}

void ft_swap(t_lst *a, t_lst *b)
{
	t_lst *aux;
	t_lst *aux1;
	t_lst *aux2;
	int flag;

	aux = a;
	aux1 = 0;
	aux2 = NULL;
	flag = 1;
	while (flag == 1)
	{
		while (aux)
		{
			if (aux->next)
				aux1 = aux->next;
			if (aux1->next)
				aux2 = aux1->next;
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
				flag = puta(a, b);
				break ;
			}
			else
				flag = 0;
			aux = aux->next;
		}
		ft_printf("flag -> %d\n", flag);
		aux = b;
		while (aux)
		{
			if (aux->next)
				aux1 = aux->next;
			if (aux1->next)
				aux2 = aux1->next;
			if (aux->n > aux1->n && aux1->n > aux2->n && ft_count(a) > 1)
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
			/* NO RELLENAS CORRECTAMENTE EL STACK B X ESO DA
			SEGMENTATION FAULT AQUI */
			ft_printf("%d\n", b->n);
			while (b)
			{
				ft_printf("Cabron\n");
				ft_push_a(a, b);
			}
			break ;
		}
	}
}
