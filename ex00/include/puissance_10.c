/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance_10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:34:50 by jguaglio          #+#    #+#             */
/*   Updated: 2024/08/04 12:18:13 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	unique_zero(char **list_number, char **list_name, char *number)
{
	int	i;

	i = 0;
	if (ft_strlen(number) == 1)
	{
		while (list_number[i])
		{
			if (list_number[i][0] == '0')
				ft_putstr(list_name[i]);
			i++;
		}
	}
}

int	is_power_ten(char * number)
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

void	ft_print_unity(char **list_number, char **list_name, char *unity)
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
				ft_putstr(list_name[i]);
				break ;
			}
		}
		i++;
	}
}
		

void	ft_print_ten(char **list_number, char **list_name, char *ten, char *unity)
{
	int	i;

	i = 0;
	while (list_number[i])
	{
		if (ft_strlen(list_number[i]) == 2 && list_number[i][0] == ten[0] && unity[0] == '0')
		{
			ft_putstr(list_name[i]);
			ft_print_unity(list_number, list_name, unity);
			return;
		}
		if (ten[0] == '1' && ft_strlen(list_number[i]) == 2 && list_number[i][0] == ten[0] && list_number[i][1] == unity[0])
		{
			ft_putstr(list_name[i]);
			return ;
		}
		i++;
	}
}

void	ft_print_hundred(char **list_number, char **list_name, char *hundred, char *ten, char *unity)
{
	int	i;

	i = 0;
	if (hundred[0] == '0')
	{
		ft_print_ten(list_number, list_name, ten, unity);
		return ;
	}
	if (hundred[0] != '1')
		ft_print_unity(list_number, list_name, hundred);
	while (list_number[i])
	{
		if (ft_strlen(list_number[i]) == 3 && is_power_ten(list_number[i]))
		{
			ft_putstr(list_name[i]);
			break ;
		}
		i++;
	}
	ft_print_ten(list_number, list_name, ten, unity);
}

void	print_under_3digits(char **list_number, char **list_name, char *number)
{
	if (ft_strlen(number) == 3)
		ft_print_hundred(list_number, list_name, &number[0], &number[1], &number[2]);
	else if (ft_strlen(number) == 2)
		ft_print_ten(list_number, list_name, &number[0], &number[1]);
	else if (ft_strlen(number) == 1)
		ft_print_unity(list_number, list_name, &number[0]);
	return ;
}

void	ft_print_power_of_ten2(char **list_number, char **list_name, char *number,
				t_incrementeur *n, int *reduction)
{
		if (ft_strlen(number) == (ft_strlen(list_number[n->j]) + 1))
		{
				ft_print_ten(list_number, list_name, &number[0], &number[1]);
				*reduction = 2;
		}
		else if (ft_strlen(number) == (ft_strlen(list_number[n->j]) + 2))
		{
				ft_print_hundred(list_number, list_name, &number[0], &number[1], &number[2]);
				*reduction = 3;
		}
		if (number[0] != '0')
			ft_putstr(list_name[n->i - 1]);
}

char	*ft_print_power_of_ten(char **list_number, char **list_name, char *number)
{
	t_incrementeur n;
	int	reduction;

	reduction = 0;
	n.i = 0;
	n.j = -1;
	if (ft_strlen(number) <= 3)
	{
		print_under_3digits(list_number, list_name, number);
		return (number);
	}
	while (list_number[n.i++])
	{
		if (is_power_ten(list_number[n.i]))
		{
			if (n.j == -1)
				n.j = n.i;
			if (ft_strlen(list_number[n.i]) == ft_strlen(number))
			{
				ft_print_unity(list_number, list_name, &number[0]);
				if (number[0] != '0')
					ft_putstr(list_name[n.i]);
				reduction = 1; 
				break ;
			}
			else if (n.i != 0 && ft_strlen(number) < ft_strlen(list_number[n.i]) &&
					   	ft_strlen(number) > ft_strlen(list_number[n.j]))
			{
				ft_print_power_of_ten2(list_number, list_name, number, &n, &reduction);
				break ;
			}
			n.j = n.i;	
		}
	}
	ft_print_power_of_ten(list_number, list_name, &number[reduction]);
	return (number);
}
/*
int	main(void)
 {
 	char	*l1[] = {"2","3","30","101", "100", "1000", "1000000", 0};
 	char	*l2[] = {"deux","trois","trente","cent-un", "cent", "mille", "million"};
  	char	nbr[] = "2330132";

 	ft_print_power_of_ten(l1, l2, nbr);
 }
*/
