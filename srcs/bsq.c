/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzubat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:26:29 by hzubat            #+#    #+#             */
/*   Updated: 2021/08/11 18:26:30 by hzubat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	display_bsq(t_params *par)
{
	int		a;
	int		b;

	a = par->max_i - par->max;
	while (a < par->max_i)
	{
		b = par->max_j - par->max;
		while (b < par->max_j)
		{
			par->map[a * (par->columns + 1) + b] = par->x;
			b++;
		}
		a++;
	}
	if (par->lines > 0 && par->columns > 0)
		ft_putstr(par->map);
	else
		ft_putstr_err("map error\n");
}
