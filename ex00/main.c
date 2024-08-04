/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:14:11 by bepoisso          #+#    #+#             */
/*   Updated: 2024/08/04 12:18:34 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int main(int ac, char **av)
{
	t_list list;
	list.small = NULL;
	list.big = NULL;
	list.number = NULL;
	list.word = NULL;
	if (gest_error(ac, av))
		return (1);
	if (gest_error_dict(ac, av))
		return (1);
	if (ac == 3)
		list.small = create_list(av[1]);
	list.small = create_list("./numbers.dict");
	list.big = ft_split(list.small, " +-:\n");
	split_list(list.big, &list.number, &list.word);
	sort_list(list.number, list.word);
	//traitement du 0;
	if (ac == 3)
		ft_print_power_of_ten(list.number, list.word, av[2]);
	ft_print_power_of_ten(list.number, list.word, av[1]);
	free(list.small);
	free_2d(list.big);
	free_2d(list.number);
	free_2d(list.word);
}
