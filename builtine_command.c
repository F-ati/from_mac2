/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtine_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:16:27 by root              #+#    #+#             */
/*   Updated: 2024/10/15 17:31:20 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// echo command 

void ft_print_str(t_shell *minishell , int flag)
{
	int i ;
	int j = flag ;
	
	while (minishell->list->command[j] != NULL)
	{
		i = 0;
		while (minishell->list->command[j][i] != '\0')
		{
			write(1,&minishell->list->command[j][i],1);
			i++;
		}
		write(1," ",1);
		j++;
	}
	if (flag == 1 )
		write(1,"\n",1);
}

void ft_echo(t_shell *minishell)
{
	
	int i;
	int j ;
	j = 1;
	i = 0;
	if ( minishell->list->command[j] != NULL && minishell->list->command[j][0] == '-' && minishell->list->command[j][1] != '-')
	{
		while (minishell->list->command[j] != NULL)
		{
			i = 0;
			while((minishell->list->command[j][i] != '\0' && minishell->list->command[j][i] == 'n' )|| minishell->list->command[j][i] == '-')
			{
				i++;
			}
		    if (i != ft_strlen(minishell->list->command[j]))
				break;
			j++;
		}
	}
	ft_print_str(minishell,j);
}

//  env command 


void  ft_env(t_shell *data)
{
	int j = 0;
	int i ;
	while (data->env[j] != NULL)
	{
		i = 0;
		while ( data->env[j][i] != '\0')
		{
			write(1,&data->env[j][i],1);
			i ++;
		}
		write(1,"\n",1);
		j ++;
	}
}

// pwd command ;
void ft_pwd()
{
	char *path;
    path = getcwd(NULL,0);
    if(path == NULL)
    {
        perror("bash: pwd: getcwd");
        exit(EXIT_FAILURE);
    }
    printf("%s\n",path);
    free(path);
}


// cd command 

#include "minishell.h"

char *get_pwd(t_shell *shell)
{
	int j = 0;
	char *pwd;
	pwd = NULL;
	while (shell->env[j] != NULL)
	{
		if(shell->env[j][0] == 'P' && strncmp(shell->env[j] ,"PWD",3) == 0 && shell->env[j][3] == '=')
		{
			pwd = ft_strdup(&shell->env[j][4]);
			break;
		}
		j++;
	}
	return(pwd);
}

void update_pwd_env(char *curr_pwd,t_shell *shell)
{
	int j = 0;
	int flag = 0;
	// int i = 0;
	char *save_pwd = get_pwd(shell);
	while(shell->env[j] != NULL)
	{
		
		if(shell->env[j][0] == 'P' && strncmp(shell->env[j] ,"PWD",3) == 0 && shell->env[j][3] == '=')
		{
			char *save = shell->env[j];
			shell->env[j] = ft_strjoin("PWD=",curr_pwd);
			free(save);
			flag = 1;
		}	
		if (shell->env[j][0] == 'O' && strncmp(shell->env[j] ,"OLDPWD",6) == 0 && shell->env[j][6] == '=' && flag == 1)
		{
			char *save1 = shell->env[j];
			shell->env[j] = ft_strjoin("OLDPWD=",save_pwd);
			free(save1);
		}
		j++;
	}
	free(save_pwd);
}

void ft_cd(t_shell *shell)
{
    int i;
    char *curr_pwd = NULL;
    if (shell->list->command[1] != NULL)
    {
      i = chdir(shell->list->command[1]);
    
    	if ( i < 0)
    	{
        	perror("bash: cd:");
        	exit(EXIT_FAILURE);
    	}
    	curr_pwd = getcwd(NULL,0);
		if (curr_pwd ==  NULL)
		{
			perror("bash: cd");
			exit(EXIT_FAILURE);
		}
    	update_pwd_env(curr_pwd,shell);
    }
    free(curr_pwd); 
}

//  