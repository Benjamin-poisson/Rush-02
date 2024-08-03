/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myacoub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:40:59 by myacoub           #+#    #+#             */
/*   Updated: 2024/08/03 20:08:02 by myacoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	gest_error(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac > 3 || ac == 1)
	{
		write(1, "Error\n", 6);
		retrun (1);
	}
	j = ac -1;
	while (av[j][i])
	{
		if (av[j][i] < '0' || av[j][i] > '9')
		{
			write(1, "Error\n", 6);
			retrun (1);
		}
		i++;
	}
	return (0);
}
int	gest_error_dict(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[j][i])
	{
		if (av[j][i] < '0' || av[j][i] > '9')
		{
			write(1, "Error\n", 6);
			retrun (1);
		}
		i++;
	}
	return (0);
}
int	get_max_number(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 3)
	{
		while (av[1])
			i++;
		if (av[1][i] == 't' && av[1][i -1] == 'c' && av[1][i -2] == 'i' 
		&& av[1][i -3] == 'd' && av[1][i -4] == '.')
			return (0);
		write(1, "Error\n", 6);
		retrun (1);
	}
}
