/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:04:54 by rofuente          #+#    #+#             */
/*   Updated: 2023/06/13 16:00:09 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check(t_lst *a)
{
	t_lst	*aux;
	t_lst	*aux1;

	aux = a;
	while (aux)
	{
		if (!aux->next)
			break ;
		aux1 = aux->next;
		if (aux->n != aux1->n)
			return (0);
		aux = aux->next;
	}
	return (1);
}

int	ft_no_argv(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			k++;
		i++;
	}
	if (k == 0)
		return (1);
	return (0);
}

int	ft_check_maxmin(char *s)
{
	int	j;

	j = ft_strlen_no_s(s);
	if (j == 10 || (j == 11 && s[0] == '-'))
	{
		if (s[0] == '-')
		{
			if (ft_strncmp(s, ft_itoa(-2147483648), 11) > 0)
				return (0);
		}
		else
			if (ft_strncmp(s, ft_itoa(2147483647), 10) > 0)
				return (0);
	}
	if (j > 11 || (j == 11 && s[0] != '-'))
		return (0);
	return (1);
}
