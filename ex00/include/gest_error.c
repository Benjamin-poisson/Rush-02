/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myacoub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:40:59 by myacoub           #+#    #+#             */
/*   Updated: 2024/08/04 15:43:16 by myacoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int	gest_max_numer(char **list)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 0;
	while (*list[j])
	{
		while (list[j][i])
			i++;
		if (i > res)
			res = i;
		j++;
	}
	return (res);
}

int	gest_error_dict(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 3)
	{
		while (av[1])
			i++;
		i--;
		if (!(av[1][i] == 't' && av[1][i -1] == 'c' && av[1][i -2] == 'i'
		&& av[1][i -3] == 'd' && av[1][i -4] == '.'))
			return (1);
		return (0);
	}
}

int	function_error_all(int ac, char **av)
{
	if (gest_error_dict(ac, av))
	{
		write(2, "Dict Error\n", 11);
		return (0);
	}
	if (gest_error(ac, av))
	{
		write(2, "Error\n", 6);
		return (0);
	}
}
