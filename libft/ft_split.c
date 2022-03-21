/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:26:14 by smikayel          #+#    #+#             */
/*   Updated: 2022/03/17 20:48:25 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counting_word(char const *s, char c)
{
	int	index;
	int	count;

	count = 0;
	index = 0;
	if (!s && !c)
		return (-1);
	while (s[index] != '\0')
	{
		if (s[index] == c && index != 0 && s[index + 1] != c)
			count++;
		index++;
	}
	if (s[index - 1] != c)
		count += 1;
	return (count);
}

static char	**spl(char **sp_list, char const *s, char c)
{
	int		index;
	int		len;
	int		j;

	index = 0;
	j = 0;
	j = 0;
	while (s[index] != '\0')
	{
		if (s[index] != c)
		{
			len = 0;
			while (s[index] != '\0' && s[index] != c)
			{
				len++;
				index++;
			}
			sp_list[j] = ft_substr(s, index - len, len);
			j++;
		}
		while (s[index] == c)
			index++;
	}
	sp_list[j] = NULL;
	return (sp_list);
}

char	**ft_split(char const *s, char c)
{
	char	**sp_list;

	sp_list = (char **)malloc((counting_word(s, c) + 1) * sizeof(char *));
	if (!sp_list)
		return (NULL);
	if (s[0] == 0 && c == 0)
	{
		sp_list[0] = NULL;
		return (sp_list);
	}
	if (c != '\0')
	{
		sp_list = spl(sp_list, s, c);
	}
	else
	{
		sp_list[0] = ft_strdup(s);
		sp_list[1] = NULL;
	}
	return (sp_list);
}
