/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehmed <mmehmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:28:31 by freinhar          #+#    #+#             */
/*   Updated: 2025/08/05 14:21:58 by mmehmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(void)
{
	rush(15, 5);
	return (0);
}

void	rush(int x, int y)
{
	int	row_counter;

	row_counter = 0;
	if (x > 0 && y > 0)
	{
		while (row_counter < y)
		{
			if (row_counter == 0)
			{
				first_row(x);
			}
			if (row_counter > 0 && row_counter < y -1)
			{
				rows_between(x);
			}
			if (row_counter == y -1 && y > 1)
			{
				last_row(x);
			}
			row_counter++;
		}
	}
}

void	first_row(int x)
{
	int	col_counter;

	col_counter = 0;
	while (col_counter < x)
	{
		if (col_counter == 0)
		{
			ft_putchar('/');
		}
		else if (col_counter == x - 1)
		{
			ft_putchar('\\');
		}
		else
		{
			ft_putchar('*');
		}
		col_counter++;
	}
	ft_putchar('\n');
}

void	rows_between(int x)
{
	int	col_counter;

	col_counter = 0;
	while (col_counter < x)
	{
		if (col_counter == 0 || col_counter == x - 1)
		{
			ft_putchar('*');
		}
		else
		{
			ft_putchar(' ');
		}
		col_counter++;
	}
	ft_putchar('\n');
}

void	last_row(int x)
{
	int	col_counter;

	col_counter = 0;
	while (col_counter < x)
	{
		if (col_counter == 0)
		{
			ft_putchar('\\');
		}
		else if (col_counter == x - 1)
		{
			ft_putchar('/');
		}
		else
		{
			ft_putchar('*');
		}
		col_counter++;
	}
	ft_putchar('\n');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
