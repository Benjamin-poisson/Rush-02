/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:14:11 by bepoisso          #+#    #+#             */
/*   Updated: 2024/08/03 15:30:28 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "./split/ft_split.c"

char	**ft_split(char *str, char *charset);

int	rush(char *str)
{
	char buf[1];
	int size = 1;
	int	fd = 0;
	int	count = 0;
	char *list = NULL;
	char **list2 = NULL;

	(void)str;
	fd = open("./numbers.dict", O_RDONLY );
	if (fd == -1)
		return (1);
	while(size != 0)
	{
		size = read(fd, buf, 1);
		count++;
	}
	close (fd);
	list = malloc((sizeof(char) * count )+ 1);
	if (list == NULL)
		return 1;
	fd = open("./numbers.dict", O_RDONLY );
	if (fd == -1)
		return (1);
	count = 0;
	size = 1;
	while(size != 0)
	{
		size = read(fd, buf, 1);
		list[count] = *buf;
		count++;
	}
	close (fd);
	list2 = ft_split(list, " :\n");
	count = 0;
	while(list2[count] != 0)
	{
		printf("%s\n", list2[count]);
		count++;
	}
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
