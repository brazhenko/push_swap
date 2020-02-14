/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a17641238 <a17641238@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:42:42 by a17641238         #+#    #+#             */
/*   Updated: 2020/02/14 11:42:42 by a17641238        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utilities.h"

char	*ft_strnew(size_t size)
{
	char		*ret;

	ret = (char *)xmalloc(sizeof(char) * (size + 1));
	ft_memset(ret, 0, sizeof(char) * (size + 1));
	return (ret);
}