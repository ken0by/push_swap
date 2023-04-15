/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:16:36 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/15 22:10:06 by rodro            ###   ########.fr       */
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

static t_lst	*ft_split_lst(char **b, t_lst *a, int i)
{
	int		j;
	char	**s;
	t_lst	*new;

	s = ft_split(b[i], ' ');
	j = 0;
	while (s[j])
	{
		new = lstnew(ft_atoi(s[j]));
		lstadd_back(&a, new);
		j++;
	}
	return (a);
}

static t_lst	*ft_add_node(char **b, t_lst *a, int i)
{
	t_lst	*new;

	new = lstnew(ft_atoi(b[i]));
	lstadd_back(&a, new);
	return (a);
}

t_lst	*fill_lst(t_lst *a, char **b, int x)
{
	int		i;
	int		j;

	i = 1;
	while (i < x)
	{
		j = 0;
		while (b[i][j])
			j++;
		if (j == 1)
			a = ft_add_node(b, a, i);
		else
			a = ft_split_lst(b, a, i);
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
