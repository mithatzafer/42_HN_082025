/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize_marcus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehmed <mmehmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:12:42 by mmehmed           #+#    #+#             */
/*   Updated: 2025/08/20 13:10:09 by mmehmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	upr(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	lwr(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (upr(str[i]))
			str[i] = str[i] + 32;
		i++;
	}
	if (lwr(str[0]))
		str[0] = str[0] - 32;
	i = 1;
	while (str[i] != '\0')
	{
		if (!(lwr(str[i - 1]) || upr(str[i - 1]) || num(str[i - 1])))
		{
			if (lwr(str[i]))
				str[i] = str[i] - 32;
		}
		i++;
	}
	i++;
	return (str);
}

// int	main(void)
// {
// 	char	s[] = "hi, hOW are YOU? 42words forty-two; fifty+and+one";
// 	printf("%s", ft_strcapitalize(s));
// 	return (0);
// }
