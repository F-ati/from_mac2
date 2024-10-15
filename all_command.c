/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:37:20 by fel-aziz          #+#    #+#             */
/*   Updated: 2024/10/15 12:37:03 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void  ft_exit(t_data *data)
// {
// 	int nb ;
// 	if (data->command[1] == NULL)
// 	{
// 		printf("exit\n");
// 		exit(0);
// 	}
// 	else if ( check_is_number(data->command[1]) == 1 && data->command[2] == NULL)
// 	{
// 		nb = ft_atoi(data->command[1]);
// 		printf("exit");
// 		exit (nb);
// 	}
// 	else if (check_is_number(data->command[1]) == 0)
// 	{
// 		printf("exit\n");
// 		printf("bash: exit: %s: numeric argument required\n",data->command[1]);
// 		exit(255);
// 	}
// 	else if (check_is_number(data->command[1]) == 1 && data->command[2] != NULL )
// 	{
// 		printf("exit\n");
// 		printf("bash: exit: too many arguments\n");
// 	}
// }

// int  ft_found_word(t_data *data)
// {
	
// 	int j = 0;
// 	int len ;
// 	len = ft_strlen(data->command[1]);

// 	while (data->env[j] != NULL  )
// 	{
// 		if ( data->env[j][0] == data->command[1][0] && ft_strncmp(data->command[1] ,data->env[j] ,len) == 0 && data->env[j][len] == '=')
// 			return(j);	
// 		j++;
// 	}
// 	return(-7);
// }
// int ft_count_len(char **str)
// {
// 	int count = 0;

// 	int j = 0;
// 	while (str[j] != NULL)
// 	{
// 		int i = 0;
// 		while (str[j][i] != '\0')
// 		{	
		
// 			if(str[j][i + 1] == '\0')
// 				count ++;
// 			i++;
// 		}
// 		j++;
// 	}
// 	return(count);
// }

// void ft_resize(t_data *data , int len , int index )
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
// 	free(data->env);
// 	data->env = p;
// 	p = NULL;
// }


// void ft_unset(t_data *data)
// {
// 	int i = ft_found_word(data);
// 	int len = ft_count_len(data->env);
// 	if ( i >= 0)
// 	{
// 		ft_resize(data ,len , i);
// 	}
//    ft_env(data);	
//    ft_free(data->env); 
//    data->env = NULL;
// }

