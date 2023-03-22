/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:56:16 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/22 19:25:28 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ord(int n, char **s)
{
	int	j;

	j = 0;
	while (s[j] && j < n)
	{
		if ((s[j] > s[j + 1]) && n > 1 && s[j + 1] != '\0')
			sa(s, j);
		if (s[j - 1] > s[j])
			j = 0;
		else
			j++;
	}
	return (0);
}

static int	comp(int ac, char **s)
{
	int i;
	int j;

	j = ac - 1;
	while (j > 0)
	{
		i = 0;
		while (s[j][i])
		{
			if ((s[j][i] >= '0' && s[j][i] <= '9') || s[j][i] == ' ' || s[j][i] == '-' || s[j][i] == '+')
				i++;
			else
			{
				printf("Error\n");
				return (0);
			}
		}
		j--;
	}
	return (1);
}

int main(int ac, char **av)
{
	char	**s;

	if (comp(ac, av) == 0)
		return (0);
	s = fill_s(av);
	if (ord(ac, s) == 1)
		return (0);
	return (0);
}
