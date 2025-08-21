/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehmed <mmehmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:12:42 by mmehmed           #+#    #+#             */
/*   Updated: 2025/08/19 21:12:41 by mmehmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	str[0] = str[0] - 32;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i - 1] > 31 && str[i - 1] < 48)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
			i++;
		}
		i++;
	}
	return (str);
}

// int	main(void)
// {
// 	// char	a[] = "hi, hOW are YOU? 42words forty-two; fifty+and+one";
// 	char	a[] = "";
// 	printf("%s", ft_strcapitalize(a));
// 	return (0);
// }
