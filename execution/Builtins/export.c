/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:09:19 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/20 17:23:07 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/header.h"

void	export(t_env **env, char *env_var)
{
	t_env	*node;
	
	node = ft_lstnew(env_var);
	ft_lstadd_back(env, env_var);
}
