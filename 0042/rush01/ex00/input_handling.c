/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehmed <mmehmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:31:02 by mmehmed           #+#    #+#             */
/*   Updated: 2025/08/10 18:06:17 by mmehmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putstr(char *str);
char	ft_check_input_for_error(int argc, char **argv);
char	ft_check_input_for_error1(int argc, char **argv);
char	ft_check_input_for_error2(int argc, char **argv);
int		ft_get_grid_size(char *input);
int		ft_strlen(char *str);

char	ft_check_input_for_error(int argc, char **argv)
{
	int	i;
	int	strlen;

	if (argc != 2)
	{
		ft_putstr("Error: The number of arguments must be 1.");
		return (-1);
	}
}

char	ft_check_input_for_error1(int argc, char **argv)
{
	int	i;
	int	strlen;

	i = 0;
	strlen = ft_strlen(argv[1]);
	printf("str: %s, strlen: %i\n", argv[1], strlen);
	while (i < strlen - 1)
	{
		if (!(('0' <= argv[1][i] && argv[1][i] <= '9') || argv[1][i] == ' '))
		{
			ft_putstr("Error: The input must fit the format");
			return (-1);
		}
		if (argv[1][i] == ' ' && argv[1][i - 1] == ' ')
		{
			ft_putstr("Error: Only one space between each number.");
			return (-1);
		}
		// if (argv[1][i] > ft_get_grid_size(argv[1]))
		// {
		// 	ft_putstr("Error: Smaller number expexted.");
		// 	return (-1);
		// }
		// // Check for consecutive numbers
		// // Missing check for number 1 <= and <= grid_size.
		// if (argv[1][i] != ' ' && argv[1][i - 1] != ' ')
		// {
		// 	ft_putstr("Error: Multiple numbers next to each other.");
		// 	return (-1);
		// 	i++;
		// }
		return (0);
	}
}

char	ft_check_input_for_error2(int argc, char **argv)
{
	int	i;
	int	strlen;

	i = 0;
	strlen = ft_strlen(argv[1]);
	printf("str: %s, strlen: %i\n", argv[1], strlen);
	while (i < strlen - 1)
	{
		if (argv[1][i] > ft_get_grid_size(argv[1]))
		{
			ft_putstr("Error: Smaller number expexted.");
			return (-1);
		}
		if (argv[1][i] != ' ' && argv[1][i - 1] != ' ')
		{
			ft_putstr("Error: Multiple numbers next to each other.");
			return (-1);
			i++;
		}
		return (0);
	}
}

int	ft_get_grid_size(char *input)
{
	int	input_parameters;
	int	i;

	input_parameters = (ft_strlen(input)) / 2;
	i = 0;
	while (i < 9)
	{
		i++;
		if (input_parameters == (i * 4))
		{
			return (i);
		}
	}
	ft_putstr("Error: Invalid grid size. There must n^2");
	return (-1);
}

// int	main(int argc, char **argv) // Might be a VLA
// {
// 	int	grid_size;

// 	if (ft_check_input_for_error(argc, argv) == -1)
// 		return (-1);
// 	grid_size = ft_get_grid_size();
// 	return (0);
// }
