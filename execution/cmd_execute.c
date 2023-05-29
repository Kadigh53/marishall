/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:22:38 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/28 10:14:51 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_abs_cmd(char *cmd, char *path)
{
	char	**path_array;
	char	*tmp;
	int		i;

	i = 0;
	path_array = ft_split(path, ':');
	while (path_array[i])
	{
		tmp = ft_strjoin(path_array[i], "/");
		if (!access(ft_strjoin(tmp, cmd), X_OK))
		{
			// free(tmp);
			return (ft_strjoin(tmp, cmd));
		}
		i++;
	}
	free(tmp);
	return (NULL);
}

char	*get_cmd_path(char *cmd, t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->env_var, "PATH=", 5) && !tmp->env_or_export)
			return (get_abs_cmd(cmd, tmp->env_var + 5));
		tmp = tmp->next;
	}
	return (NULL);
}

int	a_builtin_cmd(char *cmd, char **args, t_env **env)
{
	if (!ft_strncmp("cd", cmd, ft_strlen(cmd)))
		_cd(env, args[0]);
	else if (ft_strncmp("echo", cmd, ft_strlen(cmd)))
		_echo(args);
	// else if (ft_strncmp("env",cmd, ft_strlen(cmd)))
	// 	_env(env);
	// else if (ft_strncmp("exit",cmd, ft_strlen(cmd)))
	// 	/*env*/;
	// else if (ft_strncmp("export",cmd, ft_strlen(cmd)))
	// 	_export(env, args);
	// else if (ft_strncmp("pwd",cmd, ft_strlen(cmd)))
	// 	_pwd();
	// else if (ft_strncmp("unset",cmd, ft_strlen(cmd)))
	// 	_unset(env, args);
	else
		return (0);
	return (1);
}

void	execute(char *cmd, char **cmd_args, t_env **env)
{
	char	*cmd_path;

	if (a_builtin_cmd(cmd, cmd_args, env))
		return ;
	else
	{
		cmd_path = get_cmd_path(cmd, env);
		if (!cmd_path)
			error("ERROR : command not found\n");
		if (execve(cmd_path, cmd_args, envlist_toarray(env)) == -1)
			error("ERROR:execve() failed\n");
	}
}
