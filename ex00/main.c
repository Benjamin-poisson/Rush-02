/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:14:11 by bepoisso          #+#    #+#             */
/*   Updated: 2024/08/04 10:34:51 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	rush(char *str)
{
	int	count = 0;
	char *list = NULL;
	char **list2 = NULL;
	char **nb = NULL;
	char **word = NULL;

	(void)str;
	list = create_list("./numbers.dict");
	list2 = ft_split(list, " +-:\n");
	free(list);
	count = 0;
	split_list(list2, &nb, &word);
	sort_list(nb, word);
	int i = 0;
	while(nb[i] != 0 || word[i] != 0)
	{
		printf("%s\n", nb[i]);
		printf("%s\n", word[i]);
		i++;
	}
	free_2d(nb);
	free_2d(word);
	return (0);
}


int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	if (rush(av[1]))
	{
		write(1, "ERROR\n", 6);
		return (1);
	}
	return (0);
}
