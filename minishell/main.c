/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:00:58 by herbie            #+#    #+#             */
/*   Updated: 2023/10/18 09:43:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "init.h"
#include "history.h"
#include "env.h"
#include "shell_levels.h"
#include "signals.h"
#include "free.h"
#include "token.h"
#include "lexer.h"
#include "error.h"
#include "parse.h"
#include <stdbool.h>
#include <readline/readline.h>
#include <stdio.h>
#include <unistd.h>

t_signal	g_signal;

t_token ft_init_token(void)
{
	t_token token;

	token.type = TOKEN_INVALID;
	token.value = NULL;
	token.length = 0;
	token.next = NULL;
	// token.prev = NULL;
	return (token);
}

void	ft_init_signal(void)
{
	g_signal.sigint = 0;
	g_signal.sigquit = 0;
	g_signal.exit_status = 0;
	g_signal.pid = 0;
}

// ft_build_command(char *buffer, char **envp)
void ft_build_data_minishell(t_data *data, char *buffer, char **envp)
{
	t_lexer lexer;
	t_token token;
	t_token prev;
	int i;

	i = 0;
	prev = ft_init_token();
	lexer = ft_lexer_new(buffer);
	token = ft_lexer_next(&lexer, NULL);
	while (token.type != TOKEN_EOF)
	{
		if (token.type == TOKEN_INVALID)
		{
			ft_invalid_token(lexer, token);
			ft_clear_tokens(&data->tokens); // check if it's tokens have to be freed here julien
			return ;
		}
		if (ft_append_token(&data->tokens, token))
			data->token_length++;
		token = ft_lexer_next(&lexer, &prev);	
		
	}
	ft_parse(data);
	ft_clear_tokens(&data->tokens);
}

void ft_await_command_entry(t_data *data, char **envp)
{
	char *buffer;

while (true)
	{
		ft_init_signal();
		buffer = readline("minishell> ");
		if (!buffer)
		{
			ft_handle_ctrl_d();
		}
		if (ft_strlen(buffer) > 0)
		{
			ft_history_add(buffer);
			ft_build_data_minishell(data, buffer, envp);
		}
		free(buffer);
	}
}

int		main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	t_data data;

	data = ft_init_data();
	ft_history_new();
	ft_signals_register();
	ft_init_env(&data, envp);
	ft_init_secret_env(&data, envp);
	ft_increment_shell_level(data.envp);
	ft_await_command_entry(&data, envp);
	ft_free_env(data.envp);
	ft_free_env(data.secret_env); 
	return (0);
}
