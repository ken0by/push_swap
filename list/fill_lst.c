/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:16:36 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/24 17:47:07 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	lstadd_back(lst **a, lst *new)
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
	int	j;
	lst	*new;

	j = 1;
	while (j <= x)
	{
		new = lstnew(ft_atoi(b[j]));
		lstadd_back(&a, new);
		j++;
	}
	return (a);
}
