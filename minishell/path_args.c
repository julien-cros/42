/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:30:14 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/17 14:51:18 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_args.h"
#include "str2.h"
#include "str.h"
#include "display.h"
#include "find_cmd.h"
#include "args.h"
#include "execution.h"
#include "free.h"
#include "mem.h"
#include "token.h"
#include "split.h"
#include "env.h"

// int			error_message(char *path)
// {
// 	DIR	*folder;
// 	int	fd;
// 	int	ret;

// 	fd = open(path, O_WRONLY);
// 	folder = opendir(path);
// 	ft_putstr_fd("minishell: ", STDERR);
// 	ft_putstr_fd(path, STDERR);
// 	if (ft_strchr(path, '/') == NULL)
// 		ft_putstr_fd(": command not found", STDERR);
// 	else if (fd == -1 && folder == NULL)
// 		ft_putstr_fd(": No such file or directory", STDERR);
// 	else if (fd == -1 && folder != NULL)
// 		ft_putstr_fd(": is a directory", STDERR);
// 	else if (fd != -1 && folder == NULL)
// 		ft_putstr_fd(": Permission denied", STDERR);
// 	if (ft_strchr(path, '/') == NULL || (fd == -1 && folder == NULL))
// 		ret = UNKNOWN_COMMAND;
// 	else
// 		ret = IS_DIRECTORY;
// 	if (folder)
// 		closedir(folder);
// 	if (fd != -1)
// 		close(fd);
// 	return (ret);
// }


// int			ft_exc(char *path, char **args, t_env *env, t_data *data)
// {
// 	char	**env_array;
// 	char	*ptr;
// 	int		ret;

// 	ret = SUCCESS;
// 	g_signal.pid = fork();
// 	if (g_signal.pid == 0)
// 	{
// 		ptr = ft_env_to_str(env);
// 		env_array = ft_split(ptr, '\n');
// 		ft_memdel(ptr);
// 		if (ft_strchr(path, '/') != NULL)
// 			execve(path, args, env_array);
// 		ret = error_message(path);
// 		ft_free_tab(env_array);
// 		ft_clear_tokens(&data->tokens);
// 		exit(ret);
// 	}
// 	else
// 		waitpid(g_signal.pid, &ret, 0);
// 	if (g_signal.sigint == 1 || g_signal.sigquit == 1)
// 		return (g_signal.exit_status);
// 	ret = (ret == 32256 || ret == 32512) ? ret / 256 : !!ret;
// 	return (ret);
// }

// char		*path_join(const char *s1, const char *s2)
// {
// 	char	*tmp;
// 	char	*path;

// 	tmp = ft_strjoin(s1, "/");
// 	path = ft_strjoin(tmp, s2);
// 	ft_memdel(tmp);
// 	return (path);
// }

char		*check_dir(char *bin, char *command)
{
	DIR				*folder;
	struct dirent	*item;
	char			*path;

	path = NULL;
	// printf("bin = %s\n", bin);
	// printf("command = %s\n", command);
	folder = opendir(bin);
	if (!folder)
		return (NULL);
	while ((item = readdir(folder)))
	{
		if (ft_strncmp(item->d_name, command, ft_strlen(command)) == 0)
			path = path_join(bin, item->d_name);
	}
	closedir(folder);
	return (path);
}

int			ft_exec_bin(char **args, t_env *env, t_data *data, t_token *token)
{
	int		i;
	char	**bin;
	char	*path;
	int		ret;

	i = 0;
	ret = UNKNOWN_COMMAND;
	while (env && env->value && ft_strncmp(env->value, "PATH=", 5) != 0)
		env = env->next;
	if (env == NULL || env->next == NULL)
		return (ft_exc(args[0], args, env, data));
	bin = ft_split(env->value, ':');
	if (!args[0] && !bin[0])
		return (ERROR);
	i = 1;
	path = check_dir(bin[0] + 5, args[0]);
	while (args[0] && bin[i] && path == NULL)
	{
		// printf("bin[%d] = %s\n", i, bin[i]);
		path = check_dir(bin[i++], args[0]);
	}
	if (path != NULL)
	{
		// printf("path = %s\n", path);
		ret = ft_exc(path, args, env, data);
	}
	else
	{
		// printf("else\n");
		ret = ft_exc(args[0], args, env, data);
	}
	ft_free_tab(bin);
	ft_memdel(path);
	return (ret);
}

// bool ft_get_path_and_args(t_data *data, t_token *token)
// {
// 	char	*path;
// 	char	**args;

// 	if (data->charge == 0)
// 		return (false);
// 	path = ft_set_path(data, token);
// 	args = ft_set_args(token);
// 	// expension
// 	ft_execution(path, args, data);
// 	// ft_exec_bin(args, data->envp, data);
// 	// if (path)
// 	// 	printf ("path: %s\n", path);
// 	// if (args)
// 	// {
// 	// 	while (*args)
// 	// 	{
// 	// 		printf ("args: %s\n", *args);
// 	// 		args++;
// 	// 	}
// 	// }
// 	// ft_free_array(args, ft_args_count(token));// probleme ici
// 	if (data->pipe_in > 0)
// 		close(data->pipe_in);
// 	if (data->pipe_out > 0)
// 		close(data->pipe_out);
// 	data->pipe_in = -1;
// 	data->pipe_out = -1;
// 	data->charge = 0;
// 	return (true);
// }

void	ft_exec_cmd(t_data *data, t_token *token)
{
	char	**cmd;
	int		i;

	// printf("\n\n--- in exec_cmd ---\n\n");
	// printf("data->fdin = %d\n", data->in_fd);
	// printf("data->fdout = %d\n", data->out_fd);
	// printf("data->pipin = %d\n", data->pipe_in);
	// printf("data->pipout = %d\n", data->pipe_out);
	if (data->charge == 0)
		return ;
	cmd = ft_set_args(token);
	i = 0;
	while (cmd && cmd[i])
	{
		// printf("cmd[%d] = %s\n", i, cmd[i]);
		i++;
	}
	i = 0;
	// while (cmd && cmd[i])
	// {
	// 	cmd[i] = expansions(cmd[i], data->envp, data->return_status);
	// 	i++;
	// }
	// if (cmd && ft_strcnmp(cmd[0], "exit") == 0 && has_pipe(token) == 0)
	// 	data_exit(data, cmd);
	// else if (cmd && is_builtin(cmd[0]))
	// 	data->return_status = exec_builtin(cmd, data);
	if (cmd)
	{
		// i = 0;
		// while (cmd[i])
		// {
		// 	printf("cmd[%d] = %s\n", i, cmd[i]);
		// 	i++;
		// }
		// printf("env = %s\n", data->envp->value);
		
		data->return_status = ft_exec_bin(cmd, data->envp, data, token);
	}
	// ft_free_tab(cmd);
	if (data->pipe_in > 0)
		close(data->pipe_in);
	if (data->pipe_out > 0)
		close(data->pipe_out);
	data->pipe_in = -1;
	data->pipe_out = -1;
	// data->in_fd = -1;
	// data->out_fd = -1;
	data->charge = 0;
}
