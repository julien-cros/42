/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:33:04 by herbie            #+#    #+#             */
/*   Updated: 2023/10/17 15:39:46 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "redirection.h"
#include "fd.h"
#include "token.h"
#include "find.h"
#include "free.h"
#include "str2.h"
#include "builtin.h"
#include <stdbool.h>

// t_token	*next_run(t_token *token)
// {
// 	while (token && token->type != TOKEN_SYMBOL)
// 	{
// 		token = token->next;
// 		if (token && token->type == TOKEN_SYMBOL && token->prev == NULL)
// 			;
// 		else if (token && token->type == TOKEN_SYMBOL && token->prev->type < TOKEN_SYMBOL)
// 			token = token->next;
// 	}
// 	// if (token)
// 	// 	printf("token->value = %s\n", token->value);
// 	return (token);
// }

void ft_print_tokens(t_token *tokens)
{
	t_token *tmp;
	char *str;

	tmp = tokens;
	while (tmp)
	{
		str = ft_substr(tmp->value, 0, tmp->length);
		printf("token: %s   |   type: %d\n", str, tmp->type);
		if (tmp->prev)
			printf("prev: %s\n", tmp->prev->value);
		free(str);
		tmp = tmp->next;
	}
}

void	ft_find_cmd_token(t_data *data, t_token *token)
{
	t_token *head;

	head = token;
	while (token)
	{
		if (ft_is_io_symbol(token))
			token = token->next->next;
		if (token && token->type == TOKEN_SYMBOL && token->prev == NULL)
			token->type = TOKEN_CMD;
		else if (token && token->type == TOKEN_SYMBOL && token->prev->type == TOKEN_PIPE)
			token->type = TOKEN_CMD;
		else if (token && token->type == TOKEN_SYMBOL && token->prev && token->prev->prev 
			&& ft_is_io_symbol(token->prev->prev))
			token->type = TOKEN_CMD;
		if (token)
			token = token->next;
	}
	token = head;
}

void	ft_find_in_token(t_data *data, t_token *token)
{
	int		in_fd;
	char	*in_file;
	t_token	*head;

	in_fd = -1;
	head = token;
	while (token)
	{
		if (token && token->type == TOKEN_SYMBOL 
			&& ft_find_prev_type(token, TOKEN_CMD) 
			&& !ft_is_io_symbol(token->prev))
		{
			in_file = ft_substr(token->value, 0, token->length);
			in_fd = open(in_file, O_RDONLY);
			if (in_fd != -1)
			{
				token->type = TOKEN_IN_FILE;
				close(in_fd);
				free(in_file);
				token = head;
				return ;
			}
		}
		token = token->next;
	}
}


bool	ft_parse(t_data *data)
{
	t_token	*tmp;
	int		status;
	// char *cmd;

	tmp = data->tokens;
	// cmd = ft_substr(tmp->value, 0, tmp->length);
	printf("parsing\n");
	while (data->exit == -1 && tmp)
	{
		data->charge = 1;
		data->is_parent = 1;
		data->last = 1;
		ft_find_cmd_token(data, tmp);
		ft_find_in_token(data, tmp);
		printf("ok\n");
		// ft_print_tokens(tmp);	
		// if (ft_if_builtin(cmd))
		// 	ft_builtin_valid(tmp, data, cmd);
		// else 
		ft_redirection(data, tmp);
		printf("aft redirection\n");
		ft_reset_std(data);
		ft_close_fds(data);
		ft_reset_fds(data);
		waitpid(-1, &status, 0);
		status = WEXITSTATUS(status);
		data->return_status = (data->last == 0) ? status : data->return_status;
		if (data->is_parent == false)
		{
			ft_clear_tokens(&data->tokens);
			exit(data->return_status);
		}
		data->is_executable = 0;
		tmp = NULL;
	}
	return (true);
}
