/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:37:14 by fel-aziz          #+#    #+#             */
/*   Updated: 2024/10/15 16:20:09 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void ft_free_env( char **str)
// {
// 	int i = 0;
// 	while (str[i] != NULL)
// 	{
// 		free(str[i]);
// 		i++;
// 	}
// 	free(str);
// 	str = NULL;
// }

// int  ft_found_word(t_shell *data)
// {
	
// 	int j = 0;
// 	int len ;
// 	len = ft_strlen(data->list->command[1]);

// 	while (data->env[j] != NULL  )
// 	{
// 		if ( data->env[j][0] == data->list->command[1][0] && strncmp(data->list->command[1] ,data->env[j] ,len) == 0 && data->env[j][len] == '=')
// 			return(j);	
// 		j++;
// 	}
// 	return(-7);
// }
int ft_env_len(char **str)
{
	int count = 0;
	
	int j = 0;
	while (str[j] != NULL)
	{
		int i = 0;
		while (str[j][i] != '\0')
		{	
		
			if(str[j][i + 1] == '\0')
				count ++;
			i++;
		}
		j++;
	}
	return(count);
}

// void ft_resize(t_shell *data , int len , int index )
// {
// 	int i = 0;
// 	char **p ;
// 	int j = 0;
// 	p = malloc(sizeof(char *) * len );
// 	while (i < len )
// 	{
// 		if ( i == index)
// 		{
// 		   free(data->env[i]);
// 			i++;
// 		}
// 		else
// 		{
// 		  p[j] = data->env[i];
// 			j++;
// 		    i++;
// 		}
		
// 	}
// 	p[i] = NULL;
// 	// free(data->env);
// 	data->env = p;
// 	p = NULL;
// }


// void ft_unset(t_shell *data)
// {
// 	int i = ft_found_word(data);
// 	int len = ft_count_len(data->env);
// 	if ( i >= 0)
// 	{
// 		ft_resize(data ,len , i);
// 	}	
//    ft_free_env(data->env);  
// }

// int ft_delete_count(t_shell *shell)
// {
// 	int count = 0;
// 	int j = 0;
// 	while (shell->list->command[j] != NULL)
// 	{
// 		count++;
// 		j++;
// 	}
// 	return (count - 1);
// }


// void ft_unset(t_shell *shell)
// {
// 	int i = 1;
// 	char **p = NULL;
// 	int env_len = ft_env_len(shell->env);
// 	int delete_count = ft_delete_count(shell);
// 	p = malloc (sizeof(char *) * env_len - delete_count); // ?
// 	while (shell->list->command[i] != NULL)
// 	{
// 		ft_resize(p,env_len,de)
// 	}
// }