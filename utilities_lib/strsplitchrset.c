/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplitchrset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a17641238 <a17641238@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:42:49 by a17641238         #+#    #+#             */
/*   Updated: 2020/02/14 11:42:49 by a17641238        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"
#include "utilities.h"

static int		is_separator(char c, char *charset)
{
	if (!c)
		return (1);
	while (*charset)
		if (*charset++ == c)
			return (1);
	return (0);
}

static size_t	cntwords(const char *s, char *charset)
{
	size_t words;
	size_t i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (!is_separator(s[i], charset) && is_separator(s[i + 1], charset))
			words++;
		i++;
	}
	return (words);
}

static void		getwords(char **arr, const char *s, char *charset)
{
	size_t i;
	size_t j;
	size_t len;

	len = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (!is_separator(s[i], charset))
			len++;
		else if (len)
		{
			arr[j] = strsub(s, i - len, len);
			j++;
			len = 0;
		}
		i++;
	}
	arr[j] = strsub(s, i - len, len);
}

char			**strsplitcharset(char const *s, char *charset)
{
	size_t	wrdcnt;
	char	**sp;

	if (!s)
		return (NULL);
	wrdcnt = cntwords(s, charset);
	sp = (char**)xmalloc(sizeof(char*) * wrdcnt + 1);
	getwords(sp, s, charset);
	sp[wrdcnt] = NULL;
	return (sp);
}
