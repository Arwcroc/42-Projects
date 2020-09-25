#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

# define ERROR_ARG "Error: No function selected\n"
# define ERROR_FUNC_UNKNOW "Error: Function unknow\n"
# define ERROR_NEED_ARG "Error: Need argument\n"

char	*ft_strcpy(char * dst, const char * src);
char	*ft_strdup(const char *s1);

int		ft_strcmp(const char *s1, const char *s2);

size_t	ft_strlen(const char *s);

ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);

#endif
