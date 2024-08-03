/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:18:43 by bepoisso          #+#    #+#             */
/*   Updated: 2024/08/03 19:14:33 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdlib.h>
# include <fcntl.h>
#include <stdio.h>

char	**ft_split(char *str, char *charset);
int		file_count_char(char *file_name);
char	*create_list(char *file_name);
char	*ft_strcpy(char *dest, char *src);
int		ft_strlen(char *str);

typedef struct s_file
{
	int		file;
	char	buff[1];
	int		size;
} t_file ;

#endif
