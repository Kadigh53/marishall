/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:05:47 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/09 09:52:57 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_env_var(t_env **env, char *str)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->env_var, str, ft_strlen(str)))
			return (tmp->env_var);
		tmp = tmp->next;
	}
	return (NULL);
}

void	cd_with_abspath(char *arg)
{
	if (chdir(arg) == -1)
		error("ERROR:chdir() failed\n");
}
void	_cd(t_env **env, char *arg)
{
	char	*PWD;
	char	*OLDPWD;

	OLDPWD = ft_malloc(1024);
	OLDPWD = getcwd(OLDPWD, 1024);
	// printf(" cwd : %s\n", OLDPWD);
	// _export(env, ft_strjoin(ft_strdup("OLDPWD="), OLDPWD));
	if (!arg || (arg[0] == '~' && ft_strlen(arg) == 1))
	{
		if (chdir(get_env_var(env, "HOME=") + 5) == -1)
			write(2, "cd: HOME not set\n", 17);
	}
	else
	{
		if (!access(arg, F_OK))
			cd_with_abspath(arg);
		// else
		// {
		// 	printf("2 >> arg : %s", arg);
		// 	cd_fromcwd(env, arg);
		// }
	}
	PWD = ft_malloc(1024);
	getcwd(PWD, 1024);
	// printf("\n cwd : %s\n", PWD);
	// _export(env, ft_strjoin("PWD=", PWD));
	free(PWD);
	free(OLDPWD);
}
