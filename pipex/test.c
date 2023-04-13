#include "parsing.h"
#include "struct.h"
#include "strs.h"








int parse_cmds(int argc, char **argv, t_pipex *pipex)
{
	int i;
	int j;
	char **cmds;

	j = 2;
	if (pipex->here_doc == true)
		j++;
	if (ft_check_spaces(argv) > 0)
		i = ft_check_spaces(argv);
	else 
		i = 0;
	pipex->cmds = (char **)malloc((argc - j)+ i * sizeof(char *));
	if (!pipex->cmds)
		return (1);	
	while (j < argc - 1)
	{
		if (ft_strchr(argv[j], ' '))
			cmds = ft_split(argv[j], ' ');
		if (!cmds)
			return (1);
		pipex->cmds[i] = cmds;
		printf("pipex->cmds[%d] = %s\n", i, pipex->cmds[i]);
		j++;
	}
	pipex->out_name = (char *)malloc(ft_strlen(argv[j]) * sizeof(char));
	if (!pipex->out_name)
		return (1);
	pipex->out_name = ft_strdup(argv[j]);
	return (0);
}


