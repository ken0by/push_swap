/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:31:18 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/11 13:25:53 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rotate_a(t_lst *a)
{
	t_lst	*aux;

	aux = a;
	a = a->next;
	aux->next = NULL;
	lstadd_back(&a, aux);
}

void	ft_rotate_b(t_lst *b)
{
	t_lst	*aux;

	aux = b;
	b = b->next;
	aux->next = NULL;
	lstadd_back(&b, aux);
}

void	ft_rotate_r(t_lst *a, t_lst *b)
{
	ft_rotate_a(a);
	ft_rotate_b(b);
}
