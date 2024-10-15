/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:08:34 by fel-aziz          #+#    #+#             */
/*   Updated: 2024/09/14 16:26:00 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_cmnd_nb( t_list *data)
{
	t_list *tmp = data;
	int i = 0;
    if (data == NULL)
    {
        return (0);
    }

	while ( tmp != NULL)
	{
		i ++;
		tmp = tmp->next; 
	}
	return (i);
}
int ft_herdoc_nb(t_list *save)
{

    int i = 0;
    t_dir *redir_cur;
    t_list *cur = save;
    if (save == NULL) 
		return 0;

    while (cur != NULL)
    {
        redir_cur = cur->redir;
        while (redir_cur != NULL)
        {
            if (redir_cur->type == HEREDOC)
            {
                i++;
            }
            redir_cur = redir_cur->next;
        }
        cur = cur->next;
    }

    return i;
}
