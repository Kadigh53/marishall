/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:05:47 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/22 19:54:45 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/header.h"

void	cd_home(t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->env_var, "HOME=", 5))
		{
			chdir(tmp->env_var + 5);
			break ;
		}
		tmp = tmp->next;
	}
	return ;
}

void	_cd(t_env **env, char *arg)
{
	if (!arg || (arg[0] == '~'))
		cd_home(*env);
	cd_fromcwd();
	cd_from_abspath();
}

// int main()
// {
// 	chdir();
// }