/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:50:04 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/11 15:23:23 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// int	a_builtin_cmd(char *cmd, char **args, t_env **env)
// {
// 	if (!ft_strncmp("cd", cmd, ft_max(ft_strlen(cmd), ft_strlen("cd"))))
// 		_cd(env, args[0]);
// 	else if (!ft_strncmp("export", cmd, ft_max(ft_strlen(cmd),
// 					ft_strlen("export"))))
// 		_export(env, args);
// 	else if (!ft_strncmp("env", cmd, ft_max(ft_strlen(cmd), ft_strlen("env"))))
// 		_env(env);
// 	else if (!ft_strncmp("pwd", cmd, ft_max(ft_strlen(cmd), ft_strlen("pwd"))))
// 		_pwd();
// 	else if (!ft_strncmp("echo", cmd, ft_max(ft_strlen(cmd),
// 					ft_strlen("echo"))))
// 		_echo(args);
// 	else if (!ft_strncmp("unset", cmd, ft_max(ft_strlen(cmd),
// 					ft_strlen("unset"))))
// 		_unset(env, args);
// 	// else if (ft_strncmp("exit",cmd, ft_strlen(cmd)))
// 	// 	/*exit*/;
// 	else
// 		return (0);
// 	return (1);
// }

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
		execute_cmd(cmd, env);
	}
	else
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
	}
}

void	cmd_execute(char **cmd_args, t_env **env, int n)
{
	int	i;

	i = -1;
	if (n == 0)
	{
		single_cmd_execute(cmd_args[0], cmd_args, env);
		return ;
	}
	while (++i < n)
	{
		if (a_builtin_cmd(cmd_args[0], cmd_args + 1, env))
			continue ;
		else
			process(cmd_args+i, env);
	}
	while (wait(NULL) != -1)
		;
}
