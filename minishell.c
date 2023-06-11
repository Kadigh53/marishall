/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:35:54 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/06/11 15:23:32 by aaoutem-         ###   ########.fr       */
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
	char	*command;
	t_env	*env_lst;
	t_env	*tmp;
	char	**cmds;

	// extern char	**environ;
	(void)ac;
	(void)av;
	env_lst = set_env(env);
	tmp = env_lst;
	while (1)
	{
		command = readline("\033[32m marishall$ \033[0m");
		// command = ft_strdup("ls ");
		// cmds = ft_split(command, ' ');
		// execute(cmds[0], cmds + 1, &env_lst);
		// printf("\n\n");
		// command = ft_strdup("export ");
		// cmds = ft_split(command, ' ');
		// execute(cmds[0], cmds + 1, &env_lst);
		// printf("\n\n");
		// command = ft_strdup("export bb ");
		// cmds = ft_split(command, ' ');
		// execute(cmds[0], cmds + 1, &env_lst);
		// printf("\n\n");
		// command = ft_strdup("export bb=bss ");
		cmds = ft_split(command, ' ');
		cmd_execute(cmds, &env_lst, 1);
		// break ;
		if (!command)
			continue ;
		add_history(command);
		free(command);
	}
	return (0);
}
