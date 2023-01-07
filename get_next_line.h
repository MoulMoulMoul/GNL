#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *str, char c);
char	*fill_buffer(char *bufferleft, int fd);
int		count_line(char *str);
char	*cut_line(char *bufferleft);
char	*new_buff(char *bufferleft);
void	*ft_calloc(size_t n);

size_t	ft_strlen(const char *str);

#endif