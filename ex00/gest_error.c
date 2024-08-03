/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myacoub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:40:59 by myacoub           #+#    #+#             */
/*   Updated: 2024/08/03 17:51:21 by myacoub          ###   ########.fr       */
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

int	get_max_number(char **list)
{
	int	i;
	int	j;
	int	size;
	while (list[j])
	{
		i = 0;
		while (list[j][i])
			i++;
		if (size < i)
			size = i;
		j++;
	}
	return (size);
}
