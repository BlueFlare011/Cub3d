#include <cube.h>

int	check_arguments(int num, char **args)
{
	char	*extension;

	if (num != 2)
	{
		printf("Wrong number of arguments\n");
		return (0);
	}
	extension = ft_strrchr(args[1], '.');
	if (!extension)
	{
		printf("The file %s doesn't have extension\n", args[1]);
		return (0);
	}
	if (ft_strncmp(extension, ".cub", 4))
	{
		printf("%s is not a valid extension\n", extension);
		return (0);
	}
	return(1);
}

// int	check(void)
// {
	// char	**matrix;
	// char *str = "Prueba  uno y    2  ";
	// 
	// matrix = ft_split(str, ',');
	// printf("%s\n", *matrix);
	// pito(matrix);
	// return(0);
// }

int	main(int argc, char **argv)
{
	t_info	*info;

	if (!check_arguments(argc, argv))
		return (1);
	info = extract_file_info(argv[1]);
	if (!info)
		return (1);
	print_info(info);
	delete_struct(info);
	return (0);
}
