/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:09:19 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/09 19:45:45 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_assigned(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (arg[i] == '=')
			return (i);
	}
	return (0);
}

void	export_with_noarg(t_env **env)
{
	t_env	*node;
	int		fd;

	fd = 1;
	node = *env;
	while (node)
	{
		printf("declare -x %s\n", node->env_var);
		node = node->next;
	}
	return ;
}


void	export_to_env(t_env **env, char *arg, int var_len)
{
	t_env	*tmp;
	t_env	*node;

	tmp = *env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->env_var, arg, var_len))
		{
			tmp->env_var = arg;
			return ;
			// node = ft_lstnew(arg);
			// node->env_or_export = 0;
			// ft_lstadd_back(env, node);
		}
		tmp = tmp->next;
	}
	node = ft_lstnew(arg);
	node->env_or_export = 0;
	ft_lstadd_back(env, node);
}

void	export_only(t_env **env, char *arg)
{
	t_env	*tmp;
	t_env	*node;

	tmp = *env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->env_var, arg, ft_strlen(arg)))
			return ;
		tmp = tmp->next;
	}
	node = ft_lstnew(arg);
	node->env_or_export = 1;
	ft_lstadd_back(env, node);
	return ;
}

void	_export(t_env **env, char **args)
{
	int	i;

	i = 0;
	if (!args || !args[0])
	{
		export_with_noarg(env);
		return ;
	}
	while (args[i])
	{
		if (is_assigned(args[i]))
			export_to_env(env, args[i], is_assigned(args[i]));
		else
			export_only(env, args[i]);
		i++;
	}
}

/*
char	*get_var(t_env **env, char *arg)
{
	int		i;
	t_env	*node;
	t_env	*tmp;
	char	*var;

	printf("%s\n", arg);
	return (NULL);
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
*/
