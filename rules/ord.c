/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:57:16 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/29 18:19:17 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(t_lst *a, t_lst *b)
{
	t_lst *aux;
	t_lst *aux1;
	t_lst *aux2;
	t_lst *aux3;

	aux = a;
	aux1 = 0;
	aux2 = 0;
	while (aux)
	{
		if (aux->next)
			aux1 = aux->next;
		if (aux1->next)
			aux2 = aux1->next;
		if (aux->n > aux2->n && aux1->n > aux2->n && ft_count(a) > 1)
		{
			ft_swap_s(a, b);
			ft_printf("ss\n");
		}
		if (aux->n > aux1->n && ft_count(a) > 1)
		{
			ft_swap_a(aux, aux1);
			ft_printf("sa\n");
		}
		if (aux->n > aux1->n && aux1->n > aux2->n && ft_count(a) > 1)
		{
			ft_swap_b(aux, aux1);
			ft_printf("sb\n");
		}
		else if (aux1->n > aux2->n && aux1->n > aux->n && ft_count(a) > 0)
		{
			aux3 = a;
			aux2 = aux3->next;
			while (aux3)
			{
				if (aux3->n > aux2->n && ft_count(aux3) > 0)
				{
					aux1 = a;
					while (aux1)
					{
						if (aux1->n == aux3->n)
						{
							a = aux1;
							break ;
						}
						ft_push_b(aux1, b);
						aux1 = aux1->next;
					}
				}
				aux3 = aux3->next;
			}
		}
		aux = aux->next;
	}
}
