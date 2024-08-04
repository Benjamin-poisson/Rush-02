/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_power2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 15:05:52 by bepoisso          #+#    #+#             */
/*   Updated: 2024/08/04 15:07:12 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	print_under_3digits(char **list_number, char **list_name, char *number)
{
	if (ft_strlen(number) == 3)
	{
		ft_print_hundred(list_number, list_name, &number[0]);
		ft_print_ten(list_number, list_name, &number[1], &number[2]);
	}
	else if (ft_strlen(number) == 2)
		ft_print_ten(list_number, list_name, &number[0], &number[1]);
	else if (ft_strlen(number) == 1)
		ft_print_unity(list_number, list_name, &number[0], 1);
	return ;
}

void	ft_print_power_of_ten2(char **list_number, char **list_name,
			char *number, t_i *n)
{
	if (ft_strlen(number) == (ft_strlen(list_number[n->j]) + 1))
	{
		ft_print_ten(list_number, list_name, &number[0], &number[1]);
		n->reduct = 2;
	}
	else if (ft_strlen(number) == (ft_strlen(list_number[n->j]) + 2))
	{
		ft_print_hundred(list_number, list_name, &number[0]);
		ft_print_ten(list_number, list_name, &number[1], &number[2]);
		n->reduct = 3;
	}
	if (number[0] != '0')
		ft_putstr(list_name[n->i - 1], 0);
}

void	ft_ppot1(char **list_number, char **list_name,	char *number, t_i *n)
{
	while (list_number[n->i++])
	{
		if (is_power_ten(list_number[n->i]))
		{
			if (n->j == -1)
				n->j = n->i;
			if (ft_strlen(list_number[n->i]) == ft_strlen(number))
			{
				ft_print_unity(list_number, list_name, &number[0], 0);
				if (number[0] != '0')
					ft_putstr(list_name[n->i], 0);
				n->reduct = 1;
				break ;
			}
			else if (n->i != 0 && ft_strlen(number)
				< ft_strlen(list_number[n->i]) && ft_strlen(number)
				> ft_strlen(list_number[n->j]))
			{
				ft_print_power_of_ten2(list_number, list_name, number, n);
				break ;
			}
			n->j = n->i;
		}
	}
	ft_print_power_of_ten(list_number, list_name, &number[n->reduct]);
}

void	ft_print_power_of_ten(char **list_number, char **list_name, char *numbr)
{
	t_i	n;

	n.reduct = 0;
	n.i = 0;
	n.j = -1;
	if (ft_strlen(numbr) <= 3)
	{
		print_under_3digits(list_number, list_name, numbr);
		return ;
	}
	ft_ppot1(list_number, list_name, numbr, &n);
}
