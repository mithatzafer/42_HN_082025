/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehmed <mmehmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:12:42 by mmehmed           #+#    #+#             */
/*   Updated: 2025/08/18 19:12:02 by mmehmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 'a' || str[i] > 'z'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// int	main(void)
// {
// 	char	a[] = "asdf";

// 	printf("%d", ft_str_is_lowercase(a));
// 	return (0);
// }
