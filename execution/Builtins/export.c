/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:09:19 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/09 17:04:25 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	export_with_noarg(t_env **env)
{
	t_env	*node;
	int		fd;

	fd = 1;
	node = *env;
	// open("",O_RDWR | O_CREAT | O_APPEND, S_IRWXU);
	while (node)
	{
		printf("declare -x %s\n", node->env_var);
		// write(fd, "declare -x ", 11);
		// write(fd, node->env_var, ft_strlen(node->env_var));
		// write(fd, "\n", 1);
		node = node->next;
	}
	// close(fd);
	return ;
}

char	*get_var(t_env **env, char *arg)
{
	int		i;
	t_env	*node;
	t_env	*tmp;
	char	*var;

	i = 0;
	tmp = *env;
	while (arg[i] && arg[i] != '=')
		i++;
	if (!arg[i])
	{
		while (tmp)
		{
			if (!ft_strncmp(arg, tmp->env_var, ft_strlen(arg)))
				return (NULL);
			tmp = tmp->next;
		}
		node = ft_lstnew(arg);
		node->env_or_export = 1;
		ft_lstadd_back(env, node);
		return (NULL);
	}
	var = ft_substr(arg, 0, i);
	return (var);
}

void	_export(t_env **env, char **arg)
{
	t_env	*node;
	char	*arg_var;
	int		i;

	i = 0;
	// dup2();
	//	if there is export with  multiple args think about recurssif funcions
	node = *env;
	if (!arg || !arg[0])
	{
		export_with_noarg(env);
		return ;
	}
	arg_var = get_var(env, arg[0]);
	if (!arg_var)
		return ;
	while (node)
	{
		if (!ft_strncmp(get_var(env, node->env_var), arg_var,
				ft_strlen(arg_var)))
		{
			node->env_var = ft_strdup(arg[0]);
			// free(arg_var);
			return ;
		}
		node = node->next;
	}
	node = ft_lstnew(ft_strdup(arg[0]));
	ft_lstadd_back(env, node);
	// free(arg_var);
	// close(fd);
	return ;
}
