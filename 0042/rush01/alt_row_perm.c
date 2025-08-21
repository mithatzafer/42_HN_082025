/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_row_perm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburgsta <aburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:42:13 by aburgsta          #+#    #+#             */
/*   Updated: 2025/08/10 18:15:06 by aburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_initialise_row_dict(int grid_size);
int		ft_factorial(int n);
void	ft_generate_row_permutations(int grid_size, char **permutation_dict_pt);
void	ft_swap_char(char *a, char *b);
void	ft_reverse_sequence(int from, int to, char *row_pt);

char	**ft_initialise_row_dict(int grid_size)
{
	char	**permutation_dict_pt;
	int		j;
	int		i;

	permutation_dict_pt = malloc(ft_factorial(grid_size));
	i = 0;
	while (i < ft_factorial(grid_size))
	{
		permutation_dict_pt[i] = malloc(grid_size + 2);
		j = 0;
		while (j < grid_size)
		{
			permutation_dict_pt[i][2 + j] = j + 1;
			j++;
		}
		
		i++;
	}
	return (permutation_dict_pt);
}

void	ft_generate_row_permutations(int grid_size, char **permutation_dict_pt)
{
	int		total_permutations;
	char	row_to_work_on[grid_size]; // VLA
	int		i;
	int		j;
	int 	k;
	int 	l;

	total_permutations = ft_factorial(grid_size);
	i = 0;
	while (i < grid_size)
	{
		row_to_work_on[i] = i + 1;
		permutation_dict_pt[2 + i][0] = row_to_work_on[i];
		i++;
	}
	permutation_dict_pt[0][0] = 4;
	permutation_dict_pt[1][0] = 1;
	i = 0;
	while (i < total_permutations - 1)
	{
		i++;
		k = grid_size - 2;
		while (k >= 0)
		{
			if (row_to_work_on[k] < row_to_work_on[k + 1])
			{
				break;
			}
			k--;
		}
		if (k < 0)
			k = grid_size - 1;
		
		l = grid_size - 1;
		while (l >= 0)
		{
			if (row_to_work_on[k] < row_to_work_on[l])
			{
				break;
			}
			l--;
		}
		ft_swap_char(&row_to_work_on[k], &row_to_work_on[l]);
		ft_reverse_sequence(k + 1, grid_size - 1, row_to_work_on);
		j = 0;
		while (j < grid_size)
		{
			permutation_dict_pt[2 + j][i] = row_to_work_on[j];
			j++;
		}
		
	}
}

int	ft_factorial(int n)
{
	int value;
	
	value = 1;
	while (n > 0)
	{
		value *= n;
		n--;
	}
	return (value);
}

void	ft_swap_char(char *a, char *b)
{
	char	new_a;
	char	new_b;
	if (a == b)
		return;
	new_a = *b;
	new_b = *a;
	*a = new_a;
	*b = new_b;
}

void	ft_reverse_sequence(int from, int to, char *row_pt)
{
	int i;

	i = 0;
	while (i < ((to - from + 1) / 2))
	{
		ft_swap_char(&row_pt[from + i], &row_pt[to - i]); // Of by one
		i++;
	}
}
