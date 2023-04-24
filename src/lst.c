/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:29:20 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/24 17:22:41 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_lst	*lstlast(t_lst *a)
{
	t_lst	*aux;

	aux = a;
	while (aux)
	{
		if (aux->next == NULL)
			break ;
		aux = aux->next;
	}
	return (aux);
}

void	lstadd_back(t_lst **a, t_lst *new)
{
	t_lst	*aux;

	if (!a)
		return ;
	if (!*a)
	{
		*a = new;
		return ;
	}
	aux = lstlast(*a);
	aux->next = new;
}

t_lst	*lstnew(int content)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->n = content;
	new->p = 0;
	new->next = NULL;
	return (new);
}

t_lst	*ft_free_lst(t_lst **a)
{
	t_lst	*aux;

	while (*a)
	{
		aux = *a;
		*a = (*a)->next;
		aux->n = 0;
		aux->p = 0;
		aux->next = NULL;
		free (aux);
	}
	free (*a);
	return (*a);
}

void	ft_free_node(t_lst **a)
{
	t_lst *aux;

	aux = *a;
	(*a)->n = 0;
	(*a)->p = 0;
	(*a)->next = NULL;
	*a = aux;
}
