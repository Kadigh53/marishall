/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:32:16 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/24 00:35:26 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

int	ft_lstsize(t_env *lst)
{
	t_env			*tmp;
	unsigned int	i;

	i = 0;
	if (!lst)
		return (0);
	tmp = lst ;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
