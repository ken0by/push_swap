/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:12:45 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/23 21:14:33 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check_revrot(t_lst **a, t_lst **b, t_lst *aux, t_lst *aux1)
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

int	ft_check_rotation(t_lst **a, t_lst **b, t_lst *aux, t_lst *aux1)
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

int	ft_check_push(t_lst **a, t_lst **b, t_lst *aux1, int flag)
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
	}
	if (flag == 0 && b[0])
	{
		while (b[0])
		{
			if (b[0] && ft_check_pa(a) == 1)
				break ;
			aux = (*b)->next;
			ft_push_a(a, *b);
			*b = aux;
		}
	}
	return (flag);
}

int	ft_check_a(t_lst **a)
{
	t_lst	*aux;
	t_lst	*aux1;

	aux = *a;
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

t_lst	*ft_swap(t_lst **a, t_lst **b)
{
	t_lst	*aux;
	int		flag;

	flag = 1;
	while (flag == 1)
	{
		flag = ft_ss(flag, *a, a, b);
		aux = ft_iter(a);
		if (aux->next && aux->n > (aux->next)->n)
			flag = 2;
		else
		{
			flag = ft_check_a(a);
			if (flag == 0 && !*b)
				return (*a);
		}
		ft_check_moves(a, b, aux, flag);
		if (*b)
			flag = 1;
		else
			flag = ft_check_a(a);
	}
	return (*a);
}
