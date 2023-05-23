/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:08:51 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/24 00:35:00 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

void	ft_lstadd_front(t_env **lst, t_env *new)
{
	if (*lst && new)
	{
		new->next = *lst;
	}
	if (new)
	{
		(*lst) = new;
	}
}
