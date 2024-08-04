/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:28:33 by jguaglio          #+#    #+#             */
/*   Updated: 2024/08/04 11:12:30 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_sep(char *charset, char c);

int	ft_strlen_charset(char *charset, char *str, int j)
{
	int	i;

	i = 0;
	while (str[i + j])
	{
		if (ft_is_sep(charset, str[i + j]))
		{
			return (i);
		}
		i++;
	}
	return (i);
}

int	ft_is_sep(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_nbr_word(char *str, char *charset)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (ft_is_sep(charset, str[i]) == 0
			&& (ft_is_sep(charset, str[i + 1]) == 1 || str[i + 1] == '\0'))
			counter++;
		i++;
	}
	return (counter);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**str_final;
	int		i;
	int		indice_mot;

	i = 0;
	indice_mot = 0;
	str_final = malloc((ft_nbr_word(str, charset) + 1) * sizeof(char *));
	while (str[i])
	{
		if (!ft_is_sep(charset, str[i]))
		{
			str_final[indice_mot]
				= malloc((ft_strlen_charset(charset, str, i) + 1)
					* sizeof(char));
			ft_strncpy(str_final[indice_mot],
				&str[i], ft_strlen_charset(charset, str, i));
			indice_mot++;
			i += ft_strlen_charset(charset, str, i);
		}
		else
			i++;
	}
	str_final[indice_mot] = 0;
	return (str_final);
}
/*
int	main(void)
{
	char	**str;

	str = ft_split("aaabbbaaaccc", "ab");
	ft_lentab(str);
}

#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char *str, char *charset);

int		c_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		c_strctn(char *str1, char *str2, int at)
{
	int	len;
	int	i;

	len = c_strlen(str2);
	i = 0;
	while (i < len)
	{
		str1[at + i] = str2[i];
		i++;
	}
	str1[at + i] = 0;
	return (len + at);
}

char	*c_strautojoin(char **strs, char *sep)
{
	char	*str;
	int		len;
	int		seplen;
	int		i;
	int		j;

	len = 1;
	seplen = c_strlen(sep);
	i = 0;
	while (strs[i] != NULL)
	{
		len += c_strlen(strs[i]);
		if (strs[i + 1] != NULL)
			len += seplen;
		i++;
	}
	str = malloc(len * sizeof(char));
	i = 0;
	j = 0;
	while (strs[j])
	{
		i = c_strctn(str, strs[j++], i);
		if (strs[j])
			i = c_strctn(str, sep, i);
	}
	return (str);
}

int		main(void)
{
	char **tab;

	tab = ft_split("Ceci&est$un#####
#################################################
#####################################################
##################################################succes@!", "&$#@");
	printf("%s\n", c_strautojoin(tab, " "));
	tab = ft_split("Success", "CUT");
	printf("%s\n", c_strautojoin(tab, " "));
	tab = ft_split("Success", "");
	printf("%s\n", c_strautojoin(tab, " "));
	tab = ft_split("", "");
	printf("OK\n");
	tab = ft_split("", "CUT");
	printf("OK\n");
	tab = ft_split("       ", "       ");
	printf("OK\n");
	tab = ft_split("         ", "       ");
	printf("OK\n");
}*/
