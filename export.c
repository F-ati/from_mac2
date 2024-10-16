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

int check_invalid_arg(char *command)
{
	int i ;
	
	if ((command[0] >= 'a' && command[0] <= 'z') || (command[0] >= 'A' && command[0] <= 'Z') || (command[0] == '_'))
	{
		i = 1;
		while(command[i] != '\0' && command[i] != '=')
		{
				
			if((command[i] < 'a' || command[i] > 'z') && (command[i] < 'A' || command[i] > 'Z') && (command[i] < 48 || command[i] > 57 ) && (command[i] != '_'))
			{
				return (-7);
			}
			i++;
		}
	}
	else 
	{
		return(-7);
	}	
return (1);
}

int check_is_has_value(char *command)
{
	int i = 0;
	while(command[i] != '\0')
    {
		if(command[i] == '=')
		{
			return (1);
		}
		i++;
	}
	return(0);
}

int exist_name_var(char **ex_or_env , char *command)
{
	int j = 0 ;
	while(ex_or_env[j] != NULL)
	{
		if(ft_strcmp(ex_or_env[j] , command) == 0)
		{
			return(-7);
		}
		j++;
	}
	return(j);
} 

char **ft_resize(char **ex_or_env, char *name_var ,int len )
{
	char **p;
	p =  malloc(sizeof(char *) * (len + 2));
	if (name_var == NULL)
			return(NULL);
	len = 0;
	while(ex_or_env[len] != NULL)
	{
		p[len] = ex_or_env[len];
		len++;
	}
	p[len] = name_var;
	len++;
	p[len] = NULL;
	free(ex_or_env);
	return(p);
}


void ft_apdute_export(t_shell *shell , char *command)
{
	char **p = NULL;
	
	int indix = exist_name_var(shell->export ,command);
	if(indix >= 0)
	{
		p = ft_resize(shell->export,command,indix);
		shell->export = p;
		// free(p);
		p = NULL;
	}
}

char *get_name_var(char *command)
{
	char *p;
	int i = 0;
	while (command[i] != '=')
	{
		i++;
	}
	p = malloc(sizeof(char) * ( i + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while(command[i] != '=')
	{
		p[i] = command[i];
		i++;
	}
	p[i] = '\0';
	return(p);
}
void ft_apdute_env(t_shell *shell,char *command)
{
	char **p;
	int args_exist = exist_name_var(shell->env,command);
	char *nam_var = get_name_var(command);
	int indix = exist_name_var(shell->env,nam_var);
	free(nam_var);
	if (args_exist >= 0)
	{
		if(indix >= 0 )
		{
			p = ft_resize(shell->env,command,indix);
			shell->env = p;
			// free(p);
			p = NULL;
		}
		else 
		{
			// ft_apt_value();
		}
	}
}


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
	// int deja_exist;
	int has_value;
	i = 1;
	while(shell->list->command[i] != NULL)
	{
		if(check_invalid_arg(shell->list->command[i]) == 1)
		{
			// deja_exist = check_is_exist(shell->list->command[i]);
			has_value = check_is_has_value(shell->list->command[i]);
			if(/*deja_exist == 0 &&*/ has_value == 0)
			{
				ft_apdute_export(shell ,shell->list->command[i]); 	
			}
			else if (/*deja_exist = 0  && */ has_value == 1)
			{

				ft_apdute_env(shell , shell->list->command[i]);
				// ft_apdute_export(shell);
				// printf("has a value\n");
				// call env 
				//  expo;
			}

		}
		else
		{
			printf("bash: export: '%s': not a valid identifier\n",shell->list->command[i]);
			// exit(EXIT_FAILSRE);
			// apdute the exit status
		}
		i++;
	}
	
}