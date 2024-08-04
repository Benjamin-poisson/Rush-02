/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 09:59:47 by bepoisso          #+#    #+#             */
/*   Updated: 2024/08/04 14:48:44 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

int	file_count_char(char *file_name)
{
	int		count;
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

char	*create_list(char *file_name)
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

void	split_list(char **list, char ***number_list, char ***word_list)
{
	t_incr	i;

	i.i = -1;
	i.i_word = 0;
	i.i_number = 0;
	*number_list = (char **)malloc(sizeof(char *) * (ft_strslen(list) / 2 + 1));
	*word_list = (char **)malloc(sizeof(char *) * (ft_strslen(list) / 2 + 1));
	while (list[++i.i])
	{
		if (i.i % 2 == 1)
		{
			(*word_list)[i.i_word] = malloc(sizeof(char)
					* (ft_strlen(list[i.i]) + 1));
			ft_strcpy((*word_list)[i.i_word++], list[i.i]);
		}
		else
		{
			(*number_list)[i.i_number] = malloc(sizeof(char)
					* (ft_strlen(list[i.i]) + 1));
			ft_strcpy((*number_list)[i.i_number++], list[i.i]);
		}
	}
	(*number_list)[i.i_number] = NULL;
	(*word_list)[i.i_word] = NULL;
}

void	free_2d(char **list)
{
	int	i;

	i = 0;
	while (list[i] != 0)
	{
		free(list[i]);
		i++;
	}
	free(list);
}

void	sort_list(char **number, char **word)
{
	int	i;
	int	j;

	i = 0;
	while (number[i + 1] != 0)
	{
		j = 0;
		while (number[j + 1] != 0)
		{
			if (ft_strlen(number[j]) > ft_strlen(number[j + 1]))
			{
				ft_swap(&number[j], &number[j + 1]);
				ft_swap(&word[j], &word[j + 1]);
			}
			j++;
		}
		i++;
	}
}
