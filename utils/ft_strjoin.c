/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:30:47 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/27 03:16:26 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	i;

	i = ft_strlen(s1) + ft_strlen(s2);
	if (!s2)
		return (NULL);
	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char) + 1);
	if (!p)
		return (NULL);
	else
	{
		ft_memcpy(p, s1, ft_strlen(s1) * sizeof(char));
		ft_memcpy(p + ft_strlen(s1), s2, ft_strlen(s2) * sizeof(char));
		p[i] = '\0';
		free(s1);
		return (p);
	}
}
