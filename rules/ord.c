/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:57:16 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/13 13:57:17 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
			/* if (aux->next)
				aux1 = aux->next;
			if (aux1->next)
				aux2 = aux1->next; */
			/* if ((x->n < a->n) && (y->n < b->n))
			{
				ft_rotate_r(a, b);
				ft_printf("rr\n");
			} */
			if ((x->n < a->n) || (a->n > aux1->n && a->n > aux2->n))
			{
				ft_rotate_a(a);
				ft_printf("ra\n");
				aux = a;
			}
			else if (b)
			{
				if (b->next)
					aux1 = aux->next;
				if (aux1->next)
					aux2 = aux1->next;
				if (y->n > b->n || (a->n > aux1->n && a->n > aux2->n))
				{
					ft_rotate_b(b);
					ft_printf("rb\n");
				}
			}
			if (aux->next)
				aux1 = aux->next;
			if (aux1->next)
				aux2 = aux1->next;
			else
			{
				flag = 0;
				break ;
			}
			/* PONER COMPROBACIONES SOLO PARA LOS DOS PRIMEROS NUMEROS */
			/* if (aux->n > aux2->n && aux1->n > aux2->n && ft_count(a) > 1 && ft_count(b) > 1)
			{
				ft_swap_s(a, b);
				flag = 1;
				ft_printf("ss\n");
			} */
			/* else if (aux->n > aux1->n && ft_count(a) > 1)
			{
				ft_swap_a(aux, aux1);
				flag = 1;
				ft_printf("sa\n");
			} */
			if ((aux1->n > aux2->n && aux1->n > aux->n && ft_count(a) > 0) || (aux2->n > aux->n && aux2->n > aux1->n && ft_count(a) > 0))
			{
				/* AL SOLO TENER COMPROBACIONES PARA LOS DOS PRIMEROS NUMEROS, SI ESTAN ORDENADOS ENTRAR EN UN BUCLE QUE VAYA COMPROBANDO
				QUE EL RESTO TAMBIEN ESTAN OREDENADOS, SINO LO ESTAN PASAR AL STACK B HASTA ESE NUMERO Y VOLVER A INICIALIZAR EL BUCLE */
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
			if (aux->n < aux1->n && aux1->n > aux2->n && ft_count(b) > 1)
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
