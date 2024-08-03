/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:14:11 by bepoisso          #+#    #+#             */
/*   Updated: 2024/08/03 20:09:00 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	file_count_char(char *file_name)
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
	files.size = file_count_char(file_name);
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
	list[i] = 0;
	close(files.file);
	return (list);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strslen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	split_list(char **list, char ***number_list, char ***word_list)
{
	int	i;
	int	i_number;
	int	i_word;

	i = -1;
	i_word = 0;
	i_number = 0;
	*number_list = (char **)malloc(sizeof(char *) * (ft_strslen(list) / 2 + 1));
	*word_list = (char **)malloc(sizeof(char *) * (ft_strslen(list) / 2 + 1));
	while (list[++i])
	{void	split_list(char **list, char ***number_list, char ***word_list)
		if (i % 2 == 1)
		{
			(*word_list)[i_word] = malloc(sizeof(char) * (ft_strlen(list[i]) + 1));
			ft_strcpy((*word_list)[i_word++], list[i]);
		}
		else
		{
			(*number_list)[i_number] = malloc(sizeof(char) * (ft_strlen(list[i]) + 1));
			ft_strcpy((*number_list)[i_number++], list[i]);
		}
	}
	(*number_list)[i_number] = NULL;
	(*word_list)[i_word] = NULL;
}

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
	count = 0;
	split_list(list2, &nb, &word);
	int i = 0;
	while(i <= 41)
	{
		printf("%s\n", nb[i]);
		i++;
	}
	i = 0;
	while(i <= 41)
	{
		printf("%s\n", word[i]);
		i++;
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
