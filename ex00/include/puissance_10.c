/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance_10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:34:50 by jguaglio          #+#    #+#             */
/*   Updated: 2024/08/03 19:05:47 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] > s2[i])
			return ((int)(s1[i] - s2[i]));
		else if (s1[i] < s2[i])
			return (-(int)(s2[i] - s1[i]));
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, " ", 1);
}

void	ft_print_unity(char **list_number, char **list_name, char *unity)
{
	int	i;

	i = 0;
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
		if (ft_strlen(list_number[i]) == 2 && list_number[i][0] == ten[0] && list_number[i][1] == '0')
		{
			ft_putstr(list_name[i]);
			break ;
		}
		i++;
	}
	ft_print_unity(list_number, list_name, unity);
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
		if (ft_strlen(list_number[i]) == 3) // et si cest bien 100 et pas 101
		{
			ft_putstr(list_name[i]);
			break ;
		}
		i++;
	}
	ft_print_ten(list_number, list_name, ten, unity);
}



char	*ft_print_power_of_ten(char **list_number, char **list_name, char *number)
{
	int	i;
	int	reduction;

	i = 0;
	if (ft_strlen(number) <= 3)
		return (number);
	while (list_number[i])
	{
		if (ft_strlen(list_number[i]) == ft_strlen(number))
		{
			ft_print_unity(list_number, list_name, &number[0]);
			ft_putstr(list_name[i]);
			reduction = 1; 
			break;
		}
		else if (i !=0 && ft_strlen(number) < ft_strlen(list_number[i]) && ft_strlen(number) > ft_strlen(list_number[i - 1]))
		{	
			if (ft_strlen(number) == (ft_strlen(list_number[i - 1]) + 1))
			{
				ft_print_hundred(list_number, list_name,"0", &number[0], &number[1]);
				reduction = 2;
			}
			else if (ft_strlen(number) == (ft_strlen(list_number[i - 1]) + 2))
			{
				ft_print_hundred(list_number, list_name, &number[0], &number[1], &number[2]);
				reduction = 3;
			}
			ft_putstr(list_name[i - 1]);
			break ;
		}
		i++;
	}
	ft_print_power_of_ten(list_number, list_name, &number[reduction]);
	return (number);
}

int	main(void)
{
	char	*l1[] = {"2","3","30", "100", "1000", "1000000", 0};
	char	*l2[] = {"deux","trois","trente", "cent", "mille", "million"};
	char	nbr[] = "2330132";

	ft_print_power_of_ten(l1, l2, nbr);
}


