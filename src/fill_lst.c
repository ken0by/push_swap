/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:16:36 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/10 15:26:43 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_count(t_lst *a)
{
	t_lst	*aux;
	int		i;

	i = 0;
	aux = a;
	while (aux)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}

static t_lst	*lstlast(t_lst *a)
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
	new->next = NULL;
	return (new);
}

t_lst	*fill_lst(t_lst *a, char **b, int x)
{
	int		i;
	int		j;
	char	**s;
	t_lst	*new;

	i = 1;
	while (i < x)
	{
		j = 0;
		while (b[i][j])
			j++;
		if (j == 1)
		{
			new = lstnew(ft_atoi(b[i]));
			lstadd_back(&a, new);
		}
		else
		{
			s = ft_split(b[i], ' ');
			j = 0;
			while (s[j])
			{
				new = lstnew(ft_atoi(s[j]));
				lstadd_back(&a, new);
				j++;
			}
		}
		i++;
	}
	i = nbr_check(a);
	if (i == 1)
	{
		ft_printf("Error\n");
		return (NULL);
	}
	return (a);
}
