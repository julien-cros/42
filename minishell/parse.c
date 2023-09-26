/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:33:04 by herbie            #+#    #+#             */
/*   Updated: 2023/08/17 14:38:54 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "structs.h"
#include <stdio.h>
#include <fcntl.h>

bool	ft_check_first(t_command *command);
bool	ft_parse(t_command *command, t_lexer *lexer, t_token *token)
{
	// (void)command;	
	(void)lexer;
	(void)token;
	// char *path;
	printf ("command->tokens->type: %d\ncommand->tokens->value: %.*s\n", command->tokens->type, command->tokens->length , command->tokens->value);
	if (!ft_check_first(command))
		return (false);
	while (command->tokens->next != NULL)
	{
		printf ("command->tokens->type: %d\ncommand->tokens->value: %s\n  command->next->type: %d\n  command->next->value: %s\n", command->tokens->type, command->tokens->value, command->tokens->next->type, command->tokens->next->value);
		if (command->tokens->type == command->tokens->next->type)
			return (printf("error1: %d\n", command->tokens->type), false);
		if (command->tokens->type != TOKEN_CMD && command->tokens->next->type == TOKEN_PIPE)
			return (printf("error2: %d\n", command->tokens->type), false);
		if (command->tokens->type == TOKEN_PIPE && command->tokens->next->type 
		!= TOKEN_CMD)
			return (printf("error3: %d\n", command->tokens->type), false);
		command->tokens = command->tokens->next;
	}
	// printf("command-tokens->length: %d\n", command->tokens->length);
	// printf("command->token->lenght: %d\n", command->tokens->length);
	// printf("command->tokens->next->length: %d\n", command->tokens->next->length);
	// printf("command->token->value: %s\n", command->tokens->value[command->tokens->length]);
	// printf("command->subcommands->next->path: %s\n", command->subcommands->next->path);
	// printf("command->tokens->type: %d\n", command->tokens->type);
	// printf("command->tokens->value: %s\n", command->tokens->value);
	// printf("command->tokens->length: %d\n", command->tokens->length);
	// printf("command->tokens->next->type: %d\n", command->tokens->next->type);
	// printf("command->tokens->next->value: %s\n", command->tokens->next->value);
	// printf("command->tokens->next->length: %d\n", command->tokens->next->length);
	// printf("command->tokens->next->next->type: %d\n", command->tokens->next->next->type);
	// printf("command->tokens->next->next->value: %s\n", command->tokens->next->next->value);
	// printf("command->tokens->next->next->length: %d\n", command->tokens->next->next->length);
	return (printf("parsing ok\n"), true);
}

bool	ft_check_first(t_command *command)
{
	// printf ("--------1------\ncommand->tokens->type: %d\ncommand->tokens->value: %s\n------------\n", command->tokens->type, command->tokens->value);
	// if (command->tokens->type != TOKEN_LT
	// 	&& command->tokens->type != TOKEN_GT
	// 	&& command->tokens->type != TOKEN_GT_GT
	// 	&& command->tokens->type != TOKEN_LT_LT
	// 	&& command->tokens->type != TOKEN_CMD
	// 	&& command->tokens->type != TOKEN_IN_FD)
	// 	return (printf("error4: %d\n", command->tokens->type), false);

	// if (command->tokens->type == TOKEN_CMD
	// 	&& command->tokens->next->type != TOKEN_LT
	// 	&& command->tokens->next->type != TOKEN_GT
	// 	&& command->tokens->next->type != TOKEN_GT_GT
	// 	&& command->tokens->next->type != TOKEN_LT_LT)
	// 	return (printf("error5: %d\n", command->tokens->type), false);

	return (true);
}

// - look if we are in single or double quote
// - if we are in single quote, we don't care about anything
// - if we are in double quote, we don't care about anything except $

// - if < or <<, we are looking for a infile in next token
// - if << we are looking for a here_doc in next token and we append it to infile

// - if > or >>, we are looking for a outfile in next token
// - if >> we are looking for a outfile in next token and we append it to outfile

// always check when literal symbol if command exept when we are in single quote or double quote or after <, <<, >, >>



// - if parsing ok we create a tree