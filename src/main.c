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
	if (ft_strncmp(extension, ".cub", 4))
	{
		throw("Not a valid extension");
		return (0);
	}
	return(1);
}

// int	check(void)
// {
// 	char	**matrix;
// 	char *str = "Prueba  uno y    2  ";
	
// 	matrix = ft_split(str, ' ');
// 	while (*matrix)
// 	{
// 		printf("%s\n", *matrix);
// 		matrix++;
// 	}
// 	exit(2);
// }

int	main(int argc, char **argv)
{
	t_info	*info;

	if (!check_arguments(argc, argv))
		return (1);
	info = extract_file_info(argv[1]);
	if (!info)
		return (1);
	return (0);
}
