/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:02:06 by herbie            #+#    #+#             */
/*   Updated: 2023/10/18 09:33:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>
#include <stdbool.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define SKIP 1
# define NOSKIP 0

// # define BUFF_SIZE 4096 // already in io.h with 10000
# define EXPANSION -36
# define ERROR 1
# define SUCCESS 0
# define IS_DIRECTORY 126
# define UNKNOWN_COMMAND 127

typedef enum e_token_types
{
	TOKEN_EOF,
	TOKEN_INVALID,
	TOKEN_SYMBOL,
	TOKEN_GT,
	TOKEN_LT,
	TOKEN_GT_GT,
	TOKEN_LT_LT,
	TOKEN_PIPE,
	TOKEN_SQ,
	TOKEN_DQ,
	TOKEN_IN_FILE,
	TOKEN_OUT_FILE,
	TOKEN_CMD,
	// TOKEN_END,
} t_token_types;

typedef enum e_lexer_states
{
	LEXER_STATE_DEFAULT,
	LEXER_STATE_IN_SQ,
	LEXER_STATE_IN_DQ,
} t_lexer_states;

typedef struct	s_token
{
	t_token_types type;
	const char *value;
	int length;
	struct s_token *prev;
	struct s_token *next;
}				t_token;

typedef struct s_lexer
{
	const char *raw;
	t_lexer_states state;
	int length;
	int cursor;
} t_lexer;

typedef struct s_bash_token_map
{
	char *value;
	t_token_types type;
} t_bash_token_map;

typedef struct	s_env
{
	char			*value;
	struct s_env	*next;
}				t_env;

typedef struct	s_data
{
	t_env			*envp;
	t_env			*secret_env;
	t_token			*tokens;
	int				token_length;
	int				in;
	int				out;
	int				in_fd;
	int				out_fd;
	int				pipe_in;
	int				pipe_out;
	int				pid;
	bool			is_here_doc;
	bool			is_executable;
	bool			is_parent;
	bool			is_builtin;
	int				charge;
	int				last;
	int				return_status;
	int				exit;
}				t_data;

typedef struct	s_signal
{
	int				sigint;
	int				sigquit;
	int				exit_status;
	pid_t			pid;
}				t_signal;

extern t_signal g_signal;

typedef struct	s_expansions
{
	char			*new_arg;
	int				i;
	int				j;
}				t_expensions;

#endif /* STRUCTS_H */