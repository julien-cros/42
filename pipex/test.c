#include "parsing.h"

char *ft_path_cmds(char *cmd, char **envp)
{
	int i;
	int j;
	char **paths;
	char *path;

	i = 0;
	j = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	paths = ft_split(envp[i], ':');
	if (!paths)
		return (1);
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path, cmd);
		if (!path)
			return (1);
		if (access(path, F_OK))
		{
			free(path); 
			ft_free_2(paths); 
			return (path);
		}
		else
			free(path);
		i++;
	}
	return (1);
}