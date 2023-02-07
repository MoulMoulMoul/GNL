#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

size_t	ft_strlen(const char *s);
char	*ft_calloc(size_t nmemb, size_t size);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
#endif