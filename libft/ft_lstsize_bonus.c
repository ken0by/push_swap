/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:01:07 by rofuente          #+#    #+#             */
/*   Updated: 2023/01/19 19:07:51 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		x;
	t_list	*aux;

	x = 0;
	aux = lst;
	while (aux != NULL)
	{
		aux = aux->next;
		x++;
	}
	return (x);
}
