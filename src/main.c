#include <cube.h>

void	throw(char *message)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
}

int	check_arguments(int num, char **args)
{
	char	*extension;

	if (num != 2)
	{
		throw("Wrong number of arguments");
		return (0);
	}
	extension = ft_strrchr(args[1], '.');
	if (!extension)
	{
		throw("The file doesn't have extension");
		return (0);
	}
	if (!ft_strncmp(extension, ".cub", 4))
	{
		throw("Not a valid extension");
		return (0);
	}
	return(1);
}

int	main(int argc, char **argv)
{
	if (!check_arguments(argc, argv))
		return (1);
	printf("GG\n");
	return (0);
}
