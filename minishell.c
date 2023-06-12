/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:35:54 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/06/12 11:37:36 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// #include "Includes/header.h"

// void	error(char *err_msg)
// {
// 	write(2,err_msg,10);
// 	exit(EXIT_FAILURE);
// }

int	main(int ac, char **av, char **env)
{
	char			*command;
	t_env			*env_lst;
	t_env			*tmp;
	char			**cmds;
	t_multi_cmds	*multi_cmds0;
	t_multi_cmds	*multi_cmds1;
	t_multi_cmds	*multi_cmds2;

	command = NULL;
	// extern char	**environ;
	(void)ac;
	(void)av;
	env_lst = set_env(env);
	tmp = env_lst;
	multi_cmds0 = calloc(1, sizeof(t_multi_cmds));
	multi_cmds1 = calloc(1, sizeof(t_multi_cmds));
	multi_cmds2 = calloc(1, sizeof(t_multi_cmds));
	multi_cmds0->next = multi_cmds1;
	multi_cmds1->next = multi_cmds2;
	multi_cmds2->next = NULL;
	while (1)
	{
		// command = readline("\033[32m marishall$ \033[0m");
		multi_cmds0->cmds = ft_split(" cat Makefile", ' ');
		multi_cmds1->cmds = ft_split("sleep 2", ' ');
		multi_cmds2->cmds = ft_split("ls ", ' ');
		// cmds = ft_split(command, ' ');
		cmds = NULL;
		cmd_execute(&multi_cmds0, cmds, &env_lst);
		break ;
		// if (!command)
		// 	continue ;
		add_history(command);
		free(command);
	}
	return (0);
}
