/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:14:11 by bepoisso          #+#    #+#             */
/*   Updated: 2024/08/04 11:44:13 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int main(int ac, char **av)
{
	char *list;
	char **big_list;
	char **number_list;
	char **word_list;

	list = NULL;
	big_list = NULL;
	number_list = NULL;
	word_list = NULL;
	if (gest_error(ac, av))
		return (1);
	if (gest_error_dict(ac, av))
		return (1);
	if (ac == 3)
		list = create_list(av[1]);
	list = create_list("./numbers.dict");
	big_list = ft_split(list, " +-:\n");
	split_list(big_list, &number_list, &word_list);
	sort_list(number_list, word_list);
	//traitement du 0;
	if (ac == 3)
		ft_print_power_of_ten(number_list, word_list, av[2]);
	ft_print_power_of_ten(number_list, word_list, av[1]);
	free(list);
	free_2d(big_list);
	free_2d(number_list);
	free_2d(word_list);
}
