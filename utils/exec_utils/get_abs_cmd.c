/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_abs_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:17:50 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/11 15:14:45 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_abs_cmd(char *cmd, char *path)
{
	char	**path_array;
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strjoin(ft_strdup("/"), cmd);
	path_array = ft_split(path, ':');
	while (path_array[i])
	{
		// tmp = ft_strjoin(path_array[i], "/");
		if (!access(ft_strjoin(ft_strdup(path_array[i]), tmp), X_OK))
		{
			// free(tmp);
			// printf("%s\n", ft_strjoin(path_array[i], tmp));
			// exit(0);
			return (ft_strjoin(path_array[i], tmp));
		}
		i++;
	}
	// free(tmp);
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
