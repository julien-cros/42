/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:00:58 by herbie            #+#    #+#             */
/*   Updated: 2023/10/17 15:37:10 by jcros            ###   ########.fr       */
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



void	ft_init_signal(void)
{
	g_signal.sigint = 0;
	g_signal.sigquit = 0;
	g_signal.exit_status = 0;
	g_signal.pid = 0;
}

// ft_build_command(char *buffer, char **envp)
void ft_build_data_minishell(char *buffer, char **envp)
{
	t_data data;
	t_lexer lexer;
	t_token token;
	t_token prev;
	int i;

	i = 0;
	data = ft_init_data();
	ft_init_env(&data, envp);
	ft_init_secret_env(&data, envp);
	ft_increment_shell_level(data.envp);
	printf("bfr lexer new\n");
	lexer = ft_lexer_new(buffer);
	token = ft_lexer_next(&lexer, &prev);
	printf("aft lexer next\n");
	while (token.type != TOKEN_EOF)
	{
		printf("token is valid\n");
		if (token.type == TOKEN_INVALID)
		{
			ft_invalid_token(lexer, token);
			ft_clear_tokens(&data.tokens); // check if it's tokens have to be freed here julien
			return;
		}
		if (ft_append_token(&data.tokens, token))
			data.token_length++;
		printf("lexer next\n");
		token = ft_lexer_next(&lexer, &prev);	
		
	}
	// t_token *tmp;
	// tmp = data->tokens;
	// while (tmp)
	// {
	// 	if (tmp->prev)
	// 		printf("token: %d   |  prev: %d\n", tmp->type, tmp->prev->type);
	// 	else
	// 		printf("token: %d   |  prev: NULL\n", tmp->type);
	// 	tmp = tmp->next;
	// }
	// ft_print_tokens(data->tokens);
	printf("bfr parse\n");
	ft_parse(&data);
	ft_clear_tokens(&data.tokens);
	ft_free_env(data.envp);
	ft_free_env(data.secret_env); 
}

void ft_await_command_entry(char **envp)
{
	char *buffer;

while (true)
	{
		ft_init_signal();
		buffer = readline("minishell> ");
		printf("aft readline\n");
		if (!buffer)
		{
			ft_handle_ctrl_d();
		}
		if (ft_strlen(buffer) > 0)
		{
			ft_history_add(buffer);
			ft_build_data_minishell(buffer, envp);
		}
		free(buffer);
	}
}

int		main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	ft_await_command_entry(envp);

	return (0);
}
