/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:41:45 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/09 13:15:13 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_var_vi(char *arg, int mode)
{
	int		i;
	char	*var;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	if (arg[i] == '\0')
		return (NULL);
	if (mode == 0)
		var = ft_substr(arg, 0, i);
	else
		var = ft_substr(arg, i + 2, ft_strlen(arg) - i - 3);
	return (var);
}

char	*expander(t_env **env, char *var)
{
	t_env	*node;
	char	*var_in_env;

	node = *env;
	while (node)
	{
		var_in_env = get_var_vi(node->env_var, 0);
		if (!ft_strncmp(var_in_env, var, ft_strlen(var)))
		{
			free(var_in_env);
			return (get_var_vi(node->env_var, 1));
		}
		node = node->next;
	}
	free(var_in_env);
	return (NULL);
}
