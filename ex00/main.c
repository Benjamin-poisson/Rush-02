/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:14:11 by bepoisso          #+#    #+#             */
/*   Updated: 2024/08/03 17:38:11 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	files_count_char(char *file_name)
{
	int	count;
	t_file	files;
	
	count = 0;
	files.file = open(file_name, O_RDONLY);
	if (files.file == -1)
		return (-401);
	files.size = 1;
	while (files.size != 0)
	{
		files.size = read(files.file, files.buff, 1);
		count++;
	}
	close(files.file);
	return (count);
}

char *create_list(char *file_name)
{
	t_file	files;
	int		i;
	char	*list;

	i = 0;
	files.size = files_count_char(file_name);
	if (files.size == -401)
		return (NULL);
	list = malloc(sizeof(char) * files.size + 1);
	if (list == NULL)
		return (NULL);
	files.file = open(file_name, O_RDONLY);
	if (files.file == -1)
		return (NULL);
	files.size = 1;
	while (files.size != 0)
	{
		files.size = read(files.file, files.buff, 1);
		list[i] = *files.buff;
		i++;
	}
	close(files.file);
	return (list);
}

int	rush(char *str)
{
	int	count = 0;
	char *list = NULL;
	char **list2 = NULL;

	(void)str;
	list = create_list("./numbers.dict");
	list2 = ft_split(list, " +-:\n");
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
