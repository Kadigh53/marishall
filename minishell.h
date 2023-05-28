/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 23:11:39 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/28 03:51:30 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct env
{
	char		*env_var;
	int			env_or_export;
	struct env	*prev;
	struct env	*next;
}	t_env;

t_env	*set_env(char **envp);
t_env	*ft_lstnew(void *content);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_strsnbr(char *s, char c, int para, int mode);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *s1);
size_t	ft_strlen(char *s);
void	*ft_malloc(size_t size);
char	*ft_strjoin(char *s1, char *s2);
int		ft_lstsize(t_env *lst);
void	ft_lstadd_back(t_env **lst, t_env *new);

/* *************BUILTIN CMDS**************/

void	_cd(t_env **env, char *arg);
void	_echo(char **args);
void	_env(t_env **env);
/*exit*/
void	_export(t_env **env, char **arg);
void	_pwd(void);
void	_unset(t_env **env, char **args);

/***************execute fcts**************/

void	execute(char *cmd, char **cmd_args, t_env **env);

/************error function *************/

void		error(char *err_msg);
void		*ft_memcpy(void *dst, void *src, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		execute(char *cmd, char **cmd_args, t_env **env);
char		**envlist_toarray(t_env **env);

#endif