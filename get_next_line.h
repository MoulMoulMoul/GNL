#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char		*get_next_line(int fd);
const char	*ft_strchr(const char *s, int c);
void		ft_strjoin(char **line, const char *s1, int bufsize);
size_t		ft_strlen(const char *s);

#endif