/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:34:12 by codespace         #+#    #+#             */
/*   Updated: 2023/10/17 14:02:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"
#include "str2.h"
#include "here_doc.h"
#include "find.h"
#include "path_args.h"
#include "find.h"
#include "builtin.h"
#include <unistd.h>
#include <fcntl.h>

bool	ft_out_and_dup(t_data *data, t_token *token)
{
	char *str;

	printf("in out_and_dup\n");
	if (data->out_fd > 0)
		close(data->out_fd);
	if(token->next == NULL)
		return (printf("error, no thing aft GT or GTGT\n"), false);
	str = ft_substr(token->next->value, 0, token->next->length);
	printf("str = %s\n", str);
	if (!str)
	{
		data->is_executable = false;
		return (printf("error substr out_and_dup\n"), false);
	}
	if (token->type == TOKEN_GT)
			data->out_fd = open(str, O_CREAT, O_RDWR, O_TRUNC, 0644);
	else
		data->out_fd = open(str, O_CREAT, O_RDWR, O_APPEND, 0644);
	free(str);
	if (data->out_fd == -1)
	{
			data->is_executable = false;
			data->return_status = 1;
			return(printf("minishel: error wrong outfile\n"), false);
	}
	dup2(data->out_fd, STDOUT_FILENO);
	return(true);
}

bool	ft_in_and_dup(t_data *data, t_token *token)
{
	char *str;

	if (data->in_fd > 0)
		close(data->in_fd);
	if (token->next == NULL)
		return(printf("error, nothing aft LT or LTLT\n"));
	str = ft_substr(token->next->value, 0, token->next->length);
	if (!str)
	{
		data->is_executable = false;
		return (printf("error substr in_and_dup\n"), false);
	}
	if (token->type == TOKEN_LT_LT)
		ft_set_here_doc(data, token, token->length);
	else
		data->in_fd= open(str, O_RDONLY, 0644);
	free(str);
	if (data->in_fd == -1)
	{
		data->is_executable = false;
		data->return_status = 1;
		return(printf("minishel: error wrong infile\n"), false);
	}
	dup2(data->in_fd, STDIN_FILENO);
	return(true);

}

int	ft_fork_and_pipe(t_data *data)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	pid = fork();
	if (pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	if (pid == 0)
	{
		if (fd[1] > 0)
			close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		data->pipe_in = fd[0];
		data->is_parent = false;
		data->pid = -1;
		data->is_executable = true;
		return(2);
	}
	else
	{
		if (fd[0] > 0)
			close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		// perror("dup2");
		data->pipe_out = fd[1];
		data->is_parent = true;
		data->pid = pid;
		data->last = 0;
		return(1);
	}
}


/**
 * @brief The redirection function is the main function of the redirections.
 * 	The Token is place as the cmd between in and out redirections. We can
 * 	have in one side of the cmd the in and in the other side the out.
 * 		Example: < cmd >
 * 
 * @param data 
 * @param token 
 * @return true 
 * @return false 
 */
bool		ft_redirection(t_data *data, t_token *token)
{
	int		is_child;
	t_token	*head;
	char	*str;

	is_child = 0;
	printf("\n--- in redirection ---\n\n");
	// printf("token->value = %s\n", token->value);
	if (!token || !data)
	{
		printf("errors: no subcommand or tokens in redirection\n");
		return (false);

	}
	head = token;
	if (head && (head->type == TOKEN_LT || head->type == TOKEN_LT_LT)) 
		head = head->next->next;
	if (head->prev && head->prev->prev && (head->prev->prev->type == TOKEN_LT || head->prev->prev->type == TOKEN_LT_LT) || ft_find_type(head, TOKEN_IN_FILE, TOKEN_PIPE))
	{
		if (head->prev && head->prev->prev && (head->prev->prev->type == TOKEN_LT || head->prev->prev->type == TOKEN_LT_LT))
			ft_in_and_dup(data, head->prev->prev);
		else
			ft_in_and_dup(data, head);
	}
	else if (head->next && (head->next->type == TOKEN_GT || head->next->type == TOKEN_GT_GT))
	{
		printf("in gt gt\n");
		ft_out_and_dup(data, head->next);
	}
	else if (head && ft_find_type(head, TOKEN_PIPE, -1))
		is_child = ft_fork_and_pipe(data);
	if(head->next && is_child != 1 && (ft_find_type(head->next, TOKEN_CMD, -1)))
	{

		while (head && head->next && head->type != TOKEN_PIPE)
			head = head->next;
		ft_redirection(data, head->next);
	}
	if (is_child != 1)
	{
		str = ft_substr(token->value, 0, token->length);	
		if (ft_if_builtin(str))
			ft_builtin_valid(token, data, str);
		else
		ft_exec_cmd(data, head);
	}
	// ft_path_and_args(data, head); // 
	return (true);
}
