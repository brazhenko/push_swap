/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a17641238 <a17641238@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:43:01 by a17641238         #+#    #+#             */
/*   Updated: 2020/02/14 11:43:15 by a17641238        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# include <stddef.h>

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_numlen(int n, int minus);
int		ft_isspace(int c);
int		ft_isdigit(int c);

void	*xmalloc(size_t size);
char	*strsub(char const *s, unsigned int start, size_t len);
char	*ft_strncpy(char *dst, const char *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strnew(size_t size);
void	charptrptrdel(char **ptr);
char	**strsplitcharset(char const *s, char *charset);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	max(size_t x, size_t y);

#endif
