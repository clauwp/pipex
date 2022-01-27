#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <stddef.h>
# include <stdlib.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(const char *s, char c);
size_t	ft_strlen(const char *s);

#endif