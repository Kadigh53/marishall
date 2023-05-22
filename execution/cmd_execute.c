/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:22:38 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/22 17:37:19 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

char	get_abs_cmd(char *cmd, char *path)
{
	char	*path_array;
	char	*tmp;
	int		i;

	i = 0;
	path_array = ft_split(path, ':');
	while (path_array[i])
	{
		tmp = ft_strjoin(path_array[i], "/");
		if (!access(ft_strjoin(tmp, cmd), X_OK))
		{
			free(tmp);
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
		if (!ft_strncmp(tmp->env_var,"PATH=", 5) && !tmp->env_or_export)
			return (get_abs_cmd(cmd, tmp->env_var + 5));
		tmp = tmp->next;
	}
	return (NULL);
}

void	execute(char *cmd, char **cmd_args, t_env **env)
{
	char	*cmd_path;

	cmd_path = get_cmd_path(cmd, env);
	if (!cmd_path)
		error("ERROR : command not found\n");
	if (execve(cmd_path, cmd_args, envlist_toarray(env)) == -1)
		error("ERROR:execve() failed\n");
}