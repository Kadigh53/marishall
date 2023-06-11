/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:22:38 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/11 15:17:35 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	single_execute(char *cmd, char **cmd_args, char **env)
{
	int	pid;

	pid = ft_fork();
	if (pid == 0)
	{
		if (execve(cmd, cmd_args, env) == -1)
			printf("error:execve failed \n");
		// exit(1);
	}
	// (void)env;
	// printf("%s\n", cmd);
	wait(NULL);
}

void	single_cmd_execute(char *cmd, char **cmd_args, t_env **env)
{
	char	*cmd_path;
	char	**p;

	if (a_builtin_cmd(cmd, cmd_args + 1, env))
		return ;
	else
	{
		cmd_path = get_cmd_path(cmd, env);
		if (!cmd_path)
			error("ERROR : command not found\n");
		p = envlist_toarray(env);
		single_execute(cmd_path, cmd_args, p);
	}
}
