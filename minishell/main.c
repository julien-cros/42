/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:00:58 by herbie            #+#    #+#             */
/*   Updated: 2023/08/08 18:21:25 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include "io.h"
#include "parse.h"
#include "structs.h"
#include "print.h"
#include "error.h"
#include "lexer.h"
#include "command.h"
#include "subcommand.h"
#include "history.h"
#include "token.h"
#include "signals.h"
#include "clear.h"
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <readline/readline.h>

# define SUBCOMMAND_FMT \
	"Subcommand(in_fd=%d, out_fd=%d, path='%s', \
	mode=%d, is_heredoc=%d)\n"
# define SUBCOMMAND_ARG(subcommand) \
	subcommand.in_fd, subcommand.out_fd, subcommand.path, \
	subcommand.mode, subcommand.is_heredoc
	#include "mem.h"

void	ft_print_subcommands(t_command *command)
{
	t_subcommand	*subcommand;

	subcommand = command->subcommands;
	while (subcommand)
	{
		t_subcommand tmp;
		ft_memcpy(&tmp, subcommand, sizeof(t_subcommand));
		printf(SUBCOMMAND_FMT, SUBCOMMAND_ARG(tmp));
		subcommand = subcommand->next;
	}
}

void	ft_build_command(char *buffer)
{
	t_command	command;
	t_lexer		lexer;
	t_token		token;

	command = ft_command_new();
	lexer = ft_lexer_new(buffer);
	token = ft_lexer_next(&lexer);
	while (token.type != TOKEN_EOF)
	{
		if (token.type == TOKEN_INVALID)
		{
			ft_invalid_token(lexer, token);
			break ;
		}
		if (ft_append_token(&command.tokens, token))
			command.token_length++;
		token = ft_lexer_next(&lexer);
	}
	if (ft_create_subcommands(&command))
	{
		ft_parse(&command, &lexer, &token);
		ft_print_subcommands(&command);
	}
	ft_clear_tokens(&command.tokens);
	ft_clear_subcommands(&command.subcommands);
}

void	ft_await_command_entry(void)
{
	char	*buffer;

	while (true)
	{
		buffer = readline("minishell> ");
		if (!buffer)
			ft_handle_ctrl_d();
		if (ft_strlen(buffer) > 0)
		{
			ft_history_add(buffer);
			ft_build_command(buffer);
		}
		free(buffer);
	}
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	ft_history_new();
	ft_signals_register();
	ft_await_command_entry();
	return (0);
}
