/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variation_generation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburgsta <aburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:32:40 by aburgsta          #+#    #+#             */
/*   Updated: 2025/08/10 19:18:35 by aburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // ILLEGAL
#include <unistd.h>
#include <stdlib.h>
#define GRIDSIZE 4

void	ft_generate_row_permutations(int grid_size, char **permutation_dict_pt);
char	**ft_initialise_row_dict(int grid_size);
int	ft_get_grid_size(char *input);
void	ft_setup_input_array(char *input_string, char **input_array);
void	ft_putstr(char *str);
int	ft_strlen(char *str);
void	ft_get_left_and_right(int grid_size, char *row, char **return_array_pt);

// void	iterate_row(* row, * permutations)
// void	check_row(* row)
// void check_collums(* matrix)
// void	print_matrix(* matrix)

	// loop
		// interate_row  eg 0 0 0 0 -> 0 0 0 1, 0 0 0 permutation_count -> 0 0 1 0
		// if not fit input continue iteration
		// else check if colums fit input
			// if yes printf matrix
			// else continue iteration
	// if no match found return error
		
	
	//ft_putstr(permutations[9]);
	// write(1, &permutations[1].left, 1);
	
void	ft_iterate_row(int grid_size, int row_index, int *array_of_rows, char *input_array, char **permutation_dict_pt);
char	ft_check_row(int grid_size, char *row, char *left_and_right_view);


void	ft_iterate_row(int grid_size, int row_index, int *array_of_rows, char *input_array, char **permutation_dict_pt)
{
	char *row;
	char *left_right_array;
	
	printf("ITERATION: %i %i %i %i\n", array_of_rows[0], array_of_rows[1], array_of_rows[2], array_of_rows[3]);
	
	printf("Check1\n");
	array_of_rows[3] = array_of_rows[3] + 1;
	printf("Check2\n");
	if (array_of_rows[row_index] == grid_size)
	{
		array_of_rows[row_index] = 0;
		if (row_index > 0)
		{
			ft_iterate_row(grid_size, row_index - 1, array_of_rows, input_array, permutation_dict_pt);
		}
		else
		{
			printf("End Reached");
			// ERROR no solution found
			return;
		}
	}
	printf("Check3\n");
	
	left_right_array = malloc(2);
	row = *(permutation_dict_pt);
	ft_get_left_and_right(grid_size, row, &left_right_array); //this is the wrong function it should fetch from input
	if (ft_check_row(grid_size, row, left_right_array) == 0)
	{
		ft_iterate_row(grid_size, row_index, array_of_rows, input_array, permutation_dict_pt);
	}
	else 
	{
		// if ft_check_collums
		ft_iterate_row(grid_size, row_index, array_of_rows, input_array, permutation_dict_pt);
	}
	
}

void	ft_get_left_and_right(int grid_size, char *row, char **return_array_pt)
{
	int counter;
	int highest_value;
	int i;

	counter = 0;
	highest_value = 0;
	i = 0;
	while (i < grid_size)
	{
		if (row[i] > highest_value)
		{
			counter++;
			highest_value = row[i];
		}
		i++;
	}
	**return_array_pt = counter;

	counter = 0;
	highest_value = 0;
	i = 0;
	while (i < grid_size)
	{
		if (row[grid_size - 1 - i] > highest_value)
		{
			counter++;
			highest_value = row[i];
		}
		i++;
	}
	*(*(return_array_pt) + 1) = counter;
}

char	ft_check_row(int grid_size, char *row, char *left_and_right_view)
{
	char *left_right_array;
	ft_get_left_and_right(grid_size, row, &left_right_array);
	if (left_right_array[0] == left_and_right_view[0] && left_right_array[0] == left_and_right_view[0])
	{
		return (1);
	}
	else
	{
		return (0);
	}
}


char ft_check_variations(int grid_size, char *input)
{
	char **permutation_dict;
	int *array_of_rows;
	char *input_array;
	int i;
	
	permutation_dict = ft_initialise_row_dict(grid_size);
	ft_generate_row_permutations(grid_size, permutation_dict);
	array_of_rows = malloc(grid_size);
	input_array = malloc(grid_size);
	
	i = 0;
	while (i < grid_size)
	{
		array_of_rows[2 + i] = 0;
		input_array[i] = 0;
		i++;
	}
	
	ft_setup_input_array(input, &input_array);
	
	// i = 0;
	// while (i < 16)
	// {
	// 	printf("Input at %i is %i\n", i, input_array[i]);
	// 	i++;
	// }
	
	i = 0;
	while (i < 24)
	{
		printf("%i %i %i %i\n", permutation_dict[0][i], permutation_dict[1][i], permutation_dict[2][i], permutation_dict[3][i]);
		i++;
	}
	
	// while (1 == 1)
	// {
	// 	ft_iterate_row(char *row_pt, char *input);
	// }
	
	ft_iterate_row(grid_size, grid_size - 1, array_of_rows, input_array, permutation_dict);

	return (grid_size - input[0]); // useless
}

void	ft_setup_input_array(char *input_string, char **input_array)
{
	int i;

	i = 0;
	while (i < ft_get_grid_size(input_string) * 4)
	{
		*(*(input_array) + i) = ((int) input_string[i * 2]) - 48;
		i++;
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

int	main(int argc, char **argv)
{
	ft_check_variations(4, argv[1]);
	return (argc);
}