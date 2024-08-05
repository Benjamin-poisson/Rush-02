/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:14:11 by bepoisso          #+#    #+#             */
/*   Updated: 2024/08/04 18:26:14 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i])
		return (s1[i]);
	else
		return (-s2[i]);
}

void	ultimate_free(t_list list)
{
	free(list.small);
	free_2d(list.big);
	free_2d(list.number);
	free_2d(list.word);
}

int	if_nice_dict(t_list list)
{
	int	i;

	i = 1;
	while (list.word[i] != 0)
	{
		if (ft_strcmp(list.word[i], list.word[0]) != 0)
			return (0);
		i++;
	}
	ft_putstr(list.word[0], 1);
	return (1);
}

void	rush(int ac, char **av, t_list list)
{
	if (ac == 3)
		list.small = create_list(av[1]);
	else
		list.small = create_list("numbers.dict");
	list.big = ft_split(list.small, " +-:\t\n\r\v\f");
	split_list(list.big, &list.number, &list.word);
	sort_list(list.number, list.word);
	if (gest_max_numer(list.number, ac, av))
		return ;
	if (if_nice_dict(list))
	{
		ultimate_free(list);
		return ;
	}
	if (ac == 3)
	{
		unique_zero(list.number, list.word, av[2]);
		ft_print_power_of_ten(list.number, list.word, av[2]);
	}
	else
	{
		ft_print_power_of_ten(list.number, list.word, av[1]);
		unique_zero(list.number, list.word, av[1]);
	}
	ultimate_free(list);
}

int	main(int ac, char **av)
{
	t_list	list;

	list.small = NULL;
	list.big = NULL;
	list.number = NULL;
	list.word = NULL;
	if (function_error_all(ac, av))
		return (1);
	rush(ac, av, list);
	write(1, "\n", 1);
	return (0);
}
