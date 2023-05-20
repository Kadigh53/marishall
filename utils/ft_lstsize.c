/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:32:16 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/20 16:19:45 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_lstsize(t_list *lst)
{
	t_list			*tmp;
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
