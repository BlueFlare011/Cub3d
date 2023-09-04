#include <cube.h>

int	check_arguments(int num, char **args)
{
	char	*extension;

	if (num != 2)
		return (error_int(ERROR_NUM_ARGS, 0));
	extension = ft_strrchr(args[1], '.');
	if (!extension)
		return (error_int(NO_EXTENSION, 0));
	if (ft_strncmp(extension, ".cub", 4))
		return (error_int(NO_VALID_EXTENSION, 0));
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
	{
		delete_struct(info);
		return (1);
	}
	print_info(info);
	delete_struct(info);
	return (0);
}
