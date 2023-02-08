#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_get_line(char *buffer);
char	*ft_strjoin(char *buffer, char *str);
char	*ft_read_next_buffer(char *buffer);
size_t	ft_strlen(char *str);
char	*ft_read_buffer(int fd, char *buffer);
char	*ft_strchr(char *s, int c);

#endif