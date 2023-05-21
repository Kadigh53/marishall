/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:23:37 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/21 17:44:57 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H_
# define HEADER_H_

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct env
{
	char		*env_var;
	int			env_or_export;
	struct env	*next;
}	t_env;

#endif