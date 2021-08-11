/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzubat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:26:35 by hzubat            #+#    #+#             */
/*   Updated: 2021/08/11 20:45:26 by hzubat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_read_file(char *file)
{
	int		fd;
	char	buf[BUF_SIZE + 1];
	int		r;
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	else
	{
		str = (char *)malloc(sizeof(char));
		if (!(str))
			return (NULL);
		str[0] = '\0';
		r = read(fd, buf, BUF_SIZE);
		while (r)
		{
			r = read(fd, buf, BUF_SIZE);
			str = ft_strjoin(str, buf);
		}
		buf[r] = '\0';
	}
	if (close(fd) == -1)
		return (NULL);
	return (str);
}

int	ft_display_error(void)
{
	ft_putstr_err("map error\n");
	return (0);
}

int	start_bsq(char *file_name)
{
	char		*map;
	t_params	*par;

	map = ft_read_file(file_name);
	if (!(map))
		return (ft_display_error());
	par = (t_params *)malloc(sizeof(t_params));
	if (!(par))
		return (0);
	if (!is_valid(par, map))
		return (ft_display_error());
	else
	{
		par->max = 0;
		par->max_i = 0;
		par->max_j = 0;
		if (!parse_map(par))
			return (0);
		display_bsq(par);
	}
	return (1);
}

int	ft_display_standard(void)
{
	char		buf[BUF_SIZE + 1];
	char		*map;
	t_params	*par;

	map = (char *)malloc(sizeof(char));
	if (!(map))
		return (0);
	map[0] = '\0';
	while ((read(0, buf, BUF_SIZE)))
		map = ft_strjoin(map, buf);
	par = (t_params *)malloc(sizeof(t_params));
	if ((!(par)) || !is_valid(par, map))
		return (ft_display_error());
	else
	{
		par->max = 0;
		par->max_i = 0;
		par->max_j = 0;
		if (!parse_map(par))
			return (0);
		display_bsq(par);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int			i;

	if (ac == 1)
		ft_display_standard();
	else
	{
		i = 1;
		while (i < ac)
		{
			start_bsq(av[i++]);
			if (i != ac)
				ft_putstr("\n");
		}
	}
	return (0);
}
