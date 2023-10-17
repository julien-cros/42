/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:20:28 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/14 19:00:02 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "str2.h"
#include "split.h"


/**
 * @brief The ft_env_len function takes in a pointer to a linked list of
 * environment variables and returns the length of the string containing all
 * the environment variables.
 * 
 * @param lst 
 * @return size_t 
 */
size_t	ft_env_len(t_env *lst)
{
	size_t	lst_len;

	lst_len = 0;
	while (lst && lst->next != NULL)
	{
		if (lst->value != NULL)
		{
			lst_len += ft_strlen(lst->value);
			lst_len++;
		}
		lst = lst->next;
	}
	return (lst_len);
}

/**
 * @brief The ft_env_to_str function takes in a pointer to a linked list of
 * environment variables and returns a string containing all the environment
 * variables.
 * 
 * @param lst 
 * @return char* 
 */
char	*ft_env_to_str(t_env *lst)
{
	char	*env;
	int		i;
	int		j;

	if (!(env = malloc(sizeof(char) * ft_env_len(lst) + 1)))
		return (NULL);
	i = 0;
	while (lst && lst->next != NULL)
	{
		if (lst->value != NULL)
		{
			j = 0;
			while (lst->value[j])
			{
				env[i] = lst->value[j];
				i++;
				j++;
			}
		}
		if (lst->next->next != NULL)
			env[i++] = '\n';
		lst = lst->next;
	}
	env[i] = '\0';
	return (env);
}

/**
 * @brief The ft_init_env function takes in a pointer to a data struct and a
 * pointer to an array of strings. It Creates and initializes a linked list of
 * environment variables and assigns it to the envp member of the data struct.
 * 
 * @param data 
 * @param envp_array 
 * @return int 
 */
int	ft_init_env(t_data *data, char **envp_array)
{
	t_env	*envp;
	t_env	*new;
	int		i;

	if (!(envp = malloc(sizeof(t_env))))
		return (1);
	envp->value = ft_strdup(envp_array[0]);
	envp->next = NULL;
	data->envp = envp;
	i = 1;
	while (envp_array && envp_array[0] && envp_array[i])
	{
		if (!(new = malloc(sizeof(t_env))))
			return (1);
		new->value = ft_strdup(envp_array[i]);
		new->next = NULL;
		envp->next = new;
		envp = new;
		i++;
	}
	return (0);
}

/**
 * @brief The ft_init_secret_env function takes in a pointer to a data struct
 * and a pointer to an array of strings. It creates a linked list of environment
 * variables and assigns it to the secret_env member of the data struct.
 * 
 * @param data 
 * @param envp 
 * @return int 
 */
int	ft_init_secret_env(t_data *data, char **envp)
{
	t_env	*env;
	t_env	*new;
	int		i;

	if (!(env = malloc(sizeof(t_env))))
		return (1);
	env->value = ft_strdup(envp[0]);
	env->next = NULL;
	data->secret_env = env;
	i = 1;
	while (envp && envp[0] && envp[i])
	{
		if (!(new = malloc(sizeof(t_env))))
			return (1);
		new->value = ft_strdup(envp[i]);
		new->next = NULL;
		env->next = new;
		env = new;
		i++;
	}
	return (0);
}


/**
 * @brief The ft_get_env_value function takes in a pointer to a string and
 * returns the value of the environment variable.
 * 
 * @param name 
 * @param env 
 * @return char* 
 */
char	*ft_get_env_value(char *name, t_env *env)
{
	char	env_name[BUFFER_SIZE]; // changed to BUFFER_SIZE

	while (env && env->next)
	{
		ft_get_env_name(env_name, env->value);
		if (ft_strncmp(name, env_name, ft_strlen(name)) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}


/**
 * @brief The ft_get_env_name function takes in a pointer to a string and
 * returns the name of the environment variable.
 * 
 * @param env_name 
 * @param env 
 * @return ** char* 
 */
char *ft_get_env_name(char *env_name, char *env)
{
	int i;

	i = 0;
	while (env[i] && env[i] != '=')
	{
		env_name[i] = env[i];
		i++;
	}
	env_name[i] = '\0';
	return (env_name);
}

/**
 * @brief The ft_get_paths function returns an array of strings containing the
 * paths in the PATH environment variable. If the variable does not exist, NULL
 * is returned.
 * 
 * @param envp 
 * @return char** 
 */
char	**ft_get_paths(t_env *envp)
{
	char	*path;
	t_env	*tmp;
	
	tmp = envp;
	while (tmp && tmp->next)
	{
		if (ft_strncmp(tmp->value, "PATH", 4) == 0)
		{
			path = ft_substr(tmp->value, 5, ft_strlen(tmp->value));
			return (ft_split(path, ':'));
		}
		tmp = tmp->next;
	}
	if (!path)
		return (NULL);
	return (ft_split(path, ':'));
}
