/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliali <aaliali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 09:33:16 by aaliali           #+#    #+#             */
/*   Updated: 2026/01/15 14:57:02 by aaliali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static char	*nextword(char const **s, char c)
{
	char	*word;
	int		len;
	int		i;
	int		j;

	i = 0;
	while ((*s)[i] == c)
		i++;
	len = 0;
	while ((*s)[i + len] && (*s)[i + len] != c)
		len++;
	if (len == 0)
		return (NULL);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = (*s)[i + j];
		j++;
	}
	word[len] = '\0';
	(*s) += i + len;
	return (word);
}

static int	words(char const *s, char c)
{
	int	wd;

	wd = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			wd++;
			while (*s && *s != c)
				s++;
		}
	}
	return (wd);
}

static void	freetab(char **result, int i)
{
	while (i >= 0)
	{
		free(result[i]);
		i--;
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		nbrwords;
	int		i;

	if (!s)
		return (NULL);
	nbrwords = words(s, c);
	result = malloc(sizeof(char *) * (nbrwords + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < nbrwords)
	{
		result[i] = nextword(&s, c);
		if (!result[i])
		{
			freetab(result, i - 1);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
