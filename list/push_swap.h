/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:39:32 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/24 17:46:05 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/* NO SE SI IMPLEMENTAR LA LIBFT O NO */
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/gnl/get_next_line.h"

typedef struct caca
{
	int			n;
	int			p;
	struct caca	*next;
}	lst;

lst	*fill_lst(lst *a, char **b, int	x);
lst	*lstnew(int	content);

#endif
