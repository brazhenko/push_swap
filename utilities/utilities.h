#ifndef UTILITIES_H
# define UTILITIES_H

#include <stddef.h>

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_numlen(int n, int minus);
int		ft_isspace(int c);
int		ft_isdigit(int c);

void		*xmalloc(size_t size);
char	*strsub(char const *s, unsigned int start, size_t len);
char	*ft_strncpy(char *dst, const char *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strnew(size_t size);
void		charptrptrdel(char **ptr);
char			**strsplitcharset(char const *s, char *charset);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
