/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehmed <mmehmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:12:42 by mmehmed           #+#    #+#             */
/*   Updated: 2025/08/18 17:53:16 by mmehmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
// #include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// int	main(void)
// {
// 	char	a[] = "hello";

// 	printf("%d", ft_str_is_alpha(a));
// 	return (0);
// }
