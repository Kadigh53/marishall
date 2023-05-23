/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadigh <kadigh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:05:47 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/23 02:27:32 by kadigh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/header.h"

char	*cd_home(t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->env_var, "HOME=", 5))
			return (tmp->env_var);
		tmp = tmp->next;
	}
	// what if there is no home env_var
	return (NULL);
}

void	cd_with_abspath(char *arg)
{
	if (chdir(arg) == -1)
		error("ERROR:chdir() failed\n");
	// updat the PWD and OLDPWD env_var
}

void	cd_fromcwd(char *arg)
{
	char	*path;
	char	*cwd;
/*
what if . / or ../ ~ in arg
*/
	cwd = ft_malloc(1024);
	if (getcwd(cwd, 1024))
		error(""); //do something 
	cwd = ft_strjoin(cwd, "/");
	path = ft_strjoin(cwd, arg);
	chdir(path);
}

void	_cd(t_env **env, char *arg)
{
	char	*PWD;
	char	*OLDPWD;

	OLDPWD = ft_malloc(1024);
	OLDPWD = getcwd(PWD, 1024);
	_export(env, ft_strjoin("OLDPWD=", OLDPWD));
	if (!arg || (arg[0] == '~'))
	{
		if (!cd_home(env))
			write(2, "cd: HOME not set\n",17);
	}
	if (!access(arg, F_OK))
		cd_with_abspath(arg);
	else
		cd_fromcwd(arg);
	PWD = ft_malloc(1024);
	getcwd(PWD, 1024);
	_export(env, ft_strjoin("PWD=", PWD));
	free(PWD);
	free(OLDPWD);
}

// #include <stdlib.h>
// int main(int ac, char **argv)
// {
// 	printf("%d",access("/home/kadigh/Desktop/projects/minishell/execution", F_OK ));
// 	// char	*buff= malloc(1024);
// 	// buff = argv[1];
// 	// getcwd(buff,62);
// 	// printf("%s\n",buff);
// 	// int a = chdir(buff);
// 	// printf("%d\n",a);
// 	// getcwd(buff,62);
// 	// printf("\n>>>\n%s\n",buff);
// }