/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:14:11 by bepoisso          #+#    #+#             */
/*   Updated: 2024/08/03 15:05:59 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	rush(char *str)
{
	char buf[1];
	int size = 1;
	int	fd = 0;

	(void)str;
	fd = open("./numbers.dict", O_RDONLY );
	if (fd == -1)
		return (1);
	while(size != 0)
	{
		size = read(fd, buf, 1);
		printf("%s", buf);
	}
	buf[size] = 0;
	close (fd);
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
