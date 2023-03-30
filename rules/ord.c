/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:57:16 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/30 19:41:07 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	puta(t_lst *a, t_lst *b)
{
	t_lst	*aux;

	while (a)
	{
		aux = a->next;
		if (a->n > aux->n)
			break ;
		ft_push_b(a, b);
		a = aux;
		aux = aux->next;
	}
}

void ft_swap(t_lst *a, t_lst *b)
{
	t_lst *aux;
	t_lst *aux1;
	t_lst *aux2;
	int		flag;

	aux = a;
	aux1 = 0;
	aux2 = 0;
	flag = 0;
	while (aux)
	{
		if (aux->next)
			aux1 = aux->next;
		ft_printf("1\n");
		if (aux1->next)
			aux2 = aux1->next;
		ft_printf("2\n");
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
		else if (aux->n > aux1->n && aux1->n > aux2->n && ft_count(a) > 1)
		{
			ft_swap_b(aux, aux1);
			flag = 1;
			ft_printf("sb\n");
		}
		else if (aux1->n > aux2->n && aux1->n > aux->n && ft_count(a) > 0)
		{
			puta(a, b);
			flag = 0;
			break ;
		}
		if (flag == 0)
		{
			ft_printf("Puta\n");
			aux = a;
		}
		else
			aux = aux->next;
	}
	if (flag == 1)
	{
		ft_printf("Itero\n");
		ft_swap(a, b);
	}
	else
	{
		while (b)
		{
			ft_push_a(a, b);
			b = b->next;
		}
	}
}
