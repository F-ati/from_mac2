/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:12:30 by fel-aziz          #+#    #+#             */
/*   Updated: 2024/10/15 18:13:44 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_export(t_shell *shell)
{
	int i = 0;
	if (shell->list->command[1] == NULL)
	{
		while (shell->export[i] != NULL)
		{
			printf("%s\n",shell->export[i]);
			i++;
		}
	}
	// if (check_invalid_arg(shell) == 1)
	// {
		
	// }
}