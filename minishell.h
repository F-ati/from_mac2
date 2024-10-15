#ifndef MINISHELL_H
#define MINISHELL_H

#define BUFFER_SIZE 1024
#define HEREDOC 1
#define APPEND 2
#define IN 3
#define OUT 4
#define PATH_MAX 4096 


#include <readline/readline.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <sys/wait.h>
#include "libft/libft.h"

typedef struct s_dir
{
    int type;
    char    *file_name;
    int isQuoted;
    struct s_dir    *next;
}   t_dir;

typedef struct s_list
{
    char    **command;
    t_dir   *redir;
    struct s_list   *next;
}   t_list;

typedef struct s_shell
{
    char **env;
    char **export;
    t_list *list;
    int exit_status;
    // my vriable (execution);
    int len ;
    char **path;
    int i ;
    int herdoc_nb;
    int cmd_nb;
}   t_shell;

// funcs of the execution  
void  ft_execution(t_shell *minishell);
int   ft_cmnd_nb( t_list *data);
void  ft_is_builtins(t_shell *minishell);
void  ft_echo(t_shell *minishell);
void  ft_env(t_shell *data);
void  ft_cd(t_shell *shell);
void  ft_pwd();
void  ft_unset(t_shell *data);
void  ft_export(t_shell *shell);
int   ft_herdoc_nb(t_list *save);
void  ft_herdoc(t_shell *shel);

// void ft_herdoc(t_shell *data);

#endif