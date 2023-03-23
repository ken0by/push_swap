/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:14:01 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/23 16:55:35 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(char **a, int n)
{
	char	*aux;

	//aux = '\0';
	aux = a[n + 1];
	a[n + 1] = a[n];
	a[n] = aux;
	printf("sa\n");
	//return (a);
}

void	sb(char **a, char **b)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (a[i] && i < 2)
	{
		j = 0;
		while (a[i][j])
		{
			b[k][j] = a[i][j];
			j++;
		}
		b[k][j] = '\0';
		k++;
		i++;
	}
	b[k] = NULL;
	printf("sb\n");
}

void	ss(char **a, char **b, int n)
{
	sa(a, n);
	sb(a, b);
	printf("ss\n");
}
