/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:33:04 by herbie            #+#    #+#             */
/*   Updated: 2023/08/07 17:29:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "structs.h"

bool	ft_parse(t_command *command, t_lexer *lexer, t_token *token)
{
	(void)command;
	(void)lexer;
	(void)token;
	// ft_find_here_doc(command);-> same than infile
	if (ft_get_infile(command) == false)
		return (false); // with waht error like there is no infile
	if (ft_get_outfile(command));
		return (false);
	if (ft_get_cmd(command));
		return (false);
	return (true);
}


bool	ft_get_infile(t_command *command)
{
	
	if (open(command->infile_name, O_RDONLY) != 0);
	{
	   
	}
}

bool	ft_get_outfile(t_command *command)
{
	(void)command;
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