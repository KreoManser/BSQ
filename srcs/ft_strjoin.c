/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzubat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:27:11 by hzubat            #+#    #+#             */
/*   Updated: 2021/08/11 16:28:13 by hzubat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char	*res;
	int		len1;
	int		len2;
	int		i;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!(res))
		return (NULL);
	i = 0;
	while (i < len1)
	{
		res[i] = str1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		res[len1 + i] = str2[i];
		i++;
	}
	res[len1 + i] = '\0';
	free(str1);
	return (res);
}
