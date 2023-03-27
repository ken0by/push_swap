/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:16:36 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/27 17:16:26 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	ft_count(lst *a)
{
	lst	*aux;
	int	i;

	i = 0;
	aux = a;
	while (aux)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}

static lst	*lstlast(lst *a)
{
	lst	*aux;

	aux = a;
	while (aux)
	{
		if (aux->next == NULL)
			break ;
		aux = aux->next;
	}
	return (aux);
}

void	lstadd_back(lst **a, lst *new)
{
	lst	*aux;

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

lst	*lstnew(int	content)
{
	lst	*new;

	new = malloc(sizeof(lst));
	if (!new)
		return (NULL);
	new->n = content;
	new->next = NULL;
	return (new);
}

lst	*fill_lst(lst *a, char **b, int	x)
{
	int	i;
	lst	*new;

	i = 1;
	while (i < x)
	{
		new = lstnew(ft_atoi(b[i]));
		lstadd_back(&a, new);
		i++;
	}
	return (a);
}
