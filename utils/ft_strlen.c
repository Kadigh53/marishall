/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:50:37 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/05/23 17:51:13 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t	ft_strlen(char *s)
{
	size_t	count;
	int		i;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		count += 1;
		i ++;
	}
	return (count);
}