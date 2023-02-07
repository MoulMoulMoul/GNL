#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

size_t	ft_strlen(const char *s);
char	*ft_callocs(size_t nmemb, size_t size);
char	*get_next_line(int fd);
char	*ft_strjoins(char *s1, char *s2, size_t len);
#endif