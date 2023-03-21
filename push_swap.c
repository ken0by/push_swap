/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:56:16 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/21 18:27:08 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	comp(int ac, char **s)
{
	int i;
	int j;

	j = ac - 1;
	while (j > 0)
	{
		i = 0;
		while (s[j][i])
		{
			if (s[j][i] >= '0' && s[j][i] <= '9')
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
	if (comp(ac, av) == 0)
		return (0);
	return (0);
}
