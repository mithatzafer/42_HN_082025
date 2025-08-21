/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehmed <mmehmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:12:42 by mmehmed           #+#    #+#             */
/*   Updated: 2025/08/17 19:29:11 by mmehmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
// #include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// int	main(void)
// {
// 	char	src[] = "abc";
// 	char	dest[] = "xy";

// 	ft_strcpy(dest, src);
// 	printf ("%s", dest);
// 	return (0);
// }
