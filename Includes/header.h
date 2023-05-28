/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:23:37 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/27 23:07:41 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H_
# define HEADER_H_

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct env
{
	char		*env_var;
	int			env_or_export;
	struct env	*prev;
	struct env	*next;
}	t_env;

t_env	**set_env(char **envp);
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
void    _echo(char **args);
void	_env(t_env **env);
/*exit*/
void	_export(t_env **env, char *arg);
void    _pwd(void);
void	_unset(t_env **env, char **args);
/***************execute fcts**************/
void	execute(char *cmd, char **cmd_args, t_env **env);
/************error function *************/
void	error(char *err_msg);

#endif