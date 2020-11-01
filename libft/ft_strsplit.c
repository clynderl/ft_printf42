/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:31:59 by clynderl          #+#    #+#             */
/*   Updated: 2019/09/16 19:08:32 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count_words(char const *s, char c)
{
	int i;
	int counter;

	i = 0;
	while (s[i] == c)
		i++;
	counter = 0;
	while (s[i] != '\0')
	{
		counter++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (counter);
}

static	int		word_len(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c)
		i++;
	return (i);
}

static	void	free_str(char **arr, int i)
{
	int j;

	j = 0;
	while (j < i - 1)
	{
		free(arr[j]);
		j++;
	}
	free(arr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		k;

	if (!s || !(arr = (char **)malloc(sizeof(*arr) * (count_words(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < count_words(s, c))
	{
		k = 0;
		if (!(arr[i] = ft_strnew(word_len(&s[j], c) + 1)))
		{
			free_str(arr, i);
			return (NULL);
		}
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			arr[i][k++] = s[j++];
		arr[i][k] = '\0';
	}
	arr[i] = 0;
	return (arr);
}
