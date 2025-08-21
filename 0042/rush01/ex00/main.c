/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoz <ayoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:30:36 by aburgsta          #+#    #+#             */
/*   Updated: 2025/08/10 16:07:18 by ayoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	ft_check_input_for_error(int argc, char **argv);
int	ft_get_grid_size(char *input);

int	main(int argc, char **argv) // Might be a VLA
{
	int grid_size;
	
	if (ft_check_input_for_error(argc, argv) == -1)
		return (-1);
	grid_size = ft_get_grid_size();
	return (0);
}
