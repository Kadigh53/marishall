/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:50:04 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/12 11:36:44 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_cmd(char **cmd, t_env **env)
{
	char	*cmd_path;
	char	**p;

	cmd_path = get_cmd_path(cmd[0], env);
	if (!cmd_path)
		error("ERROR : command not found\n");
	p = envlist_toarray(env);
	execve(cmd_path, cmd, p);
}

void	process(char **cmd, t_env **env)
{
	int	pid;
	int	fds[2];

	ft_pipe(fds);
	pid = ft_fork();
	if (pid == 0)
	{
		close(fds[0]);
		dup2(fds[1], STDOUT_FILENO);
		if (a_builtin_cmd(cmd[0], cmd + 1, env))
			exit(0);
		execute_cmd(cmd, env);
	}
	else
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
	}
}

void	cmd_execute(t_multi_cmds **multi_cmds, char **cmd_args, t_env **env)
{
	int				i;
	t_multi_cmds	*tmp;

	i = -1;
	tmp = *multi_cmds;
	if (!(*multi_cmds)->next)
	{
		single_cmd_execute(cmd_args[0], cmd_args, env);
		return ;
	}
	while (tmp->next)
	{
		process(tmp->cmds, env);
		tmp = tmp->next;
	}
	single_cmd_execute(tmp->cmds[0], tmp->cmds, env);
	while (wait(NULL) != -1)
		;
}
