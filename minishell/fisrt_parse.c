/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fisrt_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:04:44 by juliencros        #+#    #+#             */
/*   Updated: 2023/07/20 14:39:45 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "first_parse.h"
#include "structs.h"
#include "error.h"
#include "str.h"
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>


extern char **env;

void	ft_init_tree(t_tree *tree)
{
	tree->is_pipe = false;
	tree->cmd_pos = 0;
	tree->cmd_value = NULL;
	tree->next = NULL;

}

bool	ft_is_infile(t_token *tokens, t_tree *tree)
{
	if (access(tokens->value, F_OK) == 0)
	{
		tree->in_fd = open(tokens->value, O_RDONLY);
		return (true);
	}
	else if (acces(tokensvalue, F_OK) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(tokens->next->value, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else if (acces(tokens->value, R_OK) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(tokens->next->value, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	return (false);
}

bool	ft_is_cmd(t_token *token)
{
	if (access(token->value, F_OK) == 0)
		return (true);
	else if (acces(token->value, F_OK) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(token->value, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else if (acces(token->value, R_OK) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(token->value, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	return (false);
}

bool	ft_is_valid(t_token *token, t_tree *tree)
{
	if (token->type == "TOKEN_LT" && ft_is_infile(token->next, tree) == false)
		return (false);
	if (token->type == "TOKEN_SYMBOL" && ft_is_cmd(token) == false)
		return (false);
	if ((token->type == "TOKEN_GT" && token->next == NULL)
		 || (token->type == "TOKEN_GTGT" && token->next == NULL))
		return (false);
	if (token->type == "TOKEN_GT" && ft_is_outfile(token, tree) == false)
		return (false);
	return (true);
}

void	ft_search_type(t_command *command)
{
	t_token	*token;
	t_tree *tree;
	t_token *tmp;

	ft_init_tree(tree);
	tmp = command->tokens;
	token = command->tokens;
	while (token->next != NULL)
	{
		if (ft_is_valid(token, tree) == false);
			return (ft_error(ECMD));
		if (ft_what_type(token, tree) == false)
			return (ft_error(ECMD));
		token = token->next;	
	}
	ft_fill_tree(tmp, tree);
}





















// bool ft_is_cmd(t_command *command, t_token *token)
// {
// 	if (access(token->value, F_OK) == 0)
// 	{
// 		int i;
// 		char **paths;
// 		char *path;

		
// 		i = 0;
// 		if (command->in_fd = open(token->value, O_RDONLY) != -1)
// 			return (true);
// 		paths = ft_create_paths(env);
// 		if (!paths)
// 			return (ft_error(EMALLOC), exit(1));
// 		path = ft_fill_path(paths, token->value, path);
// 		if (!path)
// 			return (ft_error(EMALLOC), exit(1));
		
// 	}
	
// }

// static	char	**ft_create_paths(char **envp)
// {
// 	char	**paths;
// 	int		i;

// 	i = 0;
// 	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
// 		i++;
// 	paths = ft_split(envp[i], ':');
// 	if (!paths)
// 		return (NULL);
// 	return (paths);
// }


// {
// 	if (access(token->value, F_OK) == 0)
// 	{
// 		char *path;
		
// 		if (command->in_fd = open(token->value, O_RDONLY) != -1)
// 			return (true);
// 		malloc (path, sizeof(char) * (10000));
// 		if (!path)
// 			return (ft_error(EMALLOC), exit(1));
		

// 	}
	
// }

// void	ft_find_type(t_command *command, t_tree *tree, t_shell *shell)
// {
// 	t_token	*token;

// 	token = command->tokens;
// 	while (token && tree->is_pipe == false && tree->cmd_value == NULL)
// 	{
// 		if (token->type == "TOKEN_LT" && ft_is_infile(command, token) == false)
// 				return ;
// 		if (token->type == "TOKEN_PIPE")
// 			tree->is_pipe = true;
// 		if (token->type == "TOKEN_SYMBOL" && ft_is_cmd(command, token, shell) == false)
// 				// return ;
// 		token = token->next;
// 	}
// }




// void	ft_fill_tree(t_command *command)
// {
// 	t_tree	*tree;
// 	t_token	*token;

// 	tree = malloc(sizeof(t_tree));
// 	if (!tree)
// 		return ;
// 	ft_init_tree(tree);
// 	ft_find_type(command, tree);
// 	token = command->tokens;
// 	while (token)
// 	{
// 		if (token->type == "TOKEN_PIPE")
// 			tree->is_pipe = true;
// 		ft_is_command()
// 		// if (token->type == "TOKEN_CMD")
// 		// {
// 			// tree->cmd_pos = token->pos;
// 			// tree->cmd_value = token->value;
// 		// }
// 		token = token->next;
// 	}
// }

// void	ft_add_tree(t_tree *tree, t_command *command)
// {
// 	t_tree	*new_tree;

// 	new_tree = malloc(sizeof(t_tree));
// 	if (!new_tree)
// 		return ;
// 	ft_init_tree(new_tree);
// 	new_tree->cmd_pos = command->cmd_pos;
// 	new_tree->cmd_value = command->cmd_value;
// 	new_tree->is_pipe = command->is_pipe;
// 	new_tree->next = NULL;
// 	while (tree->next)
// 		tree = tree->next;
// 	tree->next = new_tree;
// }

// void	ft_check_in_out(t_command *command)
// {
// 	if (acces(command->tokens->value, F_OK) == 0)
// 	{
// 		command->in_fd = open(command->tokens->value, O_RDONLY);
// 		return ;
// 	}	
// 	else if (acces(command->tokens->value, F_OK) == -1)
// 	{
// 		ft_putstr_fd("minishell: ", 2);
// 		ft_putstr_fd(command->tokens->value, 2);
// 		ft_putstr_fd(": No such file or directory\n", 2);
// 	}
// 	else if (acces(command->tokens->value, R_OK) == -1)
// 	{
// 		ft_putstr_fd("minishell: ", 2);
// 		ft_putstr_fd(command->tokens->value, 2);
// 		ft_putstr_fd(": Permission denied\n", 2);
// 	}
	
// }

// void	ft_first_parse(t_command *command)
// {
// 	if (command->tokens->type == "TOKEN_LT")
// 			ft_check_infile(command);
// 	if (command->tokens->type == "TOKEN_GT")
// 			ft_check_outfile(command);
// }