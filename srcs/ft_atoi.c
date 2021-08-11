/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzubat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:59:55 by hzubat            #+#    #+#             */
/*   Updated: 2021/08/04 15:28:16 by hzubat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_atoi(char *str)
{
	int	i;
	int	min;
	int	count;

	i = 0;
	min = 1;
	count = 0;
	while (str[count] != '\0')
	{
		if (!((str[count] >= '0' && str[count] <= '9') || (str[count] == '-'
					|| str[count] == '+')))
			return (0);
		if (str[count] == '-')
			min = min * (-1);
		while (str[count] >= '0' && str[count] <= '9')
		{
			i = i * 10 + ((str[count] - '0'));
			count++;
		}
		count++;
		if (i != 0)
			return (min * i);
	}
	return (0);
}
