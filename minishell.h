/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 23:11:39 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/11 15:18:08 by aaoutem-         ###   ########.fr       */
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
t_env	*ft_lstnew(char *content);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_strsnbr(char *s, char c, int para, int mode);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *s1);
size_t	ft_max(size_t a, size_t b);
size_t	ft_strlen(char *s);
void	*ft_malloc(size_t size);
char	*ft_strjoin(char *s1, char *s2);
int		ft_lstsize(t_env *lst);
void	ft_lstadd_back(t_env **lst, t_env *new);
void	*ft_memcpy(void *dst, void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);

/*_______________________________________*/

int		ft_fork(void);
void	ft_pipe(int pipefds[]);

/*________________BUILTIN CMDS_____________*/

void	_cd(t_env **env, char *arg);
void	_echo(char **args);
void	_env(t_env **env);
/*void	exit(int a);         */
void	_export(t_env **env, char **arg);
void	_pwd(void);
void	_unset(t_env **env, char **args);

/*_________________execute fcts_____________*/

void	single_cmd_execute(char *cmd, char **cmd_args, t_env **env);
int		a_builtin_cmd(char *cmd, char **args, t_env **env);
void	execute(char *cmd, char **cmd_args, char **env);
char	*get_cmd_path(char *cmd, t_env **env);
char	**envlist_toarray(t_env **env);
char	*get_cmd_path(char *cmd, t_env **env);
char	*get_abs_cmd(char *cmd, char *path);

/*________________error function_______________*/

void		error(char *err_msg);
void	cmd_execute(char **cmd_args, t_env **env, int n);
char		**envlist_toarray(t_env **env);

#endif