/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:13:54 by hait-hsa          #+#    #+#             */
/*   Updated: 2022/10/20 22:07:31 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_numb(long int n)
{
	int	i;

	i = 1;
	while (1)
	{
		if (n < 0)
		{
			i++;
			n *= -1;
		}
		n = n / 10;
		if (n)
			i++;
		else
			break ;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			i;
	int			x;
	long int	cast;
	char		*arr;

	cast = (long int)n;
	x = 0;
	i = ft_check_numb(cast);
	arr = malloc(((sizeof(char) * i) + 1));
	if (!arr)
		return (NULL);
	if (cast < 0)
	{
		arr[0] = '-';
		cast *= -1;
		x = 1;
	}
	arr[i] = 0;
	i--;
	while (i >= x)
	{
		arr[i--] = (cast % 10) + 48;
		cast = cast / 10;
	}
	return (arr);
}
