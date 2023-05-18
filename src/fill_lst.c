/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:16:36 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/18 13:14:53 by rofuente         ###   ########.fr       */
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
	if (!s)
		return (NULL);
	j = 0;
	while (s[j])
	{
		new = lstnew(ft_atoi(s[j]));
		lstadd_back(&a, new);
		j++;
	}
	ft_free_arr(s);
	return (a);
}

t_lst	*fill_lst(t_lst *a, char **b, int x)
{
	int	i;

	i = 1;
	while (i < x)
	{
		a = ft_split_lst(b, a, i);
		i++;
	}
	ft_plst(a);
	if (nbr_check(a) == 1)
	{
		ft_free_lst(&a);
		return (NULL);
	}
	return (a);
}
