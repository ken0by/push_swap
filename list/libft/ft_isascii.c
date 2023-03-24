/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:06:30 by rofuente          #+#    #+#             */
/*   Updated: 2023/01/17 19:45:24 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int x)
{
	int	flag;

	flag = 1;
	if (x < 0 || x > 127)
		flag = 0;
	return (flag);
}

// int main()
// {
//     int x;

//     x = 128;
//     printf("%d\n", isascii(x));
//     printf("%d\n", ft_isascii(x));
//     return (0);
// }
