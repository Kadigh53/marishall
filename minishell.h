#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
# include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>


size_t		ft_strlen(char *s);
char		*ft_strdup(char *s1);
void		*ft_memcpy(void *dst, void *src, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void        error(char *err_msg);
void        *ft_malloc(size_t size);


#endif