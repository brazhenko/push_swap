/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a17641238 <a17641238@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:44:35 by a17641238         #+#    #+#             */
/*   Updated: 2020/02/14 11:44:35 by a17641238        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include <stdlib.h>

char	*strsub(char const *s, unsigned int start, size_t len)
{
	char *sub;

	if (!s || !(sub = ft_strnew(len)))
		return (NULL);
	return (ft_strncpy(sub, &s[start], len));
}