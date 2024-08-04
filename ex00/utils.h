/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:18:43 by bepoisso          #+#    #+#             */
/*   Updated: 2024/08/04 11:13:05 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include <stdio.h>

//___________STRING___________
char	**ft_split(char *str, char *charset);
char	*ft_strcpy(char *dest, char *src);
int		ft_strlen(char *str);
int		ft_strslen(char **str);
void	ft_putstr(char *str);
void	ft_swap(char **a, char **b);
//___________LIST___________
int		file_count_char(char *file_name);
char	*create_list(char *file_name);
void	split_list(char **list, char ***number_list, char ***word_list);
void	free_2d(char **list);
void	sort_list(char **number, char **word);
//___________POWER___________
char	*ft_print_power_of_ten(char **list_number, char **list_name, char *number);
void	ft_print_unity(char **list_number, char **list_name, char *unity);
void	ft_print_ten(char **list_number, char **list_name, char *ten, char *unity);
void	ft_print_hundred(char **list_number, char **list_name, char *hundred, char *ten, char *unity);
void	ft_print_power_of_ten2(char **list_number, char **list_name, char *number,
				t_incrementeur *n, int *reduction);
void	print_under_3digits(char **list_number, char **list_name, char *number);
int		is_power_ten(char * number);
//___________ERROR___________
int		get_max_number(int ac, char **av);
int		gest_error(int ac, char **av);
int		gest_error_dict(int ac, char **av);

typedef struct s_file
{
	int		file;
	char	buff[1];
	int		size;
} t_file ;

typedef	struct s_incrementeur
{
	int	i;
	int	j;
} t_incrementeur;

#endif
