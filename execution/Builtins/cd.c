/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:05:47 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/28 05:27:53 by aaoutem-         ###   ########.fr       */
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

char	*get_path(t_env **env, char *dir)
{
	char	*cwd;
	int		i;
	int		j;

	cwd = ft_malloc(1024);
	if (getcwd(cwd, 1024))
		error("ERROR:");
	i = ft_strlen(cwd) - 1;
	if (!ft_strncmp(dir, "..", 3))
	{
		while (cwd[i] != '/')
			i--;
		j = i - 1;
		while (cwd[j] != '/')
			j--;
		return (ft_substr(cwd, j + 1, i - j));
	}
	else if (dir[0] == '.' && ft_strlen(dir) == 1)
		return (NULL);
	else if (dir[0] == '~' && ft_strlen(dir) == 1)
		return (ft_strdup(get_env_var(env, "HOME=")));
	else
		return (dir);
	free(cwd);
}

void	cd_fromcwd(t_env **env, char *arg)
{
	char	**splited_arg;
	char	*path;
	char	*cwd;
	int		i;

	i = 0;
	path = NULL;
	splited_arg = ft_split(arg, '/');
	cwd = ft_malloc(1024);
	if (getcwd(cwd, 1024))
		path = ft_strjoin(cwd, "/");
	while (splited_arg[i])
	{
		path = ft_strjoin(path, get_path(env, splited_arg[i]));
		path = ft_strjoin(path, "/");
		i++;
	}
	if (chdir(path) == -1)
		write(2, "cd: HOME not set\n", 17);
	free(splited_arg);
	free(cwd);
	free(path);
}

void	_cd(t_env **env, char *arg)
{
	char	*PWD;
	char	*OLDPWD;

	OLDPWD = ft_malloc(1024);
	OLDPWD = getcwd(OLDPWD, 1024);
	printf(" cwd : %s\n", OLDPWD);
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
		else
			cd_fromcwd(env, arg);
	}
	PWD = ft_malloc(1024);
	getcwd(PWD, 1024);
	printf("\n cwd : %s\n", PWD);
	// _export(env, ft_strjoin("PWD=", PWD));
	free(PWD);
	free(OLDPWD);
}
