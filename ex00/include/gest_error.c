/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:40:59 by myacoub           #+#    #+#             */
/*   Updated: 2024/08/04 16:53:58 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

int	gest_error(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac > 3 || ac == 1)
		return (1);
	j = ac -1;
	while (av[j][i])
	{
		if (av[j][i] < '0' || av[j][i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	gest_max_numer(char **list, int ac, char **av)
{
	t_i	i;

	i.i = 0;
	i.j = -1;
	i.size = 0;
	while (list[i.i] != 0)
		i.i++;
	i.size = ft_strlen(list[i.i - 1]);
	if (i.size < ft_strlen(av[ac - 1]))
	{
		write(2, "Error", 6);
		return (1);
	}
	return (0);
}

int	gest_error_dict(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 3)
	{
		while (av[1][i])
			i++;
		i--;
		if (!(av[1][i] == 't' && av[1][i -1] == 'c' && av[1][i -2] == 'i'
		&& av[1][i -3] == 'd' && av[1][i -4] == '.'))
			return (1);
	}
	return (0);
}

int	function_error_all(int ac, char **av)
{
	if (gest_error_dict(ac, av))
	{
		write(2, "Dict Error\n", 11);
		return (1);
	}
	if (gest_error(ac, av))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
