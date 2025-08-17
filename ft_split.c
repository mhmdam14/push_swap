/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:38:12 by mal-moha          #+#    #+#             */
/*   Updated: 2025/07/21 10:38:12 by mal-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != ' ')
				i++;
		}
	}
	return (count);
}

char	*ft_substr(char *str)
{
	int		i;
	int		len;
	char	*result;

	i = 0;
	len = 0;
	while (str[len] && str[len] != ' ')
		len++;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	**free_split_result(char **result, int j)
{
	int	i;

	i = 1;
	while (i < j)
	{
		if (result[i])
			free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	char	**result;

	i = 0;
	j = 0;
	result = malloc(sizeof(char *) * (count_words(str) + 2));
	if (!result)
		return (NULL);
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i])
		{
			result[j] = ft_substr(&str[i]);
			if (!result[j])
				return (free_split_result(result, j));
			j++;
			while (str[i] && str[i] != ' ')
				i++;
		}
	}
	result[j] = NULL;
	return (result);
}
