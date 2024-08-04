/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils _ power.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:34:50 by jguaglio          #+#    #+#             */
/*   Updated: 2024/08/04 16:03:35 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	unique_zero(char **list_number, char **list_name, char *number)
{
	int	i;

	i = 0;
	if (ft_strlen(number) == 1 && number[0] == '0')
	{
		while (list_number[i])
		{
			if (list_number[i][0] == '0')
			{
				ft_putstr(list_name[i], 1);
				return ;
			}
			i++;
		}
	}
}

int	is_power_ten(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (number[0] != '1')
			return (0);
		if (i != 0 && number[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_unity(char **list_number, char **list_name,
			char *unity, int number)
{
	int	i;

	i = 0;
	if (unity[0] == '0')
		return ;
	while (list_number[i])
	{
		if (ft_strlen(list_number[i]) == 1)
		{
			if (list_number[i][0] == unity[0])
			{
				ft_putstr(list_name[i], number);
				return ;
			}
		}
		i++;
	}
}

void	ft_print_ten(char **list_number, char **list_name,
			char *ten, char *unity)
{
	int	i;

	i = -1;
	while (list_number[++i])
	{
		while (ten[0] == '1')
		{	
			if (ft_strlen(list_number[i]) == 2 && list_number[i][0] == ten[0]
				&& list_number[i][1] == unity[0])
			{
				ft_putstr(list_name[i++], 0);
				return ;
			}
			else
				i++;
		}
		if (ft_strlen(list_number[i]) == 2 && list_number[i][0] == ten[0]
			&& list_number[i][1] == '0')
		{
			ft_putstr(list_name[i], 0);
			ft_print_unity(list_number, list_name, unity, 0);
			return ;
		}
	}
	ft_print_unity(list_number, list_name, unity, 1);
}

void	ft_print_hundred(char **list_number, char **list_name, char *hundred)
{
	int	i;

	i = 0;
	if (hundred[0] == '0')
		return ;
	ft_print_unity(list_number, list_name, hundred, 0);
	while (list_number[i])
	{
		if (ft_strlen(list_number[i]) == 3 && is_power_ten(list_number[i]))
		{
			ft_putstr(list_name[i], 0);
			break ;
		}
		i++;
	}
}
